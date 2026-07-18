#pragma once
#include "utils.h"

#ifndef EMU
void HAL_SAI_RxCpltCallback(SAI_HandleTypeDef* hi2s);
void HAL_SAI_RxHalfCpltCallback(SAI_HandleTypeDef* hi2s);
#endif

void init_codec(void);
void codec_update_volume(void);
