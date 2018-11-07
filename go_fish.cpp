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

    Player p1("Rainey");
    Player p2("Jonathan");
    int twoPlayerHandSize = 7;
    for (int i = 0; i < twoPlayerHandSize; i++) {           //deals 7 cards to each player (2-player game)
        p1.addCard(deck.dealCard());
        p2.addCard(deck.dealCard());
    }
    Card c1;
    Card c2;
    while (p1.checkHandForBook(c1, c2)) {
        p1.bookCards(c1, c2);
        cout << "From the cards he drew, " << p1.getName() << " books a pair of " << c1.rankString(c1.getRank())
             << "'s. (" << p1.getBookSize()/2 << ")" << endl;
    }
    cout << p1.getName() << "'s hand: " << p1.showHand() << endl << endl;
                                                                                //draw cards and book pairs if possible
    while (p2.checkHandForBook(c1, c2)) {
        p2.bookCards(c1, c2);
        cout << "From the cards he drew, " << p2.getName() << " books a pair of " << c1.rankString(c1.getRank())
             << "'s. (" << p2.getBookSize()/2 << ")" << endl;
    }
    cout << p2.getName() << "'s hand: " << p2.showHand() << endl << endl;

    bool successfulFish = true;
    while (deck.size() != 0 && p1.getHandSize() != 0 && p2.getHandSize() != 0) {             //even if all cards are dealt, there might be cards in players hands to ask for
        while (successfulFish) {
            successfulFish = true;
            cout << p1.getName() << "'s hand: " << p1.showHand() << endl;
            c1 = p1.chooseCardFromHand();
            cout << p1.getName() << " asks - Do you have a " << c1.rankString(c1.getRank()) << "?" << endl;
            if (p2.cardInHand(c1)) {
                successfulFish = true;
                cout << p2.getName() << " says - Yes. I have a " << c1.rankString(c1.getRank()) << "." << endl;
                p1.addCard(c1);
                p1.bookCards(c1, c2);
                p2.removeCardFromHand(c1);

                cout << p1.getName() << " books his pair of " << c1.rankString(c1.getRank()) << "'s. (" << p1.getBookSize()/2 << ")" << endl;
                cout << p1.getName() << "'s hand: " << p1.showHand() << endl << endl;

            } else {
                successfulFish = false;
                cout << p2.getName() << " says - Go Fish." << endl;                                                     //this whole section is player 1
                if(deck.size() != 0) {
                    c1 = deck.dealCard();
                    p1.addCard(c1);
                    cout << p1.getName() << " draws a " << c1.toString() << " and adds it to his hand." << endl;
                    if (p1.checkHandForBook(c1, c2)) {
                        p1.bookCards(c1, c2);
                        cout << "From the card he drew, " << p1.getName() << " books a pair of "
                             << c1.rankString(c1.getRank()) << "'s. (" << p1.getBookSize() / 2 << ")" << endl;
                    }
                    cout << p1.getName() << "'s hand: " << p1.showHand() << endl << endl;

                } else cout << "The deck is empty, so no card is drawn." << endl << endl;
            }
        }
        successfulFish = true;
        while (successfulFish) {
            successfulFish = true;
            cout << p2.getName() << "'s hand: " << p2.showHand() << endl;
            c1 = p2.chooseCardFromHand();
            cout << p2.getName() << " asks - Do you have a " << c1.rankString(c1.getRank()) << "?" << endl;
            if (p1.cardInHand(c1)) {
                successfulFish = true;
                cout << p1.getName() << " says - Yes. I have a " << c1.rankString(c1.getRank()) << "." << endl;
                p2.addCard(c1);
                p2.bookCards(c1, c2);
                p1.removeCardFromHand(c1);
                cout << p2.getName() << " books his pair of " << c1.rankString(c1.getRank()) << "'s. (" << p2.getBookSize()/2 << ")" << endl;
                cout << p2.getName() << "'s hand: " << p2.showHand() << endl << endl;
            } else {
                successfulFish = false;
                cout << p1.getName() << " says - Go Fish." << endl;
                if (deck.size() != 0) {
                    c1 = deck.dealCard();                                                                   //this whole section is player 2
                    p2.addCard(c1);
                    cout << p2.getName() << " draws " << c1.toString() << " and adds it to his hand." << endl;
                    if (p2.checkHandForBook(c1, c2)) {
                        p2.bookCards(c1, c2);
                        cout << "From the card he drew, " << p2.getName() << " books a pair of "
                             << c1.rankString(c1.getRank()) << "'s. (" << p2.getBookSize() / 2 << ")" << endl;
                    }
                    cout << p2.getName() << "'s hand: " << p2.showHand() << endl << endl;
                }else cout << "The deck is empty, so no card is drawn." << endl << endl;
            }
        }
        successfulFish = true;
    }

    cout << "The deck is empty. Who won??" << endl << endl;
    cout << p1.getName() << " has " << p1.getBookSize() / 2 << " books." << endl << "They are " << p1.showBooks() << endl << endl;
    cout << p2.getName() << " has " << p2.getBookSize() / 2 << " books." << endl << "They are " << p2.showBooks() << endl << endl;
    if (p1.getBookSize() > p2.getBookSize()) {
        cout << p1.getName() << " has more books. Player 1 is the winner!" << endl;
    } else {                                                                                    //determine who won the game
        cout << p2.getName() << " has more books. Player 2 is the winner!" << endl;
    }
}

