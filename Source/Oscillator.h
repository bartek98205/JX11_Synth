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

	float freq;
	float sampleRate;
	float phaseBL;

	float nextBandlimitedSample()
	{
		phaseBL += inc;
		if (phaseBL >= 1.0f) {
			phaseBL -=1.0f;
		}

		float output = 0.0f;
		float nyquist = sampleRate / 2.0f;
		float h = freq;
		float i = 1.0f;
		float m = 0.6366197724f;
		while (h < nyquist) {
			output += m * std::sin(TWO_PI * phaseBL * i) / i;
			h += freq;
			i += 1.0f;
			m = -m;
		}
		return output;
	}

	float getNextSample()
	{
		// TODO zaimplementowaæ mo¿liwoœæ przejsca z sinus waveform na pi³okszta³tn¹ 
		// digital resonator
		
		// sinwave// 
		/*float sinx = m_dsin * m_sin0 - m_sin1;
		m_sin1 = m_sin0;
		m_sin0 = sinx;
		return sinx;*/

		phase += inc; 

		if(phase >= 1.0f)
			phase -= 1.0f;

		return amplitude * nextBandlimitedSample();;
	}

	void reset()
	{
		phase = 0.0f;
		phaseBL = -0.5f;
		// sinwave //
		/*phase = 1.5707963268f;
		// digital resonator
		m_sin0 = amplitude * std::sin(phase * TWO_PI);
		m_sin1 = amplitude * std::sin((phase - inc) * TWO_PI);
		m_dsin = 2.0f * std::cos(inc*TWO_PI);
		*/
	}
};