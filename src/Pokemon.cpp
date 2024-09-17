
#include <string>
#include <iostream>

#include "Pokemon.hpp"


int Pokemon::count = 0;

Pokemon::Pokemon(int id, const string &name, int hitpoint, double attack, double defense, double speed, int gen, int legendary):
name(name), id(id), hitpoint(hitpoint), attack(attack), defense(defense), speed(speed), gen(gen), legendary(legendary), shiny(0) {
    count++;
    srand(time(NULL));
    std::cout << "There are now " << count << " in the universe." << std::endl;
    //use "swith (count)" instead
    }

Pokemon::Pokemon(const Pokemon &anotherPokemon, int isShiny):
name(anotherPokemon.name), id(anotherPokemon.id), hitpoint(anotherPokemon.hitpoint), attack(anotherPokemon.attack), defense(anotherPokemon.defense), gen(anotherPokemon.gen), shiny(isShiny) {
    std::cout << "A new " << name << " was created !\n" << std::endl;
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

void Pokemon::setHP(int newHP){
    hitpoint = newHP;
}


void Pokemon::dealDmg(Pokemon &anotherPokemon){
    if (getHP() == 0){
        std::cout << name << " couldn't move because he is fucking dead !\n" << std::endl;
    }
    else{
        if (anotherPokemon.getHP() == 0) {
            std::cout << name << ", stop " << " ! " << anotherPokemon.name << " is already dead !\n" << "\n" << std::endl;
        }
        else {
            int damage = 10 + getATK() - anotherPokemon.getDEF();
            if (damage > 0){
                anotherPokemon.setHP(anotherPokemon.getHP() - damage);
                std::cout << name << " attacked and inflicted " << damage << " damages to " << anotherPokemon.name << "\n" << std::endl;
                if (anotherPokemon.getHP() < 1) {
                    anotherPokemon.setHP(0);
                    std::cout << anotherPokemon.name << " didn't faint, he fucking died !\n" << std::endl;
                    // delete &anotherPokemon;
                    // deal with the next moves of this pokemon before deleting the instance
                    // for example, wait for an end of turn
                    // A "try and catch" exception doesn't suit this situation
                }
                else {
                    std::cout << anotherPokemon.name << " has " << anotherPokemon.hitpoint << " HP left.\n" << std::endl;
                }
            }
        }
    }
}

void Pokemon::displayName(){
    std::cout << getName() << std::endl;
}

void Pokemon::displayInfo(){
    std::cout << "Name: " << getName() << std::endl;
    std::cout << "ID: " << getId() << std::endl;
    std::cout << "HP: " << getHP() << std::endl;
    std::cout << "Attack: " << getATK() << std::endl;
    std::cout << "Defense: " << getDEF() << std::endl;
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
