#include "Playlist.h"

Playlist::Playlist() {
    trackCount = 0;
    currentIndex = 0;
}

bool Playlist::addTrack(AudioTrack track) {
    if (trackCount >= MAX_TRACKS) return false;

    tracks[trackCount] = track;
    trackCount++;
    return true;
}

AudioTrack* Playlist::getCurrentTrack() {
    if (trackCount == 0) return nullptr;
    return &tracks[currentIndex];
}

AudioTrack* Playlist::nextTrack() {
    if (trackCount == 0) return nullptr;

    currentIndex = (currentIndex + 1) % trackCount;
    return &tracks[currentIndex];
}

AudioTrack* Playlist::previousTrack() {
    if (trackCount == 0) return nullptr;

    if (currentIndex == 0)
        currentIndex = trackCount - 1;
    else
        currentIndex--;

    return &tracks[currentIndex];
}

uint8_t Playlist::getTrackCount() {
    return trackCount;
}

void Playlist::reset() {
    currentIndex = 0;
}

// Get track at specific index
AudioTrack* Playlist::getTrack(uint8_t index) {
    if (index >= trackCount) return nullptr;
    return &tracks[index];
}

// Linear search by title - returns index if found, -1 if not found
int Playlist::linearSearchByTitle(String title) {
    for (int i = 0; i < trackCount; i++) {
        if (tracks[i].getTitle() == title) {
            return i;
        }
    }
    return -1;
}

// Linear search by track number - returns index if found, -1 if not found
int Playlist::linearSearchByTrackNumber(uint16_t trackNumber) {
    for (int i = 0; i < trackCount; i++) {
        if (tracks[i].getTrackNumber() == trackNumber) {
            return i;
        }
    }
    return -1;
}

// Selection sort by title (ascending order)
void Playlist::sortByTitle() {
    for (int i = 0; i < trackCount - 1; i++) {
        int minIndex = i;
        
        for (int j = i + 1; j < trackCount; j++) {
            if (tracks[j].getTitle() < tracks[minIndex].getTitle()) {
                minIndex = j;
            }
        }
        
        // Swap
        if (minIndex != i) {
            AudioTrack temp = tracks[i];
            tracks[i] = tracks[minIndex];
            tracks[minIndex] = temp;
        }
    }
}

// Selection sort by track number (ascending order)
void Playlist::sortByTrackNumber() {
    for (int i = 0; i < trackCount - 1; i++) {
        int minIndex = i;
        
        for (int j = i + 1; j < trackCount; j++) {
            if (tracks[j].getTrackNumber() < tracks[minIndex].getTrackNumber()) {
                minIndex = j;
            }
        }
        
        // Swap
        if (minIndex != i) {
            AudioTrack temp = tracks[i];
            tracks[i] = tracks[minIndex];
            tracks[minIndex] = temp;
        }
    }
}

