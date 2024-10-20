/** @brief Oscillator class simple oscillator used for synth 
*
*/

#pragma once

const float TWO_PI = 6.2831853071795864f;

class Oscillator
{
private :
	float m_sin0;
	float m_sin1;
	float m_dsin;

public:
	float amplitude;
	float phase;
	float inc;

	float getNextSample()
	{
		// TODO zaimplementowaæ mo¿liwoœæ przejsca z sinus waveform na pi³okszta³tn¹ 
		// digital resonator
		float sinx = m_dsin * m_sin0 - m_sin1;
		m_sin1 = m_sin0;
		return sinx;
	}

	void reset()
	{
		phase = 1.5707963268f;
		// digital resonator
		m_sin0 = amplitude * std::sin(phase * TWO_PI);
		m_sin1 = amplitude * std::sin(phase - inc) * TWO_PI);
		m_dsin = 2.0f * std::cos(inc*TWO_PI);
	}
};