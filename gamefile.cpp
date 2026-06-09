#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

const string RED    = "\033[31m";
const string GREEN  = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE   = "\033[34m";
const string CYAN   = "\033[36m";
const string RESET  = "\033[0m";

void clearScreen()
{
    system("clear");
}

void beep()
{
    cout << '\a';
    system("afplay /System/Library/Sounds/Glass.aiff");
}

void drawBoard(){
    cout << RED;
    cout << "====== GUESS THE NUMBER ======\n";
    cout << "RANGE:- [0-999]\n";
    cout << RESET;
    // cout<< CYAN<<
   
}

int main()
{
    srand(time(0));

    int treasureX = rand()%1000;

    int moves = 0;
    
    drawBoard();
    while(true)
    {
        // drawBoard();
        bool flg = false;
        cout<<GREEN<<"moves:- "<< moves<<"\n"; 
        int choice;
        cin >> choice;
        moves++;
        if(moves>11 and (choice!=treasureX)){
            // flg=false;
            cout<<RED<<"YOU LOSE❤️"<<RESET;
        }
        if(choice==treasureX){
            cout<<GREEN<<"YOU WIN"<<RESET;
            clearScreen();
            cout << GREEN;
            cout << "================================\n";
            cout << "       TREASURE FOUND💔!          \n";
            cout << "================================\n";
            cout << RESET;
            
            beep();
            beep();
            beep();
            
            cout << "\nMoves Taken: "
            << moves
            << "\n";
            
            break;
        }else if((choice)<treasureX){
            flg=true;
        }else{
            flg=false;
        }
        beep();
        clearScreen();
        drawBoard();
        if(flg){
            cout<<YELLOW<<"AIM HIGHER\n"<<RESET;
            
        }else{
            cout<<RED<<"AIM LOWER\n"<<RESET;

        }
    }

    return 0;
}