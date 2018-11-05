//
// Created by Jonathan Walsh and Rainey Shah
// Created: 11/04/18
// Latest Update: 11/04/18
//

#include "deck.h"
#include <ctime>
#include <cstdlib>


Deck::Deck() {
    myIndex = 0;
    Card::Suit cardSuit = Card::clubs;                      //four "for" loops, one for each of the suits
    for (int rank = 1; rank < 14; rank++) {                          //The myIndex value increments array index of deck of where
        myCards[myIndex] = Card(rank, cardSuit);               //the card is going. It is reset at the end of the function to 0, the first card.
        myIndex++;
    }
    cardSuit = Card::diamonds;
    for (int rank = 1; rank < 14; rank++) {
        myCards[myIndex] = Card(rank, cardSuit);
        myIndex++;
    }
    cardSuit = Card::hearts;
    for (int rank = 1; rank < 14; rank++) {
        myCards[myIndex] = Card(rank, cardSuit);
        myIndex++;                                  //have to keep re-defining "rank" because code exits the for loop
    }
    cardSuit = Card::spades;
    for (int rank = 1; rank < 14; rank++) {
        myCards[myIndex] = Card(rank, cardSuit);
        myIndex++;
    }
    myIndex = 0;
}

void Deck::shuffle() {
    myIndex = 0;
    int card1Ind = 0;
    int card2Ind = 0;

    unsigned int currentTime = (unsigned) time(0);
    srand(currentTime);

    for(int i = 0; i < SIZE; i++){
        card1Ind = rand() % SIZE;               // No plus 1 like in previous lab, which would get you values between 1-52
        card2Ind = rand() % SIZE;               // You want values 0-51, because array index of 52 cards goes from 0-51

        Card temp = myCards[card1Ind];
        myCards[card1Ind] = myCards[card2Ind];      //swaps cards at the two random card index spots, and repeats the process SIZE (52) times
        myCards[card2Ind] = temp;
    }
}

Card Deck::dealCard() {
    if(myIndex < 52){
        myIndex++;                          //moves myIndex value, so the next card dealt will be the card after
        return myCards[myIndex];
    } else {
        EXIT_SUCCESS;
    }
}

int Deck::size() const {
    return (SIZE - myIndex);            //myIndex will only be 52 when there are 0 cards left, meaning this is accurate
}