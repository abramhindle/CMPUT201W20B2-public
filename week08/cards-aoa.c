
#include <stdbool.h> 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

enum card_face {
    ACE = 1,
    FACE2,
    FACE3,
    FACE4,
    FACE5,
    FACE6,
    FACE7,
    FACE8,
    FACE9,
    FACE10,
    JACK,
    QUEEN,
    KING,
};

typedef enum card_face CardFace;

#define NFACES 13
#define NFACEOFF 1

enum card_suit {
    CLUBS,
    HEARTS,
    DIAMONDS,
    SPADES
};

typedef enum card_suit CardSuit;

#define NSUIT 4

struct playing_card {
    CardFace face;
    CardSuit suit;
};

typedef struct playing_card PlayingCard;

#define HANDSIZE 5

bool isFlush(PlayingCard hand[HANDSIZE]) {
    CardSuit suit = hand[0].suit;
    for (int i = 1;  i < HANDSIZE; i++ ) {
        if (suit != hand[i].suit) {
            return false;
        }
    }
    return true;
}

PlayingCard randomCard() {
    PlayingCard card = {ACE, CLUBS};
    card.face = NFACEOFF + ( rand() % NFACES );
    card.suit =  rand() % NSUIT;
    return card;
}

PlayingCard * allocateHand() {
    PlayingCard * hand = malloc(sizeof(PlayingCard[HANDSIZE]));
    assert(hand!=NULL);
    return hand;
}

void randomizeHand( PlayingCard hand[HANDSIZE]) {
    for (int i = 0; i < HANDSIZE; i++) {
        hand[i] = randomCard();
    }
}

int main() {
    srand(time(NULL));
    const int HANDS = 1000000;
    // Pointer to arrays of arrays
    PlayingCard **hands = malloc(sizeof(PlayingCard(*)[5]) * HANDS);
    for (int i = 0; i < HANDS; i++) {
        hands[i] = allocateHand();
        randomizeHand( hands[i] );
    }
    int flushes = 0;
    for (int i = 0; i < HANDS; i++) {
        if (isFlush(hands[i])) {
            if (flushes < 10) { // reduce printing
                printf("Flush found at card %d\n", i);
                printf("Suit %d\n", hands[i][0].suit);
            }
            flushes++;
        }
    }
    printf("We found %d flushes out of %d hands: %f\n", flushes, HANDS, flushes/(float)(HANDS));
    for (int i = 0; i < HANDS; i++) {
        // comment these out to try valgrind
        //free(hands[i]);
    }
    // comment these out to try valgrind
    // free(hands);
}
