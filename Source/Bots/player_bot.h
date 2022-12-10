/********************************************************************************
* Filename    : PlayerBot.h

* Author      : Parth Bhatt

* Date        : December 6, 2022

* Description : Creates and handles the bots that will be playing poker with
* 			    each other.

********************************************************************************/

#ifndef __PLAYER_BOT_H__
#define __PLAYER_BOT_H__

/*******************************************************************************
* Include Files
********************************************************************************/
#include <stdbool.h>
#include <stdint.h>
#include "card_deck.h"

/*******************************************************************************
* Constants and macros
********************************************************************************/
#define MAX_CARDS_PER_PLAYER	(2)

/*******************************************************************************
* Data types
********************************************************************************/
typedef struct{
	CardType_t cards[MAX_CARDS_PER_PLAYER];
	uint8_t    numCardsServed;
	uint8_t	   changesToWin;
} PlayerBot_t;

/*******************************************************************************
* Global Variables
********************************************************************************/

/*******************************************************************************
* Functions
********************************************************************************/

void PlayerBot_Init(PlayerBot_t* playerBot);
void PlayerBot_ResetCards(PlayerBot_t* playerBot);
bool PlayerBot_ServeCardToBot(PlayerBot_t* playerBot, CardType_t* card);
void PlayerBot_Think(PlayerBot_t* playerBot);

#endif
