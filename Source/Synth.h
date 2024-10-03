#pragma once

#include <JuceHeader.h>
#include "Voice.h"
#include "NoiseGenerator.h"
/** @brief Synth class is a main synthesizer class which makes actual sound 
* 
*/

class Synth
{
public:
	Synth();
	void allocateResources(double sampleRate, int samplesPerBlock);
	void deallocateResources();
	void reset();
	void render(float** outputBuffers, int sampleCount);
	void midiMessage(uint8_t data0, uint8_t data1, uint8_t data2);
	void noteOn(int note, int velocity);
	void noteOff(int note);

private:
	float m_sampleRate;
	Voice m_voice;
	NoiseGenerator m_noiseGen;
};
