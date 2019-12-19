#include "direction.h"
#include "main.h"

double a[5] = {0, 0, 0, 0, 0};

void adc_Init()
{
    adc_init(ADC0_SE11);                                            //adc初始化
    adc_init(ADC0_SE12);
    adc_init(ADC0_SE13);
    adc_init(ADC0_SE14);
    adc_init(ADC0_SE15);

    //adc_init(ADC0_SE1);
}

void adc_read()
{
    a[4] = adc_once(ADC0_SE11, ADC_12bit);                        //电感原始值获得
    a[3] = adc_once(ADC0_SE12, ADC_12bit);
    a[2] = adc_once(ADC0_SE13, ADC_12bit);
    a[1] = adc_once(ADC0_SE14, ADC_12bit);
    a[0] = adc_once(ADC0_SE15, ADC_12bit);

    if(a[1] < 30)
        a[1] = 0;
    if(a[3] < 30)
        a[3] = 0;
    if(a[0] < 30)
        a[0] = 0;
    if(a[4] < 30)
        a[4] = 0;
    if(a[2] < 30)
        a[2] = 0;
}