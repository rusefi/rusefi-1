/**
 * @file	adc_inputs.h
 * @brief	Low level internal ADC code
 *
 * @date Jan 14, 2013
 * @author Andrey Belomutskiy, (c) 2012-2020
 */

#pragma once

#include "global.h"
#include "adc_math.h"

#define SLOW_ADC_RATE 500

#if HAL_USE_ADC

adc_channel_mode_e getAdcMode(adc_channel_e hwChannel);
void initAdcInputs();

// deprecated - migrate to 'getAdcChannelBrainPin'
int getAdcChannelPin(adc_channel_e hwChannel);

// deprecated - migrate to 'getAdcChannelBrainPin'
ioportid_t getAdcChannelPort(const char *msg, adc_channel_e hwChannel);

adc_channel_e getAdcChannel(brain_pin_e pin);
brain_pin_e getAdcChannelBrainPin(const char *msg, adc_channel_e hwChannel);

// wait until at least 1 slowADC sampling is complete
void waitForSlowAdc(int lastAdcCounter = 0);
// get a number of completed slowADC samples
int getSlowAdcCounter();

int getAdcHardwareIndexByInternalIndex(int index);

void printFullAdcReportIfNeeded(Logging *log);
int getInternalAdcValue(const char *msg, adc_channel_e index);
float getMCUInternalTemperature(void);

void addChannel(const char *name, adc_channel_e setting, adc_channel_mode_e mode);
void removeChannel(const char *name, adc_channel_e setting);

/* Depth of the conversion buffer, channels are sampled X times each.*/
#ifndef ADC_BUF_DEPTH_SLOW
#define ADC_BUF_DEPTH_SLOW      8
#endif /* ADC_BUF_DEPTH_SLOW */

#ifndef ADC_BUF_DEPTH_FAST
#define ADC_BUF_DEPTH_FAST      4
#endif /* ADC_BUF_DEPTH_FAST */

// todo: preprocessor way of doing 'max'?
// max(ADC_BUF_DEPTH_SLOW, ADC_BUF_DEPTH_FAST)
#define MAX_ADC_GRP_BUF_DEPTH 8

#define getAdcValue(msg, hwChannel) getInternalAdcValue(msg, hwChannel)

// todo: migrate to adcToVoltageInputDividerCoefficient
#define adcToVoltsDivided(adc) (adcToVolts(adc) * engineConfiguration->analogInputDividerCoefficient)

#else
#define getAdcValue(msg, channel) 0
#endif /* HAL_USE_ADC */

