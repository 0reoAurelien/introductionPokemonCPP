#include "Game.hpp"
#include "Utility.hpp"
#include "Soundboard.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <thread>


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



int Game::gamemode = 0;
Pokemon* Game::activeEnemy = nullptr;
int Game::running = 0;
int Game::listening = 0;
char Game::asyncInput = EOF;

Game::Game():
state(LoadingGame){
    srand(time(NULL));
}



void background_music(){
    Soundboard* soundboard = Soundboard::getInstance();
    soundboard->playMusic();
}


void Game::play(){
    std::thread audio_thread;
    std::thread inputListener_thread;
    while (state){
        switch (state){
            case LoadingGame:{
                running = true;

                clearFrame();
                
                std::cout << "Welcome to the wonderful world of Pokemon !\n" << std::endl;
                std::cout << "Loading resources...\n" << std::endl;

                Soundboard* soundboard = Soundboard::getInstance();

                player0 = new Player("MainPlayer");

                player1 = new Player("Player1");

                player2 = new Player("Player2");


                pokedex = Pokedex::getInstance();

                std::cout << "Please enter your name to start the game\n" << std::endl;
                
                waitConfirm();
                clearFrame();

                std::cout << "Are you sure that you are not Mr. Tauvel ?\n" << std::endl;
                waitConfirm();
                clearFrame();

                //start multithreading

                audio_thread = std::thread(background_music);
                inputListener_thread = std::thread(inputListener);


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
                Game::running = 0;
                std::cout << "An unexpected error occured." << std::endl;
                inputListener_thread.join();
                audio_thread.join();
                std::cout << "Restart the game ?" << std::endl;
                waitConfirm();
                clearFrame();
                state = MainMenu;
                break;
            }
        }
    }
    Game::running = 0;
    audio_thread.join();
    inputListener_thread.join();
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
                    clearFrame();
                    choice = stringTolower(choice);
                    wrongChoice = 0;
                    if (choice == "confirm"){
                        state = MultiplayerMenu;
                    }
                    else if (choice == "both"){
                        clearFrame();
                        std::cout << "It's Player1's turn to create their team" << std::endl;
                        waitConfirm();
                        bothReady[0] = editPlayer(1);
                        clearFrame();
                        std::cout << "It's now Player2's turn to create their team" << std::endl;
                        waitConfirm();
                        bothReady[1] = editPlayer(2);
                    }
                    else if(choice == "player1"){
                        bothReady[0] = editPlayer(1);
                    }
                    else if(choice == "player2"){
                        bothReady[1] = editPlayer(2);
                    }
                    else {
                        wrongChoice = 1;
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
                bothReady[0] = player1->pokemonParty->getArraySize();
                bothReady[1] = player2->pokemonParty->getArraySize();
                while (bothReady[0]==0){
                    clearFrame();

                    string playerName = player1->getUsername();
                    std::cout << playerName << ", you don't have pokemons !\nDo you want to randomly receive 3 pokemons ? (yes/no)\n" << std::endl;

                    // choix
                    string choice = "";
                    int wrongChoice = 1;
                    while (wrongChoice){
                        std::cin >> choice;
                        if (choice == "yes"){
                            wrongChoice = 0;
                            std::cout << "Ok " << player1->getUsername() << ", let me give you your first pokemons.\n" << std::endl;
                            player1->receiveStarters();
                            bothReady[0] = 3;
                            waitConfirm();
                            clearFrame();
                        }
                        else if (choice == "no"){
                            std::cout << "Then you will need to select at least one pokemon." << std::endl;
                            waitConfirm();
                            bothReady[0] = editPlayer(1);
                            clearFrame();
                            wrongChoice = 0;
                        }
                        else {
                            std::cout << "Please answer (yes/no)\n" << std::endl;
                        }
                    }
                }
                while (bothReady[1]==0){
                    clearFrame();

                    string playerName = player2->getUsername();
                    std::cout << playerName << ", you don't have pokemons !\nDo you want to randomly receive 3 pokemons ? (yes/no)\n" << std::endl;

                    // choix
                    string choice = "";
                    int wrongChoice = 1;
                    while (wrongChoice){
                        std::cin >> choice;
                        if (choice == "yes"){
                            wrongChoice = 0;
                            std::cout << "Ok " << player2->getUsername() << ", let me give you your first pokemons.\n" << std::endl;
                            player2->receiveStarters();
                            bothReady[1] = 3;
                            waitConfirm();
                            clearFrame();
                        }
                        else if (choice == "no"){
                            std::cout << "Then you will need to select at least one pokemon." << std::endl;
                            waitConfirm();
                            bothReady[1] = editPlayer(2);
                            wrongChoice = 0;
                        }
                        else {
                            std::cout << "Please answer (yes/no)\n" << std::endl;
                        }
                    }
                }
                duel();
                state = MultiplayerMenu;
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
    int count;
    Pokemon* pokeToAdd = nullptr;
    string choice = "";
    int ready = 0;

    if (sel == 1){
        std::cout << "Player 1, what is your name ?" << std::endl;
        std::cin >> choice;
        player1->setUsername(choice);

        clearFrame();

        count = player1->pokemonParty->getArraySize();
        if (count){
            std::cout << "Your current team is :" << std::endl;
            player1->pokemonParty->displayList();
            std::cout << "\n" << std::endl;
        }
        else {
            std::cout << "Your current team is empty." << std::endl;
        }

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

            count = player1->pokemonParty->getArraySize();

            if (count){
                std::cout << "Your current team is :" << std::endl;
                player1->pokemonParty->displayList();
                std::cout << "\n" << std::endl;
            }
            else {
                std::cout << "Your current team is empty." << std::endl;
            }
        }
        count = player1->pokemonParty->getArraySize();
    }


    if (sel == 2){

        std::cout << "Player 2, what is your name ?" << std::endl;
        std::cin >> choice;
        player2->setUsername(choice);

        clearFrame();

        count = player2->pokemonParty->getArraySize();
        if (count){
            std::cout << "Your current team is :" << std::endl;
            player2->pokemonParty->displayList();
            std::cout << "\n" << std::endl;
        }
        else {
            std::cout << "Your current team is empty." << std::endl;
        }

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

            count = player2->pokemonParty->getArraySize();

            if (count){
                std::cout << "Your current team is :" << std::endl;
                player2->pokemonParty->displayList();
            }
            else {
                std::cout << "Your current team is empty.\n\n" << std::endl;
            }
        }
        count = player2->pokemonParty->getArraySize();
    }
    state = TeamSelection;
    return count;
}

