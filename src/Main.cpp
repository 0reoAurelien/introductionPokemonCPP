

#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

#include "Utility.hpp"
#include "Game.hpp"

#include "Soundboard.hpp"


int main(){

    Game* game = new Game();
    game->play();

    delete game;
    std::cout << "Game exited successfully" << std::endl;
    
    return 0;

}