#include <iostream>
#include <string.h>
#include <cstdlib>
#include <ctime>

using namespace std;

class Player{
    private:

    public:
        int Hp = 10;

    int RollDice(){
        srand(time(NULL));
        int Number = rand() % 2 + 1;
        return Number;
    }


};

int main(){
    Player Player1;
    int Number = Player1.RollDice();
    cout<< Number << endl ;
}