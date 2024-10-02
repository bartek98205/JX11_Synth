
#pragma once

/* @brief Voice structure which produce next output for given note
*
*/
struct Voice
{
	int note; 
	int velocity;

	void reset()
	{
		note = 0;
		velocity = 0;
	}
};