#ifndef TESTCASES_H_INCLUDED
#define TESTCASES_H_INCLUDED
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <math.h>
#include <stdio.h>
#include <string.h>
#define  del cin.clear();cin.ignore(100000, '\n');
using namespace std;

int check_virsion (int version){
    if (version == 1 || version == 2)
        return version;
if ( version != 1 && version != 2 ){
cout << " Ops! Invalid input .. please enter 1 or 2 only: ";
cin >> version ;
if (cin.fail()){
        del
        version = -1;
        }
check_virsion(version);
 }
}


int check_columns (int num_columns){
    if (num_columns < 26 && num_columns != 0)
        return num_columns;
if ( num_columns > 26 || num_columns == 0)
{
cout << " Ops! Invalid input .. Number of columns must be from 1 to 26 ." << endl
     << " Please re-enter the number of columns: ";
cin >> num_columns;
if (cin.fail()){
            del
            num_columns = 0;
        }
check_columns(num_columns);
}
}
/**/


int check_players(int num_players){
    if (num_players == 2 || num_players == 1)
        return num_players;
if ( num_players !=1 && num_players!=2 )
{
cout << " Ops! Invalid input .. please enter 1 or 2 only: ";
cin >> num_players;
if (cin.fail()){
            del
            num_players = 0;
        }
check_players(num_players);
   }
}


int check_pieces (int num_pieces){
    if (num_pieces < 20 && num_pieces != 0)
        return num_pieces;
if ( num_pieces > 20 || num_pieces == 0 )
{
cout << " Ops! Invalid input .. Number of pieces must from 1 to 20 ." << endl
     << " Please re-enter the number of pieces: ";
cin >> num_pieces;
if (cin.fail()){
            del
            num_pieces = 0;
        }
check_pieces(num_pieces);
}
}


char check_index (char index, int num_columns){
    char last_column = 64 + num_columns;
    if (index >= 'A' && index <= 'Z' || index >= 'a' && index <= 'z')
        return toupper(index);
    else {
        cout << " Ops! Invalid input .. The index must be a letter from A to "
            << last_column << "(uppercase or lowercase)" << endl
            << " Please re-enter the index: " ;
        cin >> index;
        check_index(index, num_columns);
    }

}
int check_Rpieces (int Rpieces, int pieces_of_column){
    if (Rpieces <= pieces_of_column && Rpieces !=0)
        return Rpieces;
    else {
        if (pieces_of_column == 1){
            cout << " Ops! Invalid input .. The number of removed pieces must be from 1"
                 << " Please re-enter the number of removed pieces: ";
        }
        else if (pieces_of_column == 2){
            cout << " Ops! Invalid input .. The number of removed pieces must be from 1 or 2 "
                 << " Please re-enter the number of removed pieces: ";
        }
        else {
        cout << " Ops! Invalid input .. The number of removed pieces must be from 1 to "
             << pieces_of_column
             << " Please enter the number of removed pieces again: ";
        }
        cin >> Rpieces;
        if (cin.fail()){
                del
                Rpieces = 0;
            }
        check_Rpieces(Rpieces, pieces_of_column);
    }
}
char check_contiunity (char valid){
    if (valid == 'N' || valid == 'n' || valid == 'E' || valid == 'e')
        return valid;
    else {
        cout << " Ops! Invalid input .. You should enter only N or E: ";
        cin >> valid;
        check_contiunity(valid);
    }

}
#endif // TESTCASES_H_INCLUDED
