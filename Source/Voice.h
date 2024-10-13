/* @brief Voice structure which produce next output for given note
*
*/

#pragma once

#include "Oscillator.h"

struct Voice
{
	int note; 
	Oscillator osc;

	void reset()
	{
		note = 0;
		osc.reset();
	}

	float render()
	{
		return osc.getNextSample();
	}
};