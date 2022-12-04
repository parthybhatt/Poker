
/********************************************************************************
* Filename    : 

* Author      : Parth Bhatt

* Date        : 

* Description : 

********************************************************************************/

/*******************************************************************************
* Include Files
********************************************************************************/
#include "card_deck.h"
#include "circular_buffer.h"
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

/*******************************************************************************
* Constants and macros
********************************************************************************/
#define MAX_CARDS_IN_DECK   52
#define MAX_CARD_OF_SHAPE   13

/*******************************************************************************
* Data types (Structs, enum)
********************************************************************************/

/*******************************************************************************
* Static Variables
********************************************************************************/
// TODO: Change this array into a circular buffer*****
static CardType_t   CardDeck[MAX_CARDS_IN_DECK];
static CircularBufferStruct_t CardsCircularBuffer;

/*******************************************************************************
* Static Functions Declaration
********************************************************************************/
static void CreateNewDeck(CircularBufferStruct_t* cardsBuffer);
static bool ValidateDeck(CardType_t* cards, CardType_t missingCards);
static void SwapCards(CardType_t* cardA, CardType_t* cardB);
static uint8_t GetRandomInRange(uint8_t numA, uint8_t numB);

/*******************************************************************************
* Public Functions
********************************************************************************/
void CardDeck_Init()
{
    CircularBuffer_Init(&CardsCircularBuffer, CardDeck, MAX_CARDS_IN_DECK, sizeof(CardType_t), false);
    CreateNewDeck(&CardsCircularBuffer);
}

bool CardDeck_Shuffle()
{
    // Validate complete deck before shuffling
    uint8_t i = MAX_CARDS_IN_DECK - 1;
    uint8_t j = 0;
    while(i > 0)
    {
        j = GetRandomInRange(0, i);
        SwapCards(&CardDeck[j], &CardDeck[i]);
        i--;
    }
    return true;
}

bool CardDeck_GetNextCard(CardType_t* cardVal)
{
	return CircularBuffer_GetLastElement(&CardsCircularBuffer, cardVal);
}

bool CardDeck_PutCardBack(CardType_t* cardVal)
{
	return CircularBuffer_AddElement(&CardsCircularBuffer, cardVal);
}

// H, S, C D
char CardDeck_GetShape(CardType_t card)
{
    char returnVal = 'E';
    switch(card.Shape)
    {
        case CARD_SHAPE_HEART:
            returnVal = 'H';//'♥';
            break;
        case CARD_SHAPE_SPADE:
            returnVal = 'S';//'♠';
            break;
        case CARD_SHAPE_CLUB:
            returnVal = 'C';//'♣';
            break;
        case CARD_SHAPE_DIAMOND:
            returnVal = 'D';//'♦';
            break;
        default:
            returnVal = 'E';
            break;
    }
    return returnVal;
}

char CardDeck_GetVal(CardType_t card)
{
    char returnVal = 'E';
    if (card.Number == 1)
    {
        returnVal = 'A';
    }
    else if(card.Number > 1 && card.Number < 10)
    {
        returnVal = card.Number + 48; //convert directly to ascii
    }
    else if(card.Number == 10)
    {
    	returnVal = 'T';
    }
    else if(card.Number == 11)
    {
        returnVal = 'J';
    }
    else if(card.Number == 12)
    {
        returnVal = 'Q';
    }
    else if(card.Number == 13)
    {
        returnVal = 'K';
    }
    else
    {
        returnVal = 'E';
    }
    return returnVal;
}

/*******************************************************************************
* Static Functions
********************************************************************************/

static void CreateNewDeck(CircularBufferStruct_t* cardsBuffer)
{
    uint8_t i;
    int8_t j = -1;
    CardType_t generatedCard;

    for (i = 0; i < MAX_CARDS_IN_DECK; i++)
    {
        if(0 == (i % 13))
        {
            j++;
        }
        
        generatedCard.Shape = j;
        generatedCard.Number = (i % 13) + 1;
        CircularBuffer_AddElement(&CardsCircularBuffer, (void*)&generatedCard);
    }
}

static bool ValidateDeck(CardType_t* cards, CardType_t missingCards)
{
    uint8_t i = 0;
    CardType_t tempDeck[MAX_CARDS_IN_DECK];
    uint8_t availableCards[CARD_SHAPE_COUNT][MAX_CARD_OF_SHAPE];
    // Sort the cards into tempDeck and verify if it has 52 unique cards
    
    for(i = 0; i < MAX_CARDS_IN_DECK; i++)
    {
        
    }
    return true;
}

static void SwapCards(CardType_t* cardA, CardType_t* cardB)
{
    CardType_t temp;
    temp = *cardA;
    *cardA = *cardB;
    *cardB = temp;
}

static uint8_t GetRandomInRange(uint8_t numA, uint8_t numB)
{
    uint8_t lower, upper;
    if(numA == numB)
    {
        return numA;
    }
    else if(numA > numB)
    {
        upper = numA;
        lower = numB;
    }
    else
    {
        upper = numB;
        lower = numA;
    }
    return (rand() % (upper - lower + 1)) + lower;
}
