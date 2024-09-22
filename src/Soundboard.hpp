#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <alsa/asoundlib.h>

using std::string;
using std::vector;

class Soundboard
{
private:
    Soundboard();
    Soundboard(const Soundboard&) = delete;
    Soundboard& operator=(const Soundboard&) = delete;
    static Soundboard* soundboard;

    vector <const char*> musicFilenames;
public:
    static Soundboard * getInstance();


    int numberOfTracks;
    int trackIndex;
    void changeTrack();
    void playMusic();
    void playTrack(int sel, snd_pcm_t* pcm_handle, snd_pcm_uframes_t frames);
    ~Soundboard();
};
