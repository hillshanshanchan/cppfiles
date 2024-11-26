#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
#include <string>
using namespace std;

//Rock Paper Scissor: Try to use class and subclass : 2 players (1 player vs computer) 
//cin for player, rand for computer, if...else if to determine, error detect 


class Player{
    public:
    Player(string playerName): name(playerName){}
    string getName() const{
        return name;
    };
    string getChoice() const{
    return choice;    
    }
    virtual void makeChoice() = 0;
    
    protected:
    string name;
    string choice;
    
    //private:
};

class HumanPlayer : public Player {
    public:
    HumanPlayer(string playerName): Player(playerName){}
    
    
    void makeChoice() override{
    cout<< name << ", please enter your choice(Rock/Paper/Scissors)!"<< endl;
    cin>> choice;
    
    if (choice == "Rock" or "Paper" or "Scissors"){
        cout << "3,2,1!" << endl;
    }
    else {
        cout << "Inapproxiate value, please enter your choice(Rock/Paper/Scissors)!" << endl;
        makeChoice();
    }
    
    }
    
};

class Computer : public Player{
    public:
    Computer ():Player("Computer"){}
    
    void makeChoice() override {
    int randomNumber = rand() % 3;
    
    switch (randomNumber){
        case 0: choice = "Rock"; break;
        case 1: choice = "Paper"; break;
        case 2: choice = "Scissors";break;
    }
    cout<< name << " chose " << choice << endl;
    }
};

string determineWinner(const Player& player1, const Player& player2){
    string choice1 = player1.getChoice();
    string choice2 = player2.getChoice();
    
    if(choice1 == choice2){
        cout << "Tie!" <<endl;
    }else if ((choice1 == "Rock" && choice2 == "Scissors") or 
              (choice1 == "Scissors" && choice2 == "Paper") or 
              (choice1 == "Paper" && choice2 == "Rock")) {
            cout << player1.getName() << ", you win!" << endl;
              }
              else {
            cout << player1.getName() << ", you lose!" << endl;
              }
 return 0;   
}

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    HumanPlayer player1("Shan");
    Computer computer1;
    
    player1.makeChoice();
    computer1.makeChoice();
    
    cout << determineWinner(player1, computer1) << endl;

    return 0;
}
