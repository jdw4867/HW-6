//
// Created by Jonathan Walsh and Rainey Shah
// Created: 11/04/18
// Latest Update: 11/04/18
//

#include "player.h"
#include <ctime>

void Player::addCard(Card c){
    myHand.push_back(c);
}

void Player::bookCards(Card c1, Card c2){
    myBook.push_back(c1);
    myBook.push_back(c2);
    Card booked1 = removeCardFromHand(c1);
    Card booked2 = removeCardFromHand(c2);
}

bool Player::checkHandForBook(Card &c1, Card &c2){
    vector<Card>::const_iterator iter1;
    vector<Card>::const_iterator iter2;

    for(iter1 = myHand.begin(); iter1 != myHand.end()-1; iter1++){
        for(iter2 = iter1+1; iter2 != myHand.end(); iter2++){
            if(*iter1 == *iter2){
                c1 = *iter1;
                c2 = *iter2;
                return true;
            }
        }
    }
    return false;
}

Card Player::chooseCardFromHand() const{
    unsigned int currentTime = (unsigned) time(0);
    srand(currentTime);
    int size = getHandSize();

    int cardIndex;
    cardIndex = rand() % size;

    return myHand[cardIndex];
}

bool Player::cardInHand(Card c) const{
    vector<Card>::const_iterator iter;
    for(iter = myHand.begin(); iter != myHand.end(); iter++){
        if (c == *iter) return true;
    }
    return false;
}

Card Player::removeCardFromHand(Card c) {
    vector<Card>::const_iterator iter;
    int index = 0;
    for (iter = myHand.begin(); iter != myHand.end(); iter++) {
        if (myHand[index] != c) index++;
    }
    Card temp = myHand[index];
    myHand.erase(myHand.begin() + index);
    return temp;
}

string Player::showHand() const{
    string hand = "";
    for(int i = 0; i < getHandSize(); i++) {
        hand += myHand[i].toString();
        hand += " ";
    }
}

string Player::showBooks() const{
    string hand = "";
    for(int i = 0; i < getBookSize(); i++) {
        hand += myBook[i].toString();
        hand += " ";
    }
}

int Player::getHandSize() const{
    return myHand.size();
}

int Player::getBookSize() const{
    return myBook.size();
}
