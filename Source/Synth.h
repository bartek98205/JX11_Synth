#pragma once

#include <JuceHeader.h>
#include "Voice.h"

/** @brief Synth class is a main synthesizer class which makes actual sound 
* 
*/

class Synth
{
public:
	void allocateResources(double sampleRate, int samplesPerBlock);
	void deallocateResources();
	void reset();
	void render(float** outputBuffers, int sampleCount);
	void midiMessage(uint8_t data0, uint8_t data1, uint8_t data2);

private:
	float sampleRat;
	Voice voice;
};
