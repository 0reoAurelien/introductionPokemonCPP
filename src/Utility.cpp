#include "Utility.hpp"
#include "Game.hpp"

#include <string>
#include <vector>
#include <iostream>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <sys/wait.h>
using std::string;
using std::vector;

string stringTolower(const string& str) 
{   
    string newstr = str;
    for(int i = 0; str[i]; i++){
        newstr[i] = tolower(str[i]);
    }
    return newstr;
}

void clearFrame(){
    for (int i=0; i<50; i++)
        std::cout << "\n";
    std::cout << "\033[H\033[J" << std::endl;
}

void waitConfirm(){
    string wait = "";
    std::cin >> wait;
}

int isValidInteger(string userInput){
    if (userInput.size() == 1){
        char integer = userInput[0];
        if ((integer == '1') || (integer == '2') || (integer == '3') || (integer == '4') || (integer == '5') || (integer == '6') || (integer == '7') || (integer == '8') || (integer == '9')){
            return 1;
        }
    }
    return 0;
}


void sortItems(vector<Item *> *liste)
{
}

void sortPokemons(vector<Pokemon *> *liste)
{
}



//-----------------------------------------
//TRIGGER WARNING
//-----------------------------------------

//Les fonctions suivantes sont du Bricolage et peuvent heurter les âmes sensibles



void inputListener(){

    // Change the behavior of the getChar() function so it doesn't wait for newline :
    termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
    fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK);

    char c = EOF;
    char memo = c;
    while(c != 'j'){
        c = getchar();
        if ((c!=EOF)&&(c!=memo)){
            std::cout << "You touched something, didn't you ?" << std::endl;
            //Sound::musicSelector->changeMusic()
            //kill a process
            //Game::asyncInput = c?;
        }
        memo = c;
        usleep(100000);
    }
}

pid_t pid = -1;
pid_t child_pid = -1;
void handle_sigterm(int signum){
    if (child_pid>1){
        kill(child_pid, SIGTERM);
        wait(NULL);
    }
    std::cout << "The process landed successfully" << std::endl;
    exit(0);
}