/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2017,��ɿƼ�
 * All rights reserved.
 * ��������QQȺ��179029047
 *
 * �����������ݰ�Ȩ������ɿƼ����У�δ��������������ҵ��;��
 * ��ӭ��λʹ�ò������������޸�����ʱ���뱣����ɿƼ��İ�Ȩ������
 *
 * @file       		KEA128_flash
 * @company	   		�ɶ���ɿƼ����޹�˾
 * @author     		��ɿƼ�(QQ3184284598)
 * @version    		v2.0
 * @Software 		IAR 7.7 or MDK 5.23
 * @Target core		S9KEA128AMLK
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2017-11-6
 ********************************************************************************************************************/



#ifndef _KEA128_flash_h
#define _KEA128_flash_h

#include "misc.h"
#include "common.h"
#include "SKEAZ1284.h"
#include "KEA128_port_cfg.h"

#define FTF    				    FTMRE

#define SECTOR_SIZE     		(512)
#define FLASH_SECTOR_NUM        (256)                   //������
#define FLASH_ALIGN_ADDR        4                       //��ַ����������
typedef uint32_t                  FLASH_WRITE_TYPE;       //flash_write ����д�� ����������




//-------------------------------------------------------------------------------------------------------------------
//  @brief      ʹ�ú궨���flash�������ݶ�ȡ
//  @param      SectorNum 		��Ҫд����������
//  @param      offset	 		��ַƫ��
//  @param      type		 	��ȡ����������
//  @return     				���ظ�����ַ������
//  @since      v1.0
//  Sample usage:               flash_read(20,0,uint32_t);//��ȡ20������ƫ��0��������Ϊuint32_t
//-------------------------------------------------------------------------------------------------------------------
#define     flash_read(SectorNum,offset,type)        (*(type *)((uint32_t)(((SectorNum)*SECTOR_SIZE) + (offset))))


void FLASH_Init(void);
uint32_t FLASH_GetSectorSize(void);
uint8_t FLASH_EraseSector(uint32_t SectorNum);
uint8_t FLASH_WriteSector(uint32_t SectorNum, const uint8_t *buf, uint32_t len, uint32_t offset);



#endif
