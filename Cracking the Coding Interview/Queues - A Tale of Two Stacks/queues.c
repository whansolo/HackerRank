#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct sNode{
    int data;
    struct sNode *next;
};

struct queue{
    struct sNode *stack1;
    struct sNode *stack2;
};

void push(struct sNode** stackTop, int data){
    /* allocate node */
    struct sNode* new = (struct sNode*) malloc(sizeof(struct sNode));
    if(new == NULL){
        printf("Stack overflow \n");
        getchar();
        exit(0);
    }

    /* put in the data */
    new->data = data;
    /* link the old list off the new node */
    new->next = *stackTop;
    /* move the head to point to the new node */
    *stackTop = new;
}

int pop(struct sNode** stackTop){
    int res;
    struct sNode *top;

    /*If stack is empty then error */
    if(*stackTop == NULL){
        printf("Stack overflow \n");
        getchar();
        exit(0);
    }
    else{
        top = *stackTop;
        res = top->data;
        *stackTop = top->next;
        free(top);
        return res;
    }
}

void enQueue(struct queue *q, int x)
{
    push(&q->stack1, x);
}

int deQueue(struct queue *q)
{
    int x;
    /* If both stacks are empty then error */
    if(q->stack1 == NULL && q->stack2 == NULL)
    {
        printf("Q is empty");
        getchar();
        exit(0);
    }

    /* Move elements from satck1 to stack 2 only if
    stack2 is empty */
    if(q->stack2 == NULL)
    {
        while(q->stack1 != NULL)
        {
            x = pop(&q->stack1);
            push(&q->stack2, x);

        }
    }

    x = pop(&q->stack2);
    return x;
}

int peek(struct queue *q)
{
    int x;
    /* If both stacks are empty then error */
    if(q->stack1 == NULL && q->stack2 == NULL)
    {
        printf("Q is empty");
        getchar();
        exit(0);
    }

    /* Move elements from satck1 to stack 2 only if
    stack2 is empty */
    if(q->stack2 == NULL)
    {
        while(q->stack1 != NULL)
        {
            x = pop(&q->stack1);
            push(&q->stack2, x);

        }
    }

    x = q->stack2->data;
    return x;
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    char query[100];
    struct queue *q = (struct queue*)malloc(sizeof(struct queue));
    q->stack1 = NULL;
    q->stack2 = NULL;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf(" %[^\n]", query);
        switch(*query){
        case '1':
            enQueue(q, atoi(query + 2));
            break;
        case '2':
            deQueue(q);
            break;
        case '3':
            printf("%d\n", peek(q));
    }
    }
    return 0;
}
