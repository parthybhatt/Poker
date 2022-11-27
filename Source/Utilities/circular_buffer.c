/********************************************************************************
* Filename    : 

* Author      : Parth Bhatt

* Date        : 

* Description : 

********************************************************************************/

/*******************************************************************************
* Include Files
********************************************************************************/
#include "circular_buffer.h"
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

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
void CircularBuffer_Init(CircularBufferStruct_t* bufferStruct, void* buffer, uint32_t numElems, uint32_t elementsize, bool overflow)
{
	bufferStruct->writerIdx = 1;
	bufferStruct->readerIdx = 0;
	bufferStruct->maxElems = numElems;
	bufferStruct->elementSize = elementsize;
	bufferStruct->bufferArray = buffer;
	bufferStruct->allowOverflow = overflow;
	bufferStruct->bufferState = BUFFER_STATE_EMPTY;
}

void CircularBuffer_AddElement(CircularBufferStruct_t* buffer, void* element)
{
	void* bufferLoc = buffer->bufferArray;

	if(buffer->bufferState == BUFFER_STATE_FULL)
	{
		if(buffer->allowOverflow == true)
		{
			//
		}
	}

    if(buffer->writerIdx != buffer->readerIdx)
    {
    	bufferLoc += (buffer->writerIdx * buffer->elementSize);
    	memcpy(bufferLoc, element, buffer->elementSize);
    	buffer->writerIdx++;
    	if(buffer->writerIdx == buffer->maxElems)
    	{
    		buffer->writerIdx = 0;
    	}
    }
    else
    {
    	if(buffer->)
    }
}

/*******************************************************************************
* Static Functions
********************************************************************************/
