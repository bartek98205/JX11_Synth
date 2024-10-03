
#include "Synth.h"

Synth::Synth()
{
    m_sampleRate = 44100.0f;
    m_noiseGen.setNoiseType(NoiseGenerator::noiseType::juceNoise);
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
    m_voice.reset();
    m_noiseGen.reset();
}

void Synth::render(float** outputBuffers, int sampleCount)
{
    float* outputBufferLeft = outputBuffers[0];
    float* outputBufferRight = outputBuffers[1];

    for (int s = 0; s < sampleCount; s++) {
        
        float noise = m_noiseGen.nextValue();
        float output = 0.0f;

        if(m_voice.note > 0)
            output = noise * (m_voice.velocity / 127.0f) * 0.5f;

        outputBufferLeft[s] = output;
        if (outputBufferRight != nullptr)
            outputBufferRight[s] = output;
    }
}

void Synth::midiMessage(uint8_t data0, uint8_t data1, uint8_t data2)
{
    switch (data0 & 0xF0) {  /// looking only on command (only 4 highest bytes)
    
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

void Synth::noteOn(int note, int velocity)
{
    m_voice.note = note;
    m_voice.velocity = velocity;
}

void Synth::noteOff(int note)
{
    if (note == m_voice.note) {
        m_voice.note = 0;
        m_voice.velocity = 0;
    }
}

