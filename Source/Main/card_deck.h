/********************************************************************************
* Filename    : 

* Author      : Parth Bhatt

* Date        : 

* Description : 

********************************************************************************/

#ifndef __CARD_DECK_H__
#define __CARD_DECK_H__

/*******************************************************************************
* Include Files
********************************************************************************/
#include <stdint.h>
#include <stdbool.h>

/*******************************************************************************
* Constants and macros
********************************************************************************/

/*******************************************************************************
* Data types
********************************************************************************/
typedef enum{
    CARD_SHAPE_HEART,      // ♥
    CARD_SHAPE_SPADE,      // ♠
    CARD_SHAPE_CLUB,       // ♣
    CARD_SHAPE_DIAMOND,    // ♦
    CARD_SHAPE_COUNT,
} CardShape_t;

typedef struct{
    CardShape_t Shape;
    uint8_t     Number;
} CardType_t;

typedef enum{
	DECK_STATUS_MISSING_CARDS,
	DECK_STATUS_DUPLICATE_CARDS,
	DECK_STATUS_OK,
	DECK_STATUS_UNKNOWN,
} DeckStatus_t;

/*******************************************************************************
* Global Variables
********************************************************************************/


/*******************************************************************************
* Functions
********************************************************************************/
void CardDeck_Init();
bool CardDeck_Shuffle();
bool CardDeck_GetNextCard(CardType_t* cardVal);
bool CardDeck_PutCardBack();
DeckStatus_t CardDeck_Validate();
char CardDeck_GetShape(CardType_t card);
char CardDeck_GetVal(CardType_t card);

#endif
