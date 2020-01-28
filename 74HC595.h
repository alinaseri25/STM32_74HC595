#ifndef _74HC595_H
#define _74HC595_H

#include "stm32f1xx_hal.h"


class _74HC595
{
public:
	_74HC595(GPIO_TypeDef *_DTS_Port,uint16_t _DTS_Pin,GPIO_TypeDef *_SH_CP_Port,uint16_t _SH_CP_Pin,GPIO_TypeDef *_ST_CP_Port,uint16_t _ST_CP_Pin);
	void SendCommand(GPIO_PinState *Pins);
	void ReArrangeSend(GPIO_PinState *Pins);
private:
	GPIO_TypeDef *DTS_P,*SH_CP_P,*ST_CP_P;
	uint16_t DTS,SH_CP,ST_CP;
};

#endif
