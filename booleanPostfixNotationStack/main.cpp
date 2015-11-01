// Stack_ADT.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include "booleanPostfixNotationStack.h"

#define CARR_ARRAY_SIZE 5

char c_calulateResult(STACK * ptr_boolTail, STACK *ptr_operatorTail, char carr_result[])
{
	carr_result[0] = '\0';

	if(ptr_boolTail)
		sprintf_s(carr_result, CARR_ARRAY_SIZE, "%s\0", ptr_boolTail->carray_data);

	ptr_boolTail = ptr_boolTail->next;

	while(ptr_operatorTail)
	{
		switch(ptr_operatorTail->carray_data[0])
		{
			case '&' :
				sprintf_s(carr_result, CARR_ARRAY_SIZE, "%s%s\0", carr_result, ptr_boolTail->carray_data);

				if(!strcmp(carr_result,"TT"))
					sprintf_s(carr_result, CARR_ARRAY_SIZE, "%s\0", "T");
				else
					sprintf_s(carr_result,CARR_ARRAY_SIZE ,"%s\0", "F");

				break;
			
			case '|' :
				sprintf_s(carr_result, CARR_ARRAY_SIZE, "%s%s\0", carr_result, ptr_boolTail->carray_data);
				if(!strcmp(carr_result,"FF"))
					sprintf_s(carr_result, CARR_ARRAY_SIZE, "%s\0", "F");
				else
					sprintf_s(carr_result, CARR_ARRAY_SIZE, "%s\0", "T");

				break;

			case '!' :
				if(!strcmp(carr_result,"F\0"))
					sprintf_s(carr_result, CARR_ARRAY_SIZE, "%s\0", "T");
				else
					sprintf_s(carr_result, CARR_ARRAY_SIZE, "%s\0", "F");

				break;

			default:
				printf("No Case Statement for: %s\n",ptr_operatorTail->carray_data);
				break;
		}
		if(ptr_boolTail->next)
			ptr_boolTail = ptr_boolTail->next;

		ptr_operatorTail = ptr_operatorTail->next;
	}
	return *carr_result;
}

int main(int argc, char* argv[])
{
	/* T T && F || ! */
	/*bool b_answer = !(false || (true && true));*/
	
    STACK *boolHead = NULL;
    STACK *boolTail = NULL;

	STACK *operatorHead = NULL;
    STACK *operatorTail = NULL;
    
	int i_count = 1;/*gets past the first argv*/
	int i_countBool = 1;/*count of elements in the bool STACK*/
	int i_countOperator = 1;/*count of elements in the operator STACK*/
	
	char carr_value[CARR_ARRAY_SIZE];
	while(argc > i_count)
	{
		carr_value[0] = '\0';

		sprintf_s(carr_value, CARR_ARRAY_SIZE, (const char*)argv[i_count]);
	    if(carr_value[0] != 'T' && carr_value[0] != 'F') 
		{
			b_pushHeadOn(&operatorHead,i_countOperator, carr_value);
			i_countOperator++;
		}
		else
		{
			b_pushHeadOn(&boolHead,i_countBool, carr_value);
			i_countBool++;
		}

		i_count++;
	}

	bool b_result = false;
	boolTail = ptr_getTail(boolHead);
	operatorTail = ptr_getTail(operatorHead);

	c_calulateResult(boolTail, operatorTail, carr_value);

	printf("Result is : %s\n", carr_value);

	if(!b_emptyTheStack(&boolHead))
		printf("Error: bool stack underflow\n");

	if(!b_emptyTheStack(&operatorHead))
		printf("Error: operator stack underflow\n");
	
	_CrtDumpMemoryLeaks();

    getchar();

	return 0;

}

/*
	char c_anotherValue[] = "Hello World!";
	int i_len = strlen(c_anotherValue);
	for(int i = 0; i < i_len-1;i++)
	{
		if(c_anotherValue[i] == c_anotherValue[i+1])
		{
			//printf("%c%c",c_anotherValue[i],c_anotherValue[i+1]);
			i++;
		}
		printf("%c",c_anotherValue[i]);
	}
    getchar();

	return 0;
*/
