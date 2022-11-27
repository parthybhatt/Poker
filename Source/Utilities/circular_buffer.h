/********************************************************************************
* Filename    : 

* Author      : Parth Bhatt

* Date        : 

* Description : 

********************************************************************************/

#ifndef __CIRCULAR_BUFFER_H__
#define __CIRCULAR_BUFFER_H__

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
typedef enum
{
	BUFFER_STATE_EMPTY,
	BUFFER_STATE_HAS_ELEMENTS,
	BUFFER_STATE_FULL,
} BufferState_t;

typedef struct
{
	uint32_t writerIdx;
	uint32_t readerIdx;
	uint32_t maxElems;
	uint32_t elementSize;
	void*    bufferArray;
	bool	 allowOverflow;
	BufferState_t	bufferState;
} CircularBufferStruct_t;

/*******************************************************************************
* Global Variables
********************************************************************************/

/*******************************************************************************
* Functions
********************************************************************************/

void CircularBuffer_Init(CircularBufferStruct_t* bufferStruct,
		void* buffer,
		uint32_t numElems,
		uint32_t elementsize,
		bool overflow);
void CircularBuffer_AddElement(CircularBufferStruct_t* buffer, void* element);
void CircularBuffer_GetLastElement(CircularBufferStruct_t* buffer, void* element);

#endif
