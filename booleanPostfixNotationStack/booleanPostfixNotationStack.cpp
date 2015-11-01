

#include "stdafx.h"

#ifndef _MALLOC_
#include <malloc.h>
#endif

#include "booleanPostfixNotationStack.h"

void v_initElement(STACK **element)
{
    (*element)->i_order=NULL;
	(*element)->carray_data[0] = '\0';
    (*element)->prev=NULL;
    (*element)->next=NULL;
}

bool b_pushHeadOn(STACK **head,int n, char *cptr_newData)
{
	/*allocate space for the new stack item*/
    STACK *element = (STACK *)malloc(sizeof(STACK));
	/*initialise the node elements*/
	v_initElement(&element);

	if(element==NULL)
    {	/*read the message below*/
		printf("NO MEMORY FOR NEW NODE\n");
		return false;
	}else
    {
		if(*head==NULL)/*stack is empty*/
		{
			element->i_order=n;
			sprintf_s(element->carray_data,(char*)cptr_newData);
			(*head) = element;
			(*head)->prev=NULL;
			(*head)->next=NULL;
			return true;
		}
		else/*stack has at least one element*/
		{
			element->i_order=n;
			sprintf_s(element->carray_data,(char*)cptr_newData);
			element->prev = (*head);
			element->prev->next = element;
			(*head) = element;
			return true;

		}
    }
	return false;
}

bool b_showElementData(STACK *element)
{
    if(element!=NULL)
    {
        printf("Element Contents:\n");
        printf("order : %d\ndata : %s\n\n",element->i_order,element->carray_data);
		return true;
    }
    else
    {
        printf("The stack is empty!\n");
		return false;
    }
}

bool b_pullHeadOff(STACK **head)
{
	/*this will remove the last item from the stack*/
	if (*head==NULL)
	{/* stack is empty */
		return false;
	} else {     /* pop an element*/ 
		STACK *end = *head;
		if(end->prev)
		{
			(*head) = end->prev;
			(*head)->next = NULL;
		}
		else
			*head = NULL;
		free(end);
		return true;
	}
}

bool b_pullTailOff(STACK **tail)
{
	/*this will remove the last item from the stack*/
	if (*tail==NULL)
	{/* stack is empty */
		return false;
	} else {     /* pop an element*/ 
		STACK *start = *tail;
		if(start->next)
		{
			(*tail) = start->next;
			(*tail)->prev = NULL;
		}
		else
			(*tail) = NULL;
		free(start);
		return true;
	}
}

STACK* ptr_getTail(STACK *element)
{
	while(element->prev!=NULL)
	{
		element = element->prev;
	}
	return element;
}

STACK* ptr_getHead(STACK *element)
{
	while(element->next!=NULL)
	{
		element = element->next;
	}
	return element;
}

bool b_emptyTheStack(STACK **head)
{	
	while(*head!=NULL)
	{
		if(!b_pullHeadOff(head))
			return false;
	}
	return true;
}