void Game::duel()
{
    bool duelContinue = true;
    int winner = 0;

    PokemonParty* party1 = player1->pokemonParty;
    Pokemon* p1 = nullptr;
    PokemonParty* party2 = player2->pokemonParty;
    Pokemon* p2 = nullptr;

    string choice = "";

    while (duelContinue){

        if (p1 == nullptr){
            if (party1->getArraySize() == 0){
                duelContinue = false;
                if (p2 == nullptr){
                    break;
                }
                player2->addPokeToParty(p2, MultiPlayerMode);
                winner = 2;
                break;
            }
            else if (party1->getArraySize() == 1){
                p1 = player1->activePokemon();
            }
            else{
                while(p1 == nullptr){
                    std::cout << player1->getUsername() << ", please select your pokemon.\n" << std::endl;
                    party1->displayList();
                    std::cin >> choice;
                    clearFrame();
                    p1 = party1->getPokemonByName(choice);
                }
            }
            clearFrame();
        }

        if (p2 == nullptr){
            if (party2->getArraySize() == 0){
                duelContinue = false;
                if (p1 == nullptr){
                    break;
                }
                player1->addPokeToParty(p1, MultiPlayerMode);
                winner = 1;
                break;
            }
            else if (party2->getArraySize() == 1){
                p2 = player2->activePokemon();
            }
            else{
                while(p2 == nullptr){
                    std::cout << player2->getUsername() << ", please select your pokemon.\n" << std::endl;
                    party2->displayList();
                    std::cin >> choice;
                    p2 = party2->getPokemonByName(choice);
                }
            }
            clearFrame();
        }

        std::cout << player1->getUsername() << " sent a " << p1->getName() << " !\n" << std::endl;
        p1->displayInfo();

        std::cout << player2->getUsername() << " sent a " << p2->getName() << " !\n" << std::endl;
        p2->displayInfo();

        waitConfirm();
        clearFrame();

        while ((p1 != nullptr)&&(p2 != nullptr)){

            if (p1->getSPEED() > p2->getSPEED()){
                p1->dealDmg(p2);
                p2->dealDmg(p1);
            }
            else {
                p2->dealDmg(p1);
                p1->dealDmg(p2);
            }
            waitConfirm();
            clearFrame();

            if (p1->getHP() == 0){
                player1->addPokeToGraveyard(p1, MultiPlayerMode);
                p1 = nullptr;

            }
            if (p2->getHP() == 0){
                player2->addPokeToGraveyard(p2, MultiPlayerMode);
                p2 = nullptr;
            }
        }
    }

    if (winner == 1){
        std::cout << player1->getUsername() << " won the duel !\n" << std::endl;
        waitConfirm();
        if (player1->graveyard->getArraySize()){
            std::cout << "But at what cost..." << std::endl;
            std::cout << player2->getUsername() << " managed to take out the following pokemons:\n" << std::endl;
            player1->graveyard->displayList();
            waitConfirm();
        }
    }
    else if (winner == 2){
        std::cout << player2->getUsername() << " won the duel !\n" << std::endl;
        waitConfirm();
        if (player2->graveyard->getArraySize()){
            std::cout << "But at what cost..." << std::endl;
            std::cout << player1->getUsername() << " managed to take out the following pokemons:\n" << std::endl;
            player2->graveyard->displayList();
            waitConfirm();
        }
    }
    else {
        std::cout << "It's a tie !" << std::endl;
        std::cout << "You have both let all your precious pokemons die !\n" << std::endl;
        waitConfirm();
    }
    
    
    player1->graveyard->empty();
    player2->graveyard->empty();
    //RIP
    
    clearFrame();
}


void background_listening(){
    inputListener();
}

Game::~Game()
{
    delete player0;
    delete player1;
    delete player2;
    delete pokedex;
    std::cout << "\nI hope you enjoyed the game ! Have a nice day !\n\n" << std::endl;
}
