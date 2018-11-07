//
// Created by Jonathan Walsh and Rainey Shah
// Created: 11/04/18
// Latest Update: 11/04/18
//

#include "card.h"
#include <iostream>
#include <cstdlib>

Card::Card(){
    mySuit = spades;            //default card is Ace of Spades
    myRank = 1;
}

Card::Card(int rank, Suit s){
    mySuit = s;
    myRank = rank;
}

int Card::getRank() const {
    return myRank;
}

string Card::suitString(Card::Suit s) const {
    string convertedSuit;
    enum Suit {spades, hearts, diamonds, clubs};
    switch(s){
        case spades:
            convertedSuit = "s";
            break;
        case hearts:
            convertedSuit = "h";            //changes enumerated type to shorthand for printing
            break;
        case diamonds:
            convertedSuit = "d";
            break;
        case clubs:
            convertedSuit = "c";
            break;
    }
    return convertedSuit;
}

string Card::rankString(int r) const {
    string convertedRank = "error";
    if(r == 1) convertedRank = "A";
    else if (r == 2) convertedRank = "2";
    else if (r == 3) convertedRank = "3";
    else if (r == 4) convertedRank = "4";
    else if (r == 5) convertedRank = "5";
    else if (r == 6) convertedRank = "6";
    else if (r == 7) convertedRank = "7";
    else if (r == 8) convertedRank = "8";
    else if (r == 9) convertedRank = "9";
    else if (r == 10) convertedRank = "10";
    else if (r == 11) convertedRank = "J";
    else if (r == 12) convertedRank = "Q";
    else if (r == 13) convertedRank = "K";
    return convertedRank;
}

string Card::toString() const {
    string converted = "";
    converted += rankString(myRank);        //first puts rank in the concatenated string
    converted += suitString(mySuit);        //second puts suit in the concatenated string
    return(converted);
}

bool Card::sameSuitAs(const Card &c) const {
    if(c.mySuit == mySuit) return true;             //I don't think we'll ever use this function, but its here to create transferable code
    else return false;                              //for simulating multiple types of card games
}

bool Card::operator==(const Card &rhs) const {
    if(myRank == rhs.myRank) return true;           //in GoFish, only a matching rank is important
    else return false;                              //if I checked suit as well, no card would ever be equal to another
}

bool Card::operator!=(const Card &rhs) const {
    if(myRank != rhs.myRank) return true;
    else return false;
}

ostream& operator << (ostream& out, const Card& c){
    cout << c.toString();                       //prints out the concatenated string of rank + suit
    return out;
}
