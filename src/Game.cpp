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

                pokedex = Pokedex::getInstance();

                std::cout << "Please enter your name to start the game\n" << std::endl;
                
                waitConfirm();
                clearFrame();

                std::cout << "Are you sure that you are not Mr. Tauvel ?\n" << std::endl;
                waitConfirm();

                state = MainMenu;
                break;
            }
            case MainMenu:{
                clearFrame();
                std::cout << "Bonjour M. Tauvel !\n\n" << std::endl;
                string choice = "";
                vector <string> optionList = {"multiplayer", "singleplayer"/*, "settings"*/, "exit"};
                int resultingStates[] = {MultiplayerMenu, SinglePlayerMenu/*, "settings"*/, ExitGame};
                int wrongChoice = 1;
                state = MultiplayerMenu;
                int modeSelection = 0;
                while (wrongChoice)
                {
                    std::cout << "Select a gamemode 'singleplayer'/'multiplayer'\nor type 'exit' to close the game."/*or access settings(WIP)\n"*/ << std::endl;
                    std::cin >> choice;
                    choice = stringTolower(choice);
                    string option = ""; 
                    for (int i = 0; i < optionList.size() ; i++){
                        option = optionList.at(i);
                        if (choice == option){
                            wrongChoice = 0;
                            state = resultingStates[i];
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
                player1 = new Player("Player1");
                player2 = new Player("Player2");                
                playMulti();
                break;
            }

            case SinglePlayerMenu:{
                //std::cout << "This mode is still under development, sorry\n" << std::endl;
                playSolo();
                state = MainMenu;
                break;
            }
            
            default:{
                state = LoadingGame;
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
                vector <string> optionList = {"duel", "selection", "back"};
                int resultingStates[] = {Dueling, TeamSelection/*, "settings"*/, MainMenu};
                int wrongChoice = 1;
                int modeSelection = 0;

                while (wrongChoice)
                {
                    std::cout << "Select 'duel' to fight or 'selection' to edit your teams.\nType 'back' to go back to the main menu."/*or access settings(WIP)\n"*/ << std::endl;
                    std::cin >> choice;
                    choice = stringTolower(choice);
                    string option = ""; 
                    for (int i = 0; i < optionList.size() ; i++){
                        option = optionList.at(i);
                        if (choice == option){
                            wrongChoice = 0;
                            state = resultingStates[i];
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
                int modeSelection = 0;
                while (wrongChoice)
                {
                    std::cout << "Select which team you want to edit ('both', 'player1' or 'player2').\nType 'confirm' when your teams are ready."/*or access settings(WIP)\n"*/ << std::endl;
                    
                    if ((bothReady[0])&&(bothReady[1])){
                        std::cout << "Note: both players have a team ready to fight.\n"<< std::endl;
                    }
                    else {
                        std::cout << "Note: your teams are not ready yet.\n"<< std::endl;
                    }
                    std::cin >> choice;
                    choice = stringTolower(choice);
                    wrongChoice = 0;
                    if (choice == "confirm"){
                        clearFrame();
                        state = MultiplayerMenu;
                    }
                    else{
                        if (choice == "both"){
                            if (player1 != nullptr){
                                delete player1;
                            }
                            if (player2 != nullptr){
                                delete player2;
                            }
                            clearFrame();
                            std::cout << "It's Player1's turn to create their team" << std::endl;
                            waitConfirm();
                            bothReady[0] = editPlayer(1);
                            clearFrame();
                            std::cout << "It's now Player2's turn to create their team" << std::endl;
                            waitConfirm();
                            bothReady[1] = editPlayer(2);
                        }
                        else {
                            if(choice == "player1"){
                                if (player1 != nullptr){
                                    delete player1;
                                }
                                clearFrame();
                                bothReady[0] = editPlayer(1);
                            }
                            else {
                                if(choice == "player2"){
                                    if (player2 != nullptr){
                                        delete player2;
                                    }
                                    clearFrame();
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
                std::cout << "Here is the team of " << player1->getUsername() << " :" << std::endl;
                player1->pokemonParty->displayListDetails();
                waitConfirm();
                clearFrame();
                std::cout << "And here is the team of " << player2->getUsername() << " :" << std::endl;
                player2->pokemonParty->displayListDetails();
                waitConfirm();
                clearFrame();

                std::cout << "Vous savez, moi je pense que la violence ne résout rien" << std::endl;
                waitConfirm();
                std::cout << "Et puis comme on dit toujours, l'important c'est de participer" << std::endl;
                waitConfirm();
                std::cout << "Vous n'allez quand même pas vous battre ?\nRevenez plutôt au menu du jeu" << std::endl;
                waitConfirm();

                //Duel();
                state = MainMenu;
            }
            

            default:{
                state = MultiplayerMenu;
                break;
            }
        }
    }
}

void Game::playSolo()
{
    clearFrame();
    std::cout << "Unfortunately, you arrived too early !\nThis mode is still under development." << std::endl;
    waitConfirm();
    state = MainMenu;
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

        std::cout << "Player 1, what is your name ?" << std::endl;
        std::cin >> choice;
        player1 = new Player(choice);
        clearFrame();

        int ready = 0;
        while (!ready){
            std::cout << player1->getUsername() << ", is there a pokemon that you want in your team ?\nYou can pick a total of 6 pokemons.\nType 'confirm' when you are done !" << std::endl;
            std::cin >> choice;
            clearFrame();
            choice = stringTolower(choice);

            if (choice == "confirm"){
                ready = 1;
            }
            else {
                pokeToAdd = pokedex->getPokemonByName(choice);
                if (pokeToAdd != nullptr){
                    player1->addPokeToParty(pokeToAdd, MultiPlayerMode);
                }
            }

            count = player1->pokemonParty->getPartySize();

            if (count){
                std::cout << "Your current team is :" << std::endl;
                player1->pokemonParty->displayList();
                std::cout << "\n" << std::endl;
            }
            else {
                std::cout << "Your current team is empty." << std::endl;
            }
        }
        count = player1->pokemonParty->getPartySize();
    }


    if (sel == 2){

        std::cout << "Player 2, what is your name ?" << std::endl;
        std::cin >> choice;
        player2 = new Player(choice);
        clearFrame();

        int ready = 0;
        while (!ready){
            std::cout << player2->getUsername() << ", is there a pokemon that you want in your team ?\nYou can pick a total of 6 pokemons.\nType 'confirm' when you are done !" << std::endl;
            std::cin >> choice;
            clearFrame();
            choice = stringTolower(choice);

            if (choice == "confirm"){
                ready = 1;
            }
            else {
                pokeToAdd = pokedex->getPokemonByName(choice);
                if (pokeToAdd != nullptr){
                    player2->addPokeToParty(pokeToAdd, MultiPlayerMode);
                }
            }

            count = player2->pokemonParty->getPartySize();

            if (count){
                std::cout << "Your current team is :" << std::endl;
                player2->pokemonParty->displayList();
            }
            else {
                std::cout << "Your current team is empty.\n\n" << std::endl;
            }
        }
        count = player2->pokemonParty->getPartySize();
    }
    state = TeamSelection;
    return count;
}

void Game::duel()
{
}

Game::~Game()
{
}
