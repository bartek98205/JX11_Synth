/* @brief Voice structure which produce next output for given note
*
*/

#pragma once

#include "Oscillator.h"

struct Voice
{
	int m_note; 
	Oscillator m_osc;

	void reset()
	{
		m_note = 0;
		m_osc.resest();
	}

	float render()
	{
		return m_osc.getNextSample();
	}
};