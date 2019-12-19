/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2017,��ɿƼ�
 * All rights reserved.
 * ��������QQȺ��179029047
 *
 * �����������ݰ�Ȩ������ɿƼ����У�δ��������������ҵ��;��
 * ��ӭ��λʹ�ò������������޸�����ʱ���뱣����ɿƼ��İ�Ȩ������
 *
 * @file       		KEA128_irq
 * @company	   		�ɶ���ɿƼ����޹�˾
 * @author     		��ɿƼ�(QQ3184284598)
 * @version    		v2.0
 * @Software 		IAR 7.7 or MDK 5.23
 * @Target core		S9KEA128AMLK
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2017-11-6
 ********************************************************************************************************************/



#include "KEA128_irq.h"


//-------------------------------------------------------------------------------------------------------------------
//  @brief      �ⲿ�ж�
//  @param      void            
//  @return     void
//  @since      v2.0
//  Sample usage:               irq_init();
//								NVIC_SetPriority(IRQ_IRQn,1);					//�������ȼ�,�����Լ����������� �����÷�ΧΪ 0 - 3
//								NVIC_EnableIRQ(IRQ_IRQn);							//��ZERO���жϿ���
//								EnableInterrupts;								//���ܵ��жϿ���  
//  @note                       ��KEA128_port_cfg�ļ��л����ţ�IRQxͬһʱ��ֻ�ܶ�һ�����Ž��м��
//                              �����жϺ��������ʹ��CLEAR_IRQ_FLAG�궨������жϱ�־λ
//-------------------------------------------------------------------------------------------------------------------

void irq_init(void)
{
    uint8_t ptn;
    uint32_t temp;

    if(A5 == IRQ_PIN)
    {
        temp = SIM->PINSEL;
        temp &= ~((uint32_t)SIM_PINSEL_IRQPS_MASK);
        SIM->PINSEL = temp | SIM_PINSEL_IRQPS(0);
    }
    else
    {
        ptn = PTn(IRQ_PIN);//��ȡ���ź�
        
        temp = SIM->PINSEL;
        temp &= ~((uint32_t)SIM_PINSEL_IRQPS_MASK);
        SIM->PINSEL = temp | SIM_PINSEL_IRQPS(ptn+1);
    }
    
    SIM->SCGC |= SIM_SCGC_IRQ_MASK;     //����IRQʱ��
    IRQ->SC = (0
            //| IRQ_SC_IRQPDD_MASK      //1�������������� 0��ʹ����������  ע�ʹ���0
            | IRQ_SC_IRQEDG_MASK        //1�������ػ��߸ߵ�ƽ���� 0���½��ػ��ߵ͵�ƽ����   ע�ʹ���0
            | IRQ_SC_IRQPE_MASK         //ʹ��IRQ
            //| IRQ_SC_IRQIE_MASK         //�����ж�
            //| IRQ_SC_IRQMOD_MASK      //1�����������ƽ����  0��ֻ�����ش���  ע�ʹ���0
            );
	systick_delay_ms(1);
	CLEAR_IRQ_FLAG;
    IRQ->SC |= IRQ_SC_IRQIE_MASK;         //�����ж�;
    
}





