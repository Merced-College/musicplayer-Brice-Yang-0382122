#include "AudioTrack.h"

AudioTrack::AudioTrack() {
    trackNumber = 0;
    title = "";
    duration = 0;
}

AudioTrack::AudioTrack(uint16_t number, String name, uint16_t durationSec) {
    trackNumber = number;
    title = name;
    duration = durationSec;
}

uint16_t AudioTrack::getTrackNumber() {
    return trackNumber;
}

String AudioTrack::getTitle() {
    return title;
}

uint16_t AudioTrack::getDuration() {
    return duration;
}

