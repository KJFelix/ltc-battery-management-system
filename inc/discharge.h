#ifndef DISCHARGE_H
#define DISCHARGE_H
#include "state_types.h"

void Discharge_Init(BMS_STATE_T *state);
void Discharge_Config(BMS_STATE_T *state);
uint8_t Discharge_Step(BMS_INPUT_T *input, BMS_STATE_T *state, BMS_OUTPUT_T *output);

#endif
