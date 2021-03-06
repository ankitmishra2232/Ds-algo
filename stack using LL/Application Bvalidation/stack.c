/*
                AUTHOR : 2125_ANKIT
                PROGRAM: IMPLEMENTATION FILE for STACK USING LINKED LIST
                DATE CREATED: SEPT 2021
                DATE MODIFIED: SEPT 2021
 */
#include "stack.h"
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

    eleType peek(stackType s1) //It checks top element of stack and print the element only
    {
        return s1.top->data;  //if precondition was not there then stack is empty then throw the underflow error
    }


    eleType pop(stackType *s1) // It removes top element and display popped element
    {   
        s1->count--;
        node *temp=s1->top;
        //case1 stack is empty(we do not handle since it is created already)
        //case2 non empty stack
        //case 2a deleting only top element
        s1->top =s1->top->next;
         eleType poppedEle =temp->data;
            free(temp);
            return (poppedEle);
    }
    
    void destroyStack(stackType *s1) //It destroy stack and free the allocated dynamic memory
    { 
        while(s1->top!=NULL)
        {s1->count--;
        node *temp =s1->top;
        s1->top =s1->top->next;
        free(temp);
        }
    }
 
    bool push(eleType ip_data, stackType *s1) // It pushes the element into the stack at the top position 
    {   //Allocating memory
        node *newDataNode =(node *) malloc(1* sizeof(node));
        if(newDataNode ==NULL)
            return false;
        else
        {
            newDataNode ->data=ip_data;
            newDataNode->next=s1->top; //it can cover if else statement  ie. in when stack is empty and not empty
            s1->top = newDataNode;
            s1->count++;
            return true;
        }
    }
    
    bool isFull(stackType s1) // checks the memory of the sys is full or not
    {
        return false;
    }
    
    bool isEmpty(stackType s1) //check is there something into the stack or not
    {
        if(s1.top==NULL)
        {
            return true;
        }
        return false;
    }

    stackType createStack() // creates the stack in Linkedlist.
    {
        stackType s;
        s.count=0;
        s.top=NULL;
        return s;
    }