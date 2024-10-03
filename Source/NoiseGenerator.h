/** @ Noise Generator - based on pseudo random number generator 
*/
#pragma once

#include <juce_core\maths\juce_Random.h>
class NoiseGenerator
{
public:

	static enum noiseType { juceNoise, onwNoise };
	juce::Random* ran;

	void reset()
	{
		noiseSeed = 22222;
	}

	void setNoiseType(noiseType type)
	{
		m_noiseType = type;
	}

	float nextValue()
	{
		if (m_noiseType = onwNoise) {
			noiseSeed = noiseSeed * 196314165 + 907633515;
			int temp = int(noiseSeed >> 7) - 16777216;
			return float(temp) / 16777216.0f;
		} else {
			return ran->nextFloat();
		}
	}

private:
	unsigned int noiseSeed;
	noiseType m_noiseType;

};
