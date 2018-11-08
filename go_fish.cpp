//
// Created by Jonathan Walsh and Rainey Shah
// Created: 11/04/18
// Latest Update: 11/08/18
//
//This driver cycles between two players playing GoFish. 7 cards are initially drawn, and one player asks the other for a card that they themselves have.
//If the other player has it, they turn it over, and the asker may ask for another card they have. Otherwise, they "go fish" from the deck, and draw a card.
//At any point, if you have two of the same rank card in your hand, you remove the two cards as a "book". The player at the end of the game, when the hands
//and deck are empty, with the most books wins.

#include <iostream>
#include <cstdlib>
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;

int main() {
    Deck deck;
    deck.shuffle();
    freopen("gofish_results.txt", "w", stdout);

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
    while (deck.size() != 0 && (p1.getBookSize() + p2.getBookSize()) != 52) {             //even if all cards are dealt, there might be cards in players hands to ask for
        while (successfulFish) {
            successfulFish = true;
            if(p1.getHandSize() == 0 && deck.size() != 0) {
                c1 = deck.dealCard();                                                       //adds card if hand empty because of opponent asking for cards
                p1.addCard(c1);
                cout << p1.getName() << " draws a " << c1.toString() << " and adds it to his hand." << endl;
            }
            if(p1.getHandSize() != 0) {
                cout << p1.getName() << "'s hand: " << p1.showHand() << endl;                   //otherwise proceed as normal
                if (p1.getHandSize() > 0) c1 = p1.chooseCardFromHand();
                cout << p1.getName() << " asks - Do you have a " << c1.rankString(c1.getRank()) << "?" << endl;
                if (p2.cardInHand(c1)) {
                    successfulFish = true;
                    cout << p2.getName() << " says - Yes. I have a " << c1.rankString(c1.getRank()) << "." << endl;
                    c1 = p2.removeCardFromHand(c1);
                    p1.addCard(c1);                                                //procedure if opponent has card you asked for
                    p1.checkHandForBook(c1, c2);
                    p1.bookCards(c1, c2);
                    cout << p1.getName() << " books his pair of " << c1.rankString(c1.getRank()) << "'s. ("
                         << p1.getBookSize() / 2 << ")" << endl;
                    if (p1.getHandSize() == 0 && deck.size() != 0) {
                        c1 = deck.dealCard();
                        p1.addCard(c1);                                             //if hand now empty, add card to your hand from deck
                        cout << p1.getName() << " draws a " << c1.toString() << " and adds it to his hand." << endl;
                    }
                    cout << p1.getName() << "'s hand: " << p1.showHand() << endl << endl;
                } else {
                    successfulFish = false;
                    cout << p2.getName() << " says - Go Fish." << endl;           //GoFish...draw card from deck if it is not empty
                    if (deck.size() != 0) {
                        c1 = deck.dealCard();
                        p1.addCard(c1);
                        cout << p1.getName() << " draws a " << c1.toString() << " and adds it to his hand." << endl;
                        if (p1.checkHandForBook(c1, c2)) {
                            p1.bookCards(c1, c2);                                           //if card you drew from deck makes a pair, book it
                            cout << "From the card he drew, " << p1.getName() << " books a pair of "
                                 << c1.rankString(c1.getRank()) << "'s. (" << p1.getBookSize() / 2 << ")" << endl;
                            if (p1.getHandSize() == 0 && deck.size() != 0) {
                                c1 = deck.dealCard();             //if hand now empty, draw again from deck (still trying to pass turn to opponent)
                                p1.addCard(c1);
                                cout << p1.getName() << " draws a " << c1.toString() << " and adds it to his hand."
                                     << endl;
                            }
                        }
                        cout << p1.getName() << "'s hand: " << p1.showHand() << endl << endl;

                    } else cout << "The deck is empty, so no card is drawn." << endl << endl;
                }
            }else successfulFish = false;                   //break out of loop if game is over (hands && deck == 0)
        }
        successfulFish = true;
        while (successfulFish) {                    //SWITCHING TO PLAYER TWO, BASICALLY A COPY OF PREVIOUS ROUTINE FOR PLAYER ONE
            successfulFish = true;
            if (p2.getHandSize() == 0 && deck.size() != 0) {
                c1 = deck.dealCard();                                       //adds card if hand empty because of opponent asking for cards
                p2.addCard(c1);
                cout << p2.getName() << " draws a " << c1.toString() << " and adds it to his hand." << endl;
            }
            if(p2.getHandSize() != 0) {                                             //otherwise proceed as normal
                cout << p2.getName() << "'s hand: " << p2.showHand() << endl;
                if (p2.getHandSize() > 0) c1 = p2.chooseCardFromHand();
                cout << p2.getName() << " asks - Do you have a " << c1.rankString(c1.getRank()) << "?" << endl;
                if (p1.cardInHand(c1)) {
                    successfulFish = true;
                    cout << p1.getName() << " says - Yes. I have a " << c1.rankString(c1.getRank()) << "." << endl;
                    c1 = p1.removeCardFromHand(c1);
                    p2.addCard(c1);                                                         //procedure if opponent has card you asked for
                    p2.checkHandForBook(c1, c2);
                    p2.bookCards(c1, c2);
                    cout << p2.getName() << " books his pair of " << c1.rankString(c1.getRank()) << "'s. ("
                         << p2.getBookSize() / 2 << ")" << endl;
                    if (p2.getHandSize() == 0 && deck.size() != 0) {
                        c1 = deck.dealCard();                                       //if hand now empty from booking, draw card from deck
                        p2.addCard(c1);
                        cout << p2.getName() << " draws a " << c1.toString() << " and adds it to his hand." << endl;
                    }
                    cout << p2.getName() << "'s hand: " << p2.showHand() << endl << endl;
                } else {
                    successfulFish = false;
                    cout << p1.getName() << " says - Go Fish." << endl;
                    if (deck.size() != 0) {
                        c1 = deck.dealCard();                                                   //GoFish...draw card from deck if not empty
                        p2.addCard(c1);
                        cout << p2.getName() << " draws " << c1.toString() << " and adds it to his hand." << endl;
                        if (p2.checkHandForBook(c1, c2)) {
                            p2.bookCards(c1, c2);                               //if card you drew from deck makes a pair, book it
                            cout << "From the card he drew, " << p2.getName() << " books a pair of "
                                 << c1.rankString(c1.getRank()) << "'s. (" << p2.getBookSize() / 2 << ")" << endl;
                            if (p2.getHandSize() == 0 && deck.size() != 0) {
                                c1 = deck.dealCard();                   //if hand now empty, draw again from deck (still trying to pass turn to opponent)
                                p2.addCard(c1);
                                cout << p2.getName() << " draws a " << c1.toString() << " and adds it to his hand."
                                     << endl;
                            }
                        }
                        cout << p2.getName() << "'s hand: " << p2.showHand() << endl << endl;
                    } else cout << "The deck is empty, so no card is drawn." << endl << endl;
                }
            } else successfulFish = false;
        }
        successfulFish = true;              //break out of loop if game is over (hands && deck == 0)
    }

    cout << "The deck is empty. Who won??" << endl << endl;
    cout << p1.getName() << " has " << p1.getBookSize() / 2 << " books." << endl << "They are " << p1.showBooks() << endl << endl;
    cout << p2.getName() << " has " << p2.getBookSize() / 2 << " books." << endl << "They are " << p2.showBooks() << endl << endl;
    if (p1.getBookSize() > p2.getBookSize()) {
        cout << p1.getName() << " has more books. " << p1.getName() << " is the winner!" << endl;
    } else if (p1.getBookSize() < p2.getBookSize()){                                                              //determine who won the game
        cout << p2.getName() << " has more books. " << p2.getName() << " is the winner!" << endl;
    }else if (p1.getBookSize() == p2.getBookSize()){
        cout << p1.getName() << " and " << p2.getName() << " have the same number of books. The game is a tie!" << endl;
    }
}

