#include "Game.hpp"
#include "Utility.hpp"
#include <iostream>
#include <string>
#include <vector>


#define ExitGame 0
#define LoadingGame 1

#define MainMenu 2
#define MultiplayerMenu 3
#define SinglePlayerMenu 4
#define Settings 5

#define Dueling 6
#define TeamSelection 7

#define Training 8
#define GymAttempt 9

using std::string;
using std::vector;


Game::Game():
state(LoadingGame){
    srand(time(NULL));
}

int Game::gamemode = MultiPlayerMode;
    
Pokemon* Game::activeEnemy = nullptr;


void Game::play(){
    while (state){
        switch (state){
            case LoadingGame:{
                clearFrame();
                std::cout << "Welcome to the wonderful world of Pokemon !\n" << std::endl;

                Pokedex* pokedex = Pokedex::getInstance();

                std::cout << "Please enter your name to start the game\n" << std::endl;
                string wait = "";

                std::cin >> wait;
                clearFrame();

                std::cout << "Are you sure that you are not Mr. Tauvel ?\n" << std::endl;
                std::cin >> wait;

                state = MainMenu;
                break;
            }
            case MainMenu:{
                clearFrame();
                std::cout << "Bonjour M. Tauvel !\n\n" << std::endl;
                string choice = "";
                vector <string> options = {"multiplayer", "singleplayer"/*, "settings"*/, "exit"};
                int wrongChoice = 1;
                state = MultiplayerMenu;
                int modeSelection = 0;
                while (wrongChoice)
                {
                    std::cout << "Select a gamemode 'singleplayer'/'multiplayer'\nor type 'exit' to close the game."/*or access settings(WIP)\n"*/ << std::endl;
                    std::cin >> choice;
                    choice = stringTolower(choice);
                    modeSelection=0;
                    for (string option : options){
                        if (choice == option){
                            wrongChoice = 0;
                            state = (state + modeSelection)%(options.size()+2);
                        }
                        else {
                            modeSelection++;
                        }
                    }
                    clearFrame();
                    if (wrongChoice){
                        std::cout << "Please pick a valid option\n" << std::endl;
                    }
                }
                break;
                
            }

            case MultiplayerMenu:{
                //std::cout << "This mode is still under development, sorry\n" << std::endl;
                playMulti();
                state = MainMenu;
            }

            case SinglePlayerMenu:{
                //std::cout << "This mode is still under development, sorry\n" << std::endl;
                playSolo();
                state = MainMenu;
            }
            
            default:{
                //state = ExitGame;
                break;
            }
        }
    }
    std::cout << "I hope you enjoyed the game ! Have a nice day !\n\n" << std::endl;
}


void Game::playMulti(){
    gamemode = MultiPlayerMode;
    while (state != MainMenu){
        switch (state){

            case MultiplayerMenu:{
                clearFrame();
                std::cout << "***** Multiplayer *****\n" << std::endl;
                string choice = "";
                vector <string> options = {"duel", "selection", "", "", "back"};
                int wrongChoice = 1;
                state = Dueling;
                int modeSelection = 0;
                while (wrongChoice)
                {
                    std::cout << "Select 'duel' to fight or 'selection' to edit your teams.\nType 'back' to go back to the main menu."/*or access settings(WIP)\n"*/ << std::endl;
                    std::cin >> choice;
                    choice = stringTolower(choice);
                    modeSelection=0;
                    for (string option : options){
                        if (choice == option){
                            wrongChoice = 0;
                            state = (state + modeSelection)%(8);
                        }
                        else {
                            modeSelection++;
                        }
                    }
                    clearFrame();
                    if (wrongChoice){
                        std::cout << "Please pick a valid option\n" << std::endl;
                    }
                }
                break;
                
            }

            case TeamSelection:{
                clearFrame();
                std::cout << "*** Team Menu ***\n" << std::endl;
                string choice = "";
                int wrongChoice = 1;
                state = Dueling;
                int modeSelection = 0;
                while (wrongChoice)
                {
                    std::cout << "Select which team you want to edit ('both', 'player1' or 'player2').\nType 'confirm' when your teams are ready."/*or access settings(WIP)\n"*/ << std::endl;
                    
                    if ((bothReady[1])&&(bothReady[2])){
                        std::cout << "Note: both players have pokemons in their team.\n"<< std::endl;
                    }
                    else {
                        std::cout << "Note: your teams are not ready yet.\n"<< std::endl;
                    }
                    std::cin >> choice;
                    choice = stringTolower(choice);
                    wrongChoice = 0;
                    if (choice == "confirm"){
                        state = MultiplayerMenu;
                    }
                    else{
                        if (choice == "both"){
                        string wait = "";
                        std::cout << "It's Player1's turn to create their team" << std::endl;
                        std::cin >> wait;
                        bothReady[0] = editPlayer(1);
                        std::cout << "It's now Player2's turn to create their team" << std::endl;
                        std::cin >> wait;
                        bothReady[1] = editPlayer(2);
                        }
                        else {
                            if(choice == "player1"){
                            bothReady[0] = editPlayer(1);
                            }
                            else {
                                if(choice == "player2"){
                                    bothReady[1] = editPlayer(2);
                                }
                                else {
                                    wrongChoice = 1;
                                }
                            }
                        }
                    }
                    clearFrame();
                    if (wrongChoice){
                        std::cout << "Please pick a valid option\n" << std::endl;
                    }
                }
                break;
            }
            

            case Dueling:{
                //std::cout << "This mode is still under development, sorry\n" << std::endl;
                playSolo();
                state = MainMenu;
            }
            

            default:{
                state = ExitGame;
                break;
            }
        }
    }
}

void Game::playSolo()
{
}


int Game::editPlayer(int sel)
{
    clearFrame();
    std::cout << "*** Team Selection ***\n" << std::endl;
    int count = 0;
    Pokemon* pokeToAdd = nullptr;
    string choice = "";
    int ready = 0;

    if (sel == 1){

        int ready = 0;
        while (!ready){
            std::cout << "Player 1, is there a pokemon that you want in your team ?\nYou can pick a total of 6 pokemons.\nType 'ready' when you are done !" << std::endl;
            std::cin >> choice;
            choice = stringTolower(choice);

            if (choice == "ready"){
                ready = 1;
            }
            else {
                pokeToAdd = pokedex->getPokemonByName(choice);
                if (pokeToAdd != nullptr){
                    player1->addPokeToParty(pokeToAdd, MultiPlayerMode);
                }
            }
        }
        count = player1->pokemonParty->getPartySize();
    }


    if (sel == 2){
        int ready = 0;
        while (!ready){
            std::cout << "Player 2, is there a pokemon that you want in your team ?\nYou can pick a total of 6 pokemons.\nType 'ready' when you are done !" << std::endl;
            std::cin >> choice;
            choice = stringTolower(choice);

            if (choice == "ready"){
                ready = 1;
            }
            else {
                pokeToAdd = pokedex->getPokemonByName(choice);
                if (pokeToAdd != nullptr){
                    player2->addPokeToParty(pokeToAdd, MultiPlayerMode);
                }
            }
        }
        count = player2->pokemonParty->getPartySize();
    }

    return count;
}


Game::~Game()
{
}
