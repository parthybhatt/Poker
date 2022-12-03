/********************************************************************************
* Filename    :

* Author      : Parth Bhatt

* Date        :

* Description :

********************************************************************************/

/*******************************************************************************
* Include Files
********************************************************************************/
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include "circular_buffer.h"

/*******************************************************************************
* Constants and macros
********************************************************************************/
#define NUM_ELEMS_IN_ARRAY 	10

/*******************************************************************************
* Data types (Structs, enum)
********************************************************************************/

/*******************************************************************************
* Static Variables
********************************************************************************/

static uint32_t TrialBuffer[NUM_ELEMS_IN_ARRAY];
static CircularBufferStruct_t BufferStruct;

/*******************************************************************************
* Static Functions Declaration
********************************************************************************/

static void DisplayBuffer();

/*******************************************************************************
* Public Functions
********************************************************************************/

int main()
{
	uint32_t sample[10] = {1, 2, 4, 5, 6, 23 , 20, 22, 34, 43};
	uint8_t i;
	memset(TrialBuffer, 0, NUM_ELEMS_IN_ARRAY);
	CircularBuffer_Init(&BufferStruct, TrialBuffer, NUM_ELEMS_IN_ARRAY, sizeof(TrialBuffer[0]), true);

	DisplayBuffer();
	for(i = 0; i < 10; i++)
	{
		CircularBuffer_AddElement(&BufferStruct, &sample[i]);
	}
	CircularBuffer_AddElement(&BufferStruct, &sample[--i]);

	DisplayBuffer();
	return 0;
}

/*******************************************************************************
* Static Functions
********************************************************************************/

static void DisplayBuffer()
{
	printf("TrialBuffer:\n");
	for(uint8_t i = 0; i < NUM_ELEMS_IN_ARRAY; i++)
	{
		printf("%d\t",TrialBuffer[i]);

		if(i == NUM_ELEMS_IN_ARRAY/2)
			printf("\n");
	}
	printf("\n\n");
}
