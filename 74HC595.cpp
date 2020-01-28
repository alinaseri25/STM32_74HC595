#include "74HC595.h"

_74HC595::_74HC595(GPIO_TypeDef *_DTS_Port,uint16_t _DTS_Pin,GPIO_TypeDef *_SH_CP_Port,uint16_t _SH_CP_Pin,GPIO_TypeDef *_ST_CP_Port,uint16_t _ST_CP_Pin)
{
	DTS_P = _DTS_Port;
	DTS = _DTS_Pin;
	
	SH_CP_P = _SH_CP_Port;
	SH_CP = _SH_CP_Pin;
	
	ST_CP_P = _ST_CP_Port;
	ST_CP = _ST_CP_Pin;
}

void _74HC595::SendCommand(GPIO_PinState *Pins)
{
	HAL_GPIO_WritePin(DTS_P,DTS,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(SH_CP_P,SH_CP,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(ST_CP_P,ST_CP,GPIO_PIN_RESET);
	for(int8_t bit = 23 ; bit >= 0 ; bit--)
	{
		HAL_GPIO_WritePin(DTS_P,DTS,Pins[bit]);
		HAL_GPIO_WritePin(SH_CP_P,SH_CP,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SH_CP_P,SH_CP,GPIO_PIN_SET);
	}
	HAL_GPIO_WritePin(SH_CP_P,SH_CP,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(ST_CP_P,ST_CP,GPIO_PIN_SET);
}

void _74HC595::ReArrangeSend(GPIO_PinState *Pins)
{
	GPIO_PinState Pins_Temp[24];
	Pins_Temp[0] = Pins[0];
	Pins_Temp[1] = Pins[1];
	Pins_Temp[2] = Pins[2];
	Pins_Temp[3] = Pins[3];
	Pins_Temp[8] = Pins[4];
	Pins_Temp[9] = Pins[5];
	Pins_Temp[10] = Pins[6];
	Pins_Temp[11] = Pins[7];
	Pins_Temp[16] = Pins[8];
	Pins_Temp[17] = Pins[9];
	Pins_Temp[18] = Pins[10];
	Pins_Temp[19] = Pins[11];
	Pins_Temp[4] = Pins[12];
	Pins_Temp[5] = Pins[13];
	Pins_Temp[6] = Pins[14];
	Pins_Temp[7] = Pins[15];
	Pins_Temp[12] = Pins[16];
	Pins_Temp[13] = Pins[17];
	Pins_Temp[14] = Pins[18];
	Pins_Temp[15] = Pins[19];
	Pins_Temp[20] = Pins[20];
	Pins_Temp[21] = Pins[21];
	Pins_Temp[22] = Pins[22];
	Pins_Temp[23] = Pins[23];
	
	SendCommand(Pins_Temp);
}
