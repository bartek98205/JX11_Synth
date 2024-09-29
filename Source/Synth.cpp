/*
  ==============================================================================

    Synth.cpp
    Created: 28 Sep 2024 5:44:39pm
    Author:  barto

  ==============================================================================
*/

#include "Synth.h"

Synth::Synth()
{
    m_sampleRate = 44100.0f;
}

void Synth::allocateResources(double sampleRate, int samplesPerBlock)
{
    m_sampleRate = static_cast<float>(sampleRate);
}

void Synth::deallocateResources()
{
}

void Synth::reset()
{
}

void Synth::render(float** outputBuffers, int sampleCount)
{
}

void Synth::midiMessage(uint8_t data0, uint8_t data1, uint8_t data2)
{
    switch (data0 & 0xF0) {
    
        //note off
        case 0x80:
            noteOff(data1 & 0x7F);
            break;
        
        //note on
        case 0x90: {
            uint8_t note = data1 & 0x7F;
            uint8_t velo = data2 & 0x7F;
            if (velo > 0)
                noteOn(note, velo);
            else
                noteOff(note);
            break;
        }
    }
    
}

