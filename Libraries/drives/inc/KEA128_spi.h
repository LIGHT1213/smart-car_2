/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2017,��ɿƼ�
 * All rights reserved.
 * ��������QQȺ��179029047
 *
 * �����������ݰ�Ȩ������ɿƼ����У�δ��������������ҵ��;��
 * ��ӭ��λʹ�ò������������޸�����ʱ���뱣����ɿƼ��İ�Ȩ������
 *
 * @file       		KEA128_spi
 * @company	   		�ɶ���ɿƼ����޹�˾
 * @author     		��ɿƼ�(QQ3184284598)
 * @version    		v2.0
 * @Software 		IAR 7.7 or MDK 5.23
 * @Target core		S9KEA128AMLK
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2017-11-6
 ********************************************************************************************************************/


#ifndef _KEA128_spi_h
#define _KEA128_spi_h



#include "misc.h"
#include "common.h"
#include "SKEAZ1284.h"
#include "KEA128_port_cfg.h"


//���ӻ�ģʽ

typedef enum
{
    MASTER,    //����ģʽ
    SLAVE      //�ӻ�ģʽ
} SPI_CFG;


//ģ���
typedef enum
{
    spi0,
    spi1,
} SPIn_e;


//SPIģ��Ƭѡ��
typedef enum
{
    NOT_PCS,
    USE_PCS,
} SPI_PCSn_e;


uint32_t spi_init(SPIn_e spin , SPI_PCSn_e pcs, SPI_CFG master,uint32_t baud);
void spi_mosi(SPIn_e spin, SPI_PCSn_e pcs, uint8_t *modata, uint8_t *midata, uint32_t len);
void spi_mosi_cmd(SPIn_e spin, SPI_PCSn_e pcs, uint8_t *mocmd , uint8_t *micmd , uint8_t *modata , uint8_t *midata, uint32_t cmdlen , uint32_t len);

#endif 
