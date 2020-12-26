#include <stdio.h>
#include <stdlib.h>

typedef struct Element{
    int *data;
    struct Element *next;
}Element;

int push(Element **stack,int *data);

int pop(Element **stack,int **data);

int createStack(Element **stack);

int deleteStack(Element **stack);

////////////////////////////

int createStack(Element **stack){
    *stack=NULL;
    return 0;
}

int push(Element **stack,int *data){
    Element *elem;
    elem=(Element*)malloc(sizeof(Element*));
    if (!elem) return 1;

    elem->data=data;
    elem->next=*stack;
    *stack=elem;
    return 0;
}

int pop(Element **stack,int **data){
    Element *elem;
    elem=*stack;
    if (!elem) return 1;

    *stack=elem->next;
    *data=(elem->data);
    free(elem);
    return 0;
}

int deleteStack(Element **stack){
    Element *next;

    while(*stack){
        next=(*stack)->next;
        free(*stack);
        *stack=next;
    }
    return 0;
}

int main(){

    Element *stack;
    int i=5;
    int *o;

    createStack(&stack);
    if(push(&stack,&i)==1)
        printf("Error pushing\n");

    if(pop(&stack,&o)==1)
        printf("Error poping\n");

    printf("o: %d\n",*o);

    return 0;
}
