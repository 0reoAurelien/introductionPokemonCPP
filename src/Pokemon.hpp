
#include <string>
#include <iostream>


using std::string;

class Pokemon{
    private:
    int id;
    string name;
    int hitpoint;
    double attack;
    double defense;
    int gen;
    static int count;


    public:
    Pokemon(int id, const string &name, int hitpoint, double attack, double defense, int gen);
    Pokemon(const Pokemon &anotherPokemon);

    int getATK() const;
    int getDEF() const;
    int getHP() const;
    string getName() const;
    void setHP(int newHP);
    void dealDmg(Pokemon &anotherPokemon);
    void displayInfo();

    ~Pokemon();
};