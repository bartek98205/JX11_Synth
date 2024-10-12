/** @ Noise Generator - based on pseudo random number generator 
*/

#pragma once


class NoiseGenerator
{
public:


	void reset()
	{
		m_noiseSeed = 22222;
	}

	float nextValue()
	{
		m_noiseSeed = m_noiseSeed * 196314165 + 907633515;
		int temp = int(m_noiseSeed >> 7) - 16777216;
		return float(temp) / 16777216.0f;
	}

private:
	unsigned int m_noiseSeed;

};
