//
// Created by Jonathan Walsh and Rainey Shah
// Created: 11/04/18
// Latest Update: 11/04/18
//

#include <iostream>
#include <cstdlib>
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;

int main() {
    Deck deck;
    deck.shuffle();

    Player p1 ("Rainey");
    Player p2 ("Jonathan");
    int twoPlayerHandSize = 7;
    for(int i = 0; i < twoPlayerHandSize; i++) {           //deals 7 cards to each player (2-player game)
        p1.addCard(deck.dealCard());
        p2.addCard(deck.dealCard());
    }
    Card c1;
    Card c2;
    while(p1.checkHandForBook(c1, c2)) {
        cout << "From the cards he drew, " << p1.getName() << " books a pair of " << c1.rankString(c1.getRank()) << "'s." << endl;
        p1.bookCards(c1, c2);
    }
    cout << endl;
    while(p2.checkHandForBook(c1, c2)) {
        cout << "From the cards he drew, " << p2.getName() << " books a pair of " << c1.rankString(c1.getRank()) << "'s." << endl;
        p2.bookCards(c1, c2);
    }

    while(deck.size() != 0 && p1.getHandSize() != 0 && p2.getHandSize()){
    
        cout << p1.getName() << "'s hand: " << p1.showHand() << endl;
        c1 = p1.chooseCardFromHand();
        cout << p1.getName() << " asks - Do you have a " << c1.rankString(c1.getRank()) << "?" << endl;
        if(p2.cardInHand(c1)) {
            cout << p2.getName() << " says - Yes. I have a " << c1.rankString(c1.getRank()) << "." << endl;
            p1.addCard(c1);
            p2.removeCardFromHand(c1);
            p1.bookCards(c1, c2);
            cout << p1.getName() << " books his pair of " << c1.rankString(c1.getRank()) << "'s." << endl << endl;
        } else{
            cout << "No, Go Fish." << endl;
            p1.addCard(deck.dealCard());
            cout << p1.getName() << " draws a " << c1.toString() << " and adds it to his hand." << endl << endl;
            if(p1.checkHandForBook(c1, c2)) {
                cout << "From the card he drew, " << p1.getName() << " books a pair of "
                    << c1.rankString(c1.getRank()) << "'s." << endl << endl;
                p1.bookCards(c1, c2);
        }

        c1 = p2.chooseCardFromHand();
        cout << p2.getName() << " asks - Do you have a " << c1.rankString(c1.getRank()) << "?" << endl;
        if(p1.cardInHand(c1)) {
            cout << p1.getName() << " says - Yes. I have a " << c1.rankString(c1.getRank()) << "." << endl;
            p2.addCard(c1);
            p1.removeCardFromHand(c1);
            p2.bookCards(c1, c2);
            cout << p2.getName() << " books his pair of " << c1.rankString(c1.getRank()) << "'s." << endl << endl;
        } else{
            cout << "No, Go Fish." << endl;
            p2.addCard(deck.dealCard());
            cout << p2.getName() << " draws " << c1.toString() << " and adds it to his hand." << endl << endl;
            if(p1.checkHandForBook(c1, c2)) {
                cout << "From the card he drew, " << p1.getName() << " books a pair of "
                    << c1.rankString(c1.getRank()) << "'s." << endl << endl;
                p1.bookCards(c1, c2);
            }
        }
    }

    cout << "The deck is empty. Who is the winner??" << endl << endl;
    cout << p1.getName() << " has " << (p1.getBookSize())/2 << " books. They are " << p1.showBooks() << endl;
    cout << p2.getName() << " has " << (p2.getBookSize())/2 << " books. They are " << p2.showBooks() << endl;
    if(p1.getBookSize() > p2.getBookSize()) {
        cout << p1.getName() << " has more books. Player 1 is the winner!" << endl << endl;
    }else{
        cout << p2.getName() << " has more books. Player 2 is the winner!" << endl << endl;
    }
}

