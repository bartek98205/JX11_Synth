/** @brief Oscillator class simple oscillator used for synth 
*
*/

#pragma once

const float TWO_PI = 6.2831853071795864f;

class Oscillator
{
public:
	float amplitude;
	float phase;
	float inc;

	float getNextSample()
	{
		phase += inc;
		if (phase >= 1.0f)
			phase -= 1.0f;

		float nextSample =  amplitude * std::sin(TWO_PI * phase);
		
		return nextSample;
	}

	void reset()
	{
		phase = 1.5707963268f;
	}
};