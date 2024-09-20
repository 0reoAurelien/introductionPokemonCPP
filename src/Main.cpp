

#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

//#include "Pokedex.hpp"
//#include "SetOfPokemon.hpp"
//#include "Pokeball.hpp"
#include "Utility.hpp"
#include "Game.hpp"
#include "Sound.hpp"

extern pid_t child_pid;
extern pid_t pid;

int main(){
    
//TRIGGER WARNING
//je vais faire n'importe quoi dans les 7 prochaines lignes

    signal(SIGTERM, handle_sigterm);

    pid = fork();
    if (pid==0){
        child_pid = fork();
        if (child_pid==0){
            std::cout << "Process1 entered successfully" << std::endl;

            while(1){
                usleep(1000000);
            }
        }
        else if (child_pid>0){
            std::cout << "Process2 entered successfully" << std::endl;
            //inputListener(); //careful with that, as it blocks the basic std::cin 
            while(1){
                usleep(1000000);
            }
        }
        else {
            std::cerr << "a fork() failed" << std::endl;
        }
    }
    else if (pid > 0){
        std::cout << "Process3 entered successfully" << std::endl;
        usleep(10000);
        Game* game = new Game();
        game->play();

    }
    else{
        std::cerr << "a fork() failed" << std::endl;

        return 1;
    }

    int status;
    kill(pid, SIGTERM);
    wait(&status);

    std::cout << "Process exited successfully" << std::endl;
    
    return 0;

/*
    Game* game = new Game();
    game->play();
    return 0;
    */
}