/********************************************************************************
* Filename    : PlayerBot.h

* Author      : Parth Bhatt

* Date        : December 6, 2022

* Description : Creates and handles the bots that will be playing poker with
* 			    each other.

********************************************************************************/

/*******************************************************************************
* Include Files
********************************************************************************/
#include <stdbool.h>
#include <stdint.h>
#include "player_bot.h""
#include "card_deck.h"

/*******************************************************************************
* Constants and macros
********************************************************************************/

/*******************************************************************************
* Data types (Structs, enum)
********************************************************************************/

/*******************************************************************************
* Static Variables
********************************************************************************/

/*******************************************************************************
* Static Functions Declaration
********************************************************************************/

/*******************************************************************************
* Public Functions
********************************************************************************/

void PlayerBot_Init(PlayerBot_t* playerBot)
{
	PlayerBot_ResetCards(playerBot);
}

void PlayerBot_ResetCards(PlayerBot_t* playerBot)
{
	for(uint8_t i = 0; i < MAX_CARDS_PER_PLAYER; i++)
	{
		playerBot->cards[i].Number = 0xFF;
		playerBot->cards[i].Shape = 0xFF;
	}
	playerBot->numCardsServed = 0;
	playerBot->changesToWin = 0;
}

bool PlayerBot_ServeCardToBot(PlayerBot_t* playerBot, CardType_t card)
{
	if( playerBot->numCardsServed < MAX_CARDS_PER_PLAYER)
	{
		playerBot->cards[playerBot->numCardsServed] = card;
		playerBot->numCardsServed++;
		return true;
	}
	else
	{
		return false;
	}
}

void PlayerBot_Think(PlayerBot_t* playerBot)
{
	//
}

/*******************************************************************************
* Static Functions
********************************************************************************/

