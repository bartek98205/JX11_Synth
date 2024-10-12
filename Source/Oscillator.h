/** @brief Oscillator class simple oscillator used for synth 
*
*/

#pragma once

const float TWO_PI = 6.2831853071795864f;

class Oscillator
{
public:
	float m_amplitude;
	float m_freq;
	float m_phaseOffset;
	float m_sampleRate;
	int m_sampleIndex;

	float getNextSample()
	{
		float nextSample =  m_amplitude * std::sin(
			TWO_PI * m_freq * m_sampleIndex /m_sampleRate + m_phaseOffset);
		
		++m_sampleRate;
		return nextSample;
	}

	void reset()
	{
		m_sampleIndex = 0;
	}
};