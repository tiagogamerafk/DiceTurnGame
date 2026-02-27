#include <iostream>
#include <string.h>
#include <cstdlib>
#include <ctime>

using namespace std;

class Entity{
    private:

    public:
        int Hp = 10;

};
int RollDice();
int Defend(int Damage);
void EnemyAttack(bool Defended);
int EnemiesTurn(int Damage, bool Attacked, bool Defended);

Entity Player, Enemy;

int RollDice(){
    int Number = rand() % 2 + 1;
    return Number;
};

int EnemiesTurn(int Damage, bool Attacked, bool Defended){
     int Choice = rand() % 3 + 1;
     if (Choice == 1){
         if (Attacked){
              return Defend(Damage);
         }
         cout << "Both Defended." << endl;
         return 0;
    } else {
            EnemyAttack(Defended);
         return Damage;
    }
};

int Defend(int Damage){
    if(Damage == 2) {
        cout << "Enemy Defended but still got a hit, Damage: " << Damage << endl;
        return Damage - 1;
    } else {
        cout << "Enemy Defended." << endl;
        return 0;
    }
};

void EnemyAttack(bool Defended){
        if (Defended != true){
            int Damage = RollDice();
            cout << "Enemy Attacked, Giving you:" << Damage << " Damage"<< endl;
            Player.Hp -= Damage;
        }
};

int main(){
    srand(time(NULL));
    int FirstChoice = 0, SecondChoice = 0;
    int InitialAttack = 0, FinalAttack = 0;
    bool Defended, Attacked;
    cout<< "----------------" << endl ;
    cout<< "|  [1] Start   |" << endl ;
    cout<< "|  [2] Credits |" << endl ;
    cout<< "|  [3] Exit    |" << endl ;
    cout<< "----------------" << endl ;
    cin >> FirstChoice;
    if (FirstChoice == 1){
        while(SecondChoice != -99){
            Defended = false;
            Attacked = false;
            InitialAttack = 0;
            FinalAttack = 0;
            if (Enemy.Hp <= 0) {
                Enemy.Hp = 0;
                cout << "You Won Congrats!!" << endl;
                return 0;
            }
            if (Player.Hp <= 0) {
                Player.Hp = 0;
                cout << "You Lost, LOL" << endl;
                return 0;
            }
            cout << "Your health:" << Player.Hp << endl;
            cout << "Enemies health:" << Enemy.Hp << endl;
            cout << "Your Turn\n[1] Attack\n[2] Defend\n[-99] Quit" << endl;
            cin >> SecondChoice;
            if (SecondChoice == 1){
                Attacked = true;
                InitialAttack = RollDice();
                FinalAttack = EnemiesTurn(InitialAttack, Attacked, Defended);
                cout << "You attacked, Giving him:" << FinalAttack << " Damage" << endl;
                Enemy.Hp -= FinalAttack;
                Attacked = false;
            } if (SecondChoice == 2){
                Defended = true;
                EnemiesTurn(0, false, Defended);
                Defended = false;

            }
        }
    }
}