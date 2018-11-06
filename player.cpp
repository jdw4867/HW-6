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
    int size = getHandSize();
    for(int i = 0; i < (size-1); i++){
        for(int x = i + 1; x < size; x++){
            if(myHand[i] == myHand[x]){
                c1 = myHand[i];
                c2 = myHand[x];
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
    for(int i = 0; i < getHandSize(); i++){
        if (c == myHand[i]) return true;
    }
    return false;
}

Card Player::removeCardFromHand(Card c) {
    for (int i = 0; i < getHandSize(); i++) {
        if (myHand[i] == c) {
            Card temp = myHand[i];
            myHand.erase(myHand.begin() + i);
            return temp;
        }
    }
}

string Player::showHand() const{
    string hand = "";
    int numCards = getHandSize();
    for(int i = 0; i < numCards; i++) {
        hand += myHand[i].toString();
        hand += " ";
    }
    return hand;
}

string Player::showBooks() const {
    string book = "";
    int numCards = getBookSize();
    for (int i = 0; i < numCards; i++) {
        book += myBook[i].toString();
        book += " ";
    }
    return book;
}

int Player::getHandSize() const{
    return myHand.size();
}

int Player::getBookSize() const{
    return myBook.size();
}
