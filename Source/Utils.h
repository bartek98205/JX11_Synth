/** @ Class which provides some ear protection
*/

#pragma once

inline void protectYourEars(float* buffer, int sampleCount)
{
	if (buffer == nullptr)
		return;
	bool silencing = false;
	for (int s = 0; s < sampleCount; s++) {
		float sample = buffer[s];
		if (std::isnan(sample) || std::isinf(sample)) {
			DBG ("!!! Invalid sample value - silencing !!!");
			silencing = true;
		} else if (sample < -1.0f || sample > 1.0f) {
			DBG("!!! Sample value out of range - silencing !!!");
			silencing = true;
		}
		if (silencing) {
			memset(buffer, 0, sampleCount * sizeof(float));
			return;
		}
	}
}
