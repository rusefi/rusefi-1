// auto-generated by PinoutLogic.java

#include "pch.h"

const char * getBoardSpecificPinName(brain_pin_e brainPin) {
	switch(brainPin) {
		case Gpio::PROTECTED_PIN_0: return "Out 1";
		case Gpio::PROTECTED_PIN_1: return "Out 2";
		case Gpio::PROTECTED_PIN_2: return "Out 3";
		case Gpio::PROTECTED_PIN_3: return "Out 4";
		case Gpio::PROTECTED_PIN_4: return "Out 5";
		case Gpio::PROTECTED_PIN_5: return "Out 6";
		case Gpio::PROTECTED_PIN_6: return "Out 7";
		case Gpio::PROTECTED_PIN_7: return "Out 8";
		default: return nullptr;
	}
	return nullptr;
}
