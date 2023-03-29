#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

class Player{
    private: 
    std::string name;

    public:
    //constructor:
    Player(std::string player_name){
       this->name=player_name; 
    }


    //functions:
    int stacksize(){
        return 0;
    }
    int cardesTaken(){
        return 0;
    }

    
    
};