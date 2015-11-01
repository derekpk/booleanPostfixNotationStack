//typedef struct stack *StackType;
//This is a STACK implemented as a linked list

typedef struct STACK{
    int i_order;
	char carray_data[3];
    struct STACK *next;
    struct STACK *prev;
}STACK;	

bool b_pushHeadOn(STACK **head,int n,char *cptr_newData);

bool b_showElementData(STACK *element);

bool b_pullHeadOff(STACK **head);

bool b_pullTailOff(STACK **tail);

bool b_emptyTheStack(STACK **head);

STACK* ptr_getTail(STACK *tail);

STACK* ptr_getHead(STACK *head);
