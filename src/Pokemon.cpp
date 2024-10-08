
#include <string>
#include <iostream>

#include "Pokemon.hpp"


int Pokemon::count = 0;

Pokemon::Pokemon(int id, const string &name, int hitpoint, double attack, double defense, double speed, int gen, int legendary):
name(name), id(id), hitpoint(hitpoint), attack(attack), defense(defense), speed(speed), gen(gen), legendary(legendary), shiny(0) {
    count++;
    srand(time(NULL));
    //std::cout << "There are now " << count << " pokemons in the universe." << std::endl;
    //use "swith (count)" instead
    }

Pokemon::Pokemon(const Pokemon &anotherPokemon, int isShiny):
name(anotherPokemon.name), id(anotherPokemon.id), hitpoint(anotherPokemon.hitpoint), attack(anotherPokemon.attack), defense(anotherPokemon.defense), speed(anotherPokemon.speed), gen(anotherPokemon.gen), legendary(anotherPokemon.legendary), shiny(isShiny) {
    count++;
    string shinyPrefix = (isShiny)? "Shiny " : ""; 
    std::cout << "A new " << shinyPrefix << name << " was created !\n" << std::endl;
}


string Pokemon::getName() const{
    return name;
}

int Pokemon::getId() const{
    return id;
}

int Pokemon::getATK() const{
    return attack;
}

int Pokemon::getDEF() const{
    return defense;
}

int Pokemon::getSPEED() const{
    return speed;
}

int Pokemon::getHP() const{
    return hitpoint;
}

int Pokemon::isLegendary() const
{
    return legendary;
}

void Pokemon::setFree(int freeToCatch)
{
    taken = !freeToCatch;
}

int Pokemon::isTaken()
{
    return taken;
}

int Pokemon::isShiny() const
{
    return shiny;
}

void Pokemon::setHP(int newHP){
    hitpoint = newHP;
}

void Pokemon::setATK(int newATK){
    attack = newATK;
}

void Pokemon::setDEF(int newDEF){
    defense = newDEF;
}

void Pokemon::setSpeed(int newSpeed){
    speed = newSpeed;
}


void Pokemon::dealDmg(Pokemon * anotherPokemon){
    if (getHP() == 0){
        std::cout << name << " cannot move because he is fucking dead !\n" << std::endl;
    }
    else{
        if (anotherPokemon->getHP() == 0) {
            std::cout << name << ", stop ! " << anotherPokemon->name << " is already dead !\n" << "\n" << std::endl;
        }
        else {
            int damage = 3 + (getATK() + getDEF() - anotherPokemon->getDEF())/3;
            if (damage > 0){
                anotherPokemon->setHP(anotherPokemon->getHP() - damage);
                std::cout << name << " attacked and inflicted " << damage << " damages to " << anotherPokemon->getName() << "\n" << std::endl;
                if (anotherPokemon->getHP() < 1) {
                    anotherPokemon->setHP(0);
                    std::cout << anotherPokemon->getName() << " didn't faint, he fucking died !\n" << std::endl;
                    // delete &anotherPokemon;
                    // deal with the next moves of this pokemon before deleting the instance
                    // for example, wait for an end of turn
                    // A "try and catch" exception doesn't suit this situation
                }
                else {
                    std::cout << anotherPokemon->getName() << " has " << anotherPokemon->getHP() << " HP left.\n" << std::endl;
                }
            }
            else {
                std::cout << getName() << " couldn't deal any damage to " << anotherPokemon->getName() << ".\n\n" << std::endl;
            }
        }
    }
}

void Pokemon::displayName(){
    string shinyPrefix = (shiny)?"Shiny ":"";
    std::cout << shinyPrefix << getName() << std::endl;
}

void Pokemon::displayInfo(){
    std::cout << "Name: " << getName() << std::endl;
    std::cout << "ID: " << getId() << std::endl;
    std::cout << "HP: " << getHP() << std::endl;
    std::cout << "Attack: " << getATK() << std::endl;
    std::cout << "Defense: " << getDEF() << std::endl;
    std::cout << "Speed: " << getSPEED() << std::endl;
    std::cout << "Generation: " << gen << std::endl;

    if (legendary){std::cout << "This is a legendary pokemon !" << std::endl;}
    if (shiny){std::cout << "This " << getName() << " is shiny !" << std::endl;}

    std::cout << "\n" << std::endl;
}

int Pokemon::capture(int catchRate)
{
    int attempt = rand()%100;
    return (attempt > catchRate);
}

Pokemon::~Pokemon(){
    count--;
    std::cout << "Destruction of " << name << std::endl;
    switch (count) {
        case 1 :
            std::cout << "There is now 1 pokemon in the universe.\n" << std::endl;
            break;

        case 0 :
            std::cout << "The universe is empty !\n" << std::endl;
            break;


        default :
            std::cout << "There are now " << count << " pokemons in the universe.\n" << std::endl;
    }
}
