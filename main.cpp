#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include "TestCases.h"
#define  del cin.clear();cin.ignore(100000, '\n');
using namespace std;
int num_columns , sum = 0;
char table[20][26] , check_table[20][26];
int pieces_of_column[26];
string player1, player2;
char valid;
bool isMisere = 0, isValid = 1;

void input_data ();


void setting_table (int num_columns);


void play (int sum);


int main()
{
    while (true){
    system("CLS");{
    input_data();
    setting_table(num_columns);
    play(sum);
    if (valid == 'E' || valid == 'e'){
        cout <<"---------------------------------------------------------\n" << "GOOD BYEEEEEEEEEE!";
        break;
       }
      }
    }
    return 0;
}

void input_data ()
{
    int num_players, version;
        cout << "Choose a version of Nim:"<<endl;
        cout << "\"1\" for Nim or \"2\" for Misere Nim: ";
        cin  >> version;
        if (cin.fail()){
            del
            version = 0;

        }
        version = check_virsion(version);

        if (version == 2){
            isMisere = 1;
        }
        cout << "Choose an option:"<<endl
             << "\"1\" for single player or \"2\" for two players: ";
        cin >> num_players;
        if (cin.fail()){
            del
            num_players = 0;
        }
        num_players = check_players(num_players);
        cout << "Player 1 name: ";
        cin >> player1;
        if(num_players == 2)
        {
            cout << "Player 2 name: ";
            cin >> player2;
            cout<<"Number of columns: ";
            cin>>num_columns;
            if (cin.fail()){
            del
            num_columns = 0;
        }
        num_columns = check_columns(num_columns);
        }
        /*else if (num_players == 1){}*/

}

void setting_table (int num_columns)
{
    char index='A';
    for (int i = 0 ; i < 20 ; i++)
    {
        for (int j = 0 ; j < num_columns ; j++)
        {
            table[i][j] = '.';
            check_table[i][j] = '.';
            cout << table[i][j] << "   ";
        }
        cout << endl;
    }
    for (int i = 1 ; i <= num_columns ; i++ , index++)
    {
        cout << index << "   ";

    }
    cout << endl;
    index = 'A';
    int num_pieces;
    for (int j = 0 ; j < num_columns ; j++)
    {
        cout << "Enter the number of pieces of column "
             << index << ": ";
        cin >> num_pieces;
        if (cin.fail()){
            del
            num_pieces = 0;
        }
        num_pieces = check_pieces(num_pieces);
        sum += num_pieces;
        system("CLS");
        {
            for (int i = 0 ; i < num_pieces ; i++)
            {
                table[i][j]='O';
                pieces_of_column[j]++;
            }
            index++;
        }
        for (int i = 0 ; i < 20 ; i++)
        {
            for (int j=0;  j < num_columns; j++)
            {
                cout << table[i][j] << "   ";
            }
            cout << endl;
        }
        char indexx = 'A';
        for (int i=1; i <= num_columns; i++, indexx++)
        {
            cout << indexx << "   ";
        }
        cout<<endl;
    }
}


void play (int sum)
{
    int turn=1,num_Rpieces,z=0;
    string player_name = player1;
    char index;
    while (true)
    {
        system("CLS");
        {
            system("CLS");
            {
                for (int i=0; i<20; i++)
                {
                    for (int j=0; j<num_columns; j++)
                    {
                        cout << table[i][j] << "   ";
                    }
                    cout << endl;
                }
                char indexx='A';
                for (int i=1; i <= num_columns; i++,indexx++)
                {
                    cout << indexx << "   ";
                }
                cout<<endl;
            }
            if (sum==0)
            {
                system("cls");
                {
                    if (isMisere){
                        if (turn == 1)
                            player_name = player2;
                        else
                            player_name = player1;
                    }
                    cout << "\t\t" <<player_name << " WINS!\n"
                         <<"---------------------------------------------------------\n"
                         << "Press \"N\" for New Game , \"E\" to Exit: ";
                    cin  >> valid;
                    valid = check_contiunity(valid);
                    break;
                }
            }
            cout << player_name << "'s turn:\n"
                 << "Type the index of the column to remove from:";
            cin >> index;
            index = check_index(index, num_columns);
            int column = (index - 'A');
            cout << "How many pieces do you want to remove:";
            cin  >>  num_Rpieces;
            if (cin.fail()){
                del
                num_Rpieces = 0;
            }
            num_Rpieces = check_Rpieces(num_Rpieces, pieces_of_column[column]);
            pieces_of_column[column] -= num_Rpieces;
            for (int i=0; i < 20 && z < num_Rpieces; i++)
            {
                if(table[i][column]=='.')
                {
                    continue;
                }
                else
                {
                    table[i][column]='.';
                    z++;
                }
            }

            z = 0;
            sum -= num_Rpieces;
            if (sum == 0)
                continue;
            if (turn == 1){
                turn = 2;
                player_name = player2;
            }
            else{
                turn = 1;
                player_name = player1;
            }
        }
    }
}
