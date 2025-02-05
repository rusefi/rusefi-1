/**
 * @file frequency_sensor.h
 */
#include "functional_sensor.h"
#include "timer.h"
#include "biquad.h"

class FrequencySensor : public FunctionalSensor {
public:
	FrequencySensor(SensorType type, efitick_t timeoutPeriod)
		: FunctionalSensor(type, timeoutPeriod)
	{ }

	void initIfValid(brain_pin_e pin, SensorConverter &converter, float filterParameter);
	void deInit();

	// sad workaround: we are not good at BiQuad configuring
	bool useBiQuad = true;

	void onEdge(efitick_t nowNt);

	int eventCounter = 0;
private:
	Timer m_edgeTimer;
	brain_pin_e m_pin = Gpio::Unassigned;

	Biquad m_filter;
};
