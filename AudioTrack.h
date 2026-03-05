#ifndef AUDIO_TRACK_H
#define AUDIO_TRACK_H

#include <Arduino.h>

class AudioTrack {
private:
    uint16_t trackNumber;
    String title;
    uint16_t duration; // optional metadata

public:
    AudioTrack();
    AudioTrack(uint16_t number, String name, uint16_t durationSec);

    uint16_t getTrackNumber();
    String getTitle();
    uint16_t getDuration();
};

#endif

