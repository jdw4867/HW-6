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
    int twoPlayerTotalHandSize = 7;
    for(int i = 0; i < twoPlayerTotalHandSize; i++) {           //deals 7 cards to each player (2-player game)
        p1.addCard(deck.dealCard());
        p2.addCard(deck.dealCard());
    }

    while(deck.size() != 0 && p1.getHandSize() != 0 && p2.getHandSize()){
        Card c1;
        Card c2;
        while(p1.checkHandForBook(c1, c2)) p1.bookCards(c1, c2);
        while(p2.checkHandForBook(c1, c2)) p2.bookCards(c1, c2);

        c1 = p1.chooseCardFromHand();
        cout << p1.getName() << "asks - Do you have a " << c1.getRank() << "?" << endl;
        
    }
}









/*
// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;


// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);




int main( )
{
    int numCards = 5;

    Player p1("Joe");
    Player p2("Jane");

    Deck d;  //create a deck of cards
    d.shuffle();

    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);

    cout << p1.getName() <<" has : " << p1.showHand() << endl;
    cout << p2.getName() <<" has : " << p2.showHand() << endl;

    return EXIT_SUCCESS;
}



void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}

*/

