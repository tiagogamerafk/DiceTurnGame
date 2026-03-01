#include <iostream>
#include <string.h>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <stdlib.h>

using namespace std;

class Entity{
    private:

    public:
        int Hp = 10;

};

Entity Player, Enemy;

int RollDice(){
    int Number = rand() % 2 + 1;
    return Number;
};

int EnemiesChoice(){
    int Choice = rand() % 3 + 1;
    return Choice;
}

int main(){
    srand(time(NULL));
    int FirstChoice = 0, SecondChoice = 0;
    int DiceNumber, PlayerDamage, EnemiesDamage, EnemyChoice;
    while (FirstChoice != 3){
    cout<< "==================" << endl;
    cout<< "|   [1] Start    |" << endl;
    cout<< "|   [2] Credits  |" << endl;
    cout<< "|   [3] Exit     |" << endl;
    cout<< "==================" << endl;
    cin >> FirstChoice;
    
        if (FirstChoice == 1){
            while(SecondChoice != -99){
                DiceNumber = 0;
                PlayerDamage = 0;
                EnemiesDamage = 0;
                if (Enemy.Hp <= 0) {
                    Enemy.Hp = 0;
                    cout << "Players Health = " << Player.Hp <<"\nEnemies Health: 0 \nEnemy Died\nYou Won Congrats!!" << endl;
                    return 0;
                }   
                if (Player.Hp <= 0) {
                    Player.Hp = 0;
                    cout << "Enemies Health = " << Enemy.Hp <<"\nYour Health: 0 \nEnemy Attacks and everything goes black\nYou Lost." << endl;
                    return 0;
                }
                cout << "=============\nPlayers Health:" << Player.Hp << endl;
                cout << "Enemies Health:" << Enemy.Hp << "\n=============" << endl;
                cout << "Your Turn\n[1] Attack\n[2] Defend\n[-99] Quit" << endl;
                cin >> SecondChoice;
                cout << "\n\n\n\n\n\n\n" << endl;
                EnemyChoice = EnemiesChoice();
                if (SecondChoice == 1){
                    DiceNumber = RollDice();
                    if (EnemyChoice == 1){
                        cout << "You chose: Attack\nEnemy Chose: Defend" << endl;
                        PlayerDamage = DiceNumber - 1;
                        if (PlayerDamage == 1){
                            cout << "Enemy Defended but still took some damage." << endl;
                            Enemy.Hp -= PlayerDamage;
                        } else {
                            cout << "Enemy Defended taking 0 damage." << endl;
                        }
                    } else{
                        EnemiesDamage = RollDice();
                        cout << "You chose: Attack\nEnemy Chose: Attack" << endl;
                        cout << "You attacked, Giving him: " << DiceNumber << " Damage" << endl;
                        Enemy.Hp -= DiceNumber;
                        cout << "He attacked you, Giving you: " << EnemiesDamage << " Damage" << endl; 
                        Player.Hp -= EnemiesDamage;
                    }
                } if (SecondChoice == 2){
                    if (EnemyChoice == 1){
                        cout << "You chose: Defend\nEnemy Chose: Defend" << endl;
                        cout << "Both Defended." << endl;
                    } else{
                        EnemiesDamage = RollDice();
                        cout << "You chose: Defend\nEnemy Chose: Attack" << endl;
                        EnemiesDamage = EnemiesDamage - 1;
                        if (EnemiesDamage == 1){
                            cout << "You Defended but still took some damage." << endl;
                            Player.Hp -= EnemiesDamage;
                        } else {
                            cout << "You Defended taking 0 damage." << endl;
                        }
                    }
                }
            }
        } if (FirstChoice == 2){
            cout << "==================================================" << endl;
            cout << "This game was made entirely by Tiago Pereira.\nSpecial thanks to: \n -Paulo Barreira my programming teacher\n -Paulo Santos my programming teacher\n -My parents for all the sacrifices they made for me." << endl;
            cout << "==================================================" << endl;
            cout << "Press anything to go back to the menu" << endl;
            getch();

        } else {
            cout << "Game exited sucessfully" <<endl;
            return 0;
        }
    }
}