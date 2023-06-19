#ifndef ADC_H
#define ADC_H
#include "soc/soc_caps.h"
#include "esp_log.h"
#include "esp_adc/adc_oneshot.h"
#include "esp_adc/adc_cali.h"
#include "esp_adc/adc_cali_scheme.h"


void adcDrv_init();

bool adcDrv_getValue(uint8_t channel, uint16_t* result);

void adcDrv_proc();

#endif /* ADC_H */