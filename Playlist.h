#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <Arduino.h>
#include "AudioTrack.h"

#define MAX_TRACKS 50

class Playlist {
private:
    AudioTrack tracks[MAX_TRACKS];
    uint8_t trackCount;
    uint8_t currentIndex;

public:
    Playlist();

    bool addTrack(AudioTrack track);
    AudioTrack* getCurrentTrack();

    AudioTrack* nextTrack();
    AudioTrack* previousTrack();

    uint8_t getTrackCount();
    void reset();
    
    // Getter for individual track at index
    AudioTrack* getTrack(uint8_t index);

    // Linear search
    int linearSearchByTitle(String title);
    int linearSearchByTrackNumber(uint16_t trackNumber);

    // Selection sort
    void sortByTitle();
    void sortByTrackNumber();
};

#endif