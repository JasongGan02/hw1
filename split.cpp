/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <cstddef>
/* Add a prototype for a helper function here if you need */
/* If you needed a helper function, write it here */
void splitHelper(Node*& in, Node*& odds, Node*& evens, Node*& lastOdd, Node*& lastEven)
{
    if (in == nullptr)
    {
        return;
    }

    Node* nextNode = in->next; // Store the next node
    in->next = nullptr;
    // Recursive case: If input list is not empty, split the list
    if (in->value % 2 == 0) // case the input is even
    {
        if (evens == nullptr) //initialize evens if its the first node
        {
            evens = in;
        }
        else
        {
            lastEven->next = in;
        }
        lastEven = in;
    }
    else //case the input is odd
    {
        if (odds == nullptr) //initialize odds if its the first node
        {
            odds = in;
        }
        else
        {
            lastOdd->next = in;
        }
        lastOdd = in;
    }
    in = nextNode;
    splitHelper(nextNode, odds, evens, lastOdd, lastEven);
} 

void split(Node*& in, Node*& odds, Node*& evens) {  
    if (in == nullptr)
        return;
    Node* lastOdd = nullptr;
    Node* lastEven = nullptr;
    splitHelper(in, odds, evens, lastOdd, lastEven);
}

