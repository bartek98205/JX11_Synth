/** @brief Oscillator class simple oscillator used for synth 
*
*/

#pragma once

const float TWO_PI = 6.2831853071795864f;
const float PI = 3.1415926535897932f;
const float PI_OVER_4 = 0.7853981633974483f;

class Oscillator
{
private :
	float inc;
	float phase;
	float phaseMax;

public:
	float amplitude = 1.0f;;
	float period = 0.0f;


	float getNextSample()
	{
		float output = 0.0f;

		phase += inc;
		
		/*
		* When phase <= PI_OVER_4 is true,it means the oscillator should start a new impulse. Recall that
		*phase is measured in samples times π. If the phase is less than π/4, the end of the
		*previous impulse is reached and you need to start a new one. The oscillator enters
		*this if statement once per period, and also immediately when a new note starts 
		*/
		if (phase <= PI_OVER_4) {

			/*
			* Find wherethemidpointwill be between the peak that was just finished and the next
			*one. This depends on the period. If period is 100 samples, the next midpoint will be
			*50 samples	into the future.
			*/
			float halfPeriod = period / 2.0f;
			phaseMax = std::floor(0.5f + halfPeriod) - 0.5f;
			phaseMax *= PI;
			inc = phaseMax / halfPeriod;
			phase = -phase;
		
			//Caluclate sinc fn
			
			if (phase * phase > 1e-9) {
				output = amplitude * std::sin(phase) / phase;
			} else {
				output = amplitude;
			}
		} else { // current sample is somewhere between the previous peak and the next
			
			if (phase > phaseMax) { ///  outputting the sinc function backwards
				phase = phaseMax + phaseMax - phase;
				inc = -inc;
			}

			// Calculate sinc fn

			output = amplitude * std::sin(phase) / phase;
		}
		return output;
	}

	void reset()
	{
		phase = 0.0f;
		inc = 0.0f;
	}
};