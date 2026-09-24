#include "esfera_utils.h"

void CalculaVolume (float R, float *volume){
    *volume = (PI*R*R*R*4)/3;
}

void CalculaArea (float R, float *area){
    *area = 4*PI*R*R;
}