#include "Soundboard.hpp"
#include "Utility.hpp"
#include "Game.hpp"

#include <iostream>
#include <pthread.h>
#include <fstream>
#include <alsa/asoundlib.h>


Soundboard* Soundboard::soundboard = nullptr;


Soundboard::Soundboard()
{
    //Create the musics filenames vector
    musicFilenames = {};
    
    musicFilenames.push_back("../resources/soundtracks/Pokemon XY - Route 4567.wav");
    musicFilenames.push_back("../resources/soundtracks/014 - Treasure Town.wav");
    musicFilenames.push_back("../resources/soundtracks/090 - Aegis Cave.wav");
    musicFilenames.push_back("../resources/soundtracks/PMD2 - DON'T EVER FORGET - Orchestral Remix.wav");
    musicFilenames.push_back("../resources/soundtracks/Pokemon BlackWhite - Route 6.wav");
    musicFilenames.push_back("../resources/soundtracks/Pokemon DiamondPearlPlatinum - Route 209.wav");
    musicFilenames.push_back("../resources/soundtracks/Pokemon RubySapphireEmerald - Route 101.wav");
    musicFilenames.push_back("../resources/soundtracks/route-24.wav");

    numberOfTracks = musicFilenames.size();
    trackIndex = 0;

}


Soundboard *Soundboard::getInstance()
{
    if (soundboard == nullptr){
        soundboard = new Soundboard();
    }
    return soundboard;}

void Soundboard::changeTrack()
{
    int moveIndex = 1 + rand()%(numberOfTracks-1);
    trackIndex = (trackIndex + moveIndex)%numberOfTracks;
}

void Soundboard::playMusic()
{
    int alsaReady = true;
    //Initialise ALSA

    snd_pcm_t* pcm_handle;
    snd_pcm_hw_params_t* params;
    unsigned int sample_rate = 44100;
    int dir;
    snd_pcm_uframes_t frames = 1024;

    if (snd_pcm_open(&pcm_handle, "default", SND_PCM_STREAM_PLAYBACK, 0) < 0) {
        std::cerr << "Error accessing audio peripherals" << std::endl;
        alsaReady = false;
    }

    snd_pcm_hw_params_malloc(&params);
    snd_pcm_hw_params_any(pcm_handle, params);
    snd_pcm_hw_params_set_access(pcm_handle, params, SND_PCM_ACCESS_RW_INTERLEAVED);
    snd_pcm_hw_params_set_format(pcm_handle, params, SND_PCM_FORMAT_S16_LE);
    snd_pcm_hw_params_set_channels(pcm_handle, params, 2);
    snd_pcm_hw_params_set_rate_near(pcm_handle, params, &sample_rate, &dir);
    snd_pcm_hw_params_set_period_size_near(pcm_handle, params, &frames, &dir);

    if (snd_pcm_hw_params(pcm_handle, params) < 0) {
        std::cerr << "Error during audio peripherals configuration" << std::endl;
        alsaReady = false;
    }
    snd_pcm_hw_params_free(params);


    //let the music play
    while (Game::running){
        playTrack(trackIndex, pcm_handle, frames);
        changeTrack();
    }

    snd_pcm_drop(pcm_handle);
    snd_pcm_close(pcm_handle);
}

void Soundboard::playTrack(int sel, snd_pcm_t* pcm_handle, snd_pcm_uframes_t frames)
{
    std::ifstream audiofile(musicFilenames[trackIndex], std::ios::binary);
    if (!audiofile){
        std::cerr << "Could not open music file " << musicFilenames[trackIndex] << std::endl;
    }
    else {
        // read the header of the file
        char buffer[44];
        audiofile.read(buffer, 44);

        //play the soundtrack
        snd_pcm_uframes_t bufferSize = frames*4;
        char* data = new char[bufferSize];

        bool condition = ((Game::running)&&(Game::asyncInput != 'n')&&(audiofile.read(data, bufferSize)));
        
        while (condition) {
            if (snd_pcm_writei(pcm_handle, data, frames) == -EPIPE) {
                snd_pcm_prepare(pcm_handle);
            }
            condition = ((Game::running)&&(Game::asyncInput != 'n')&&(audiofile.read(data, bufferSize)));
        }

        delete[] data;
        audiofile.close();
    }
}

Soundboard::~Soundboard()
{
}