#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
using namespace std;
    struct ListNode
    {
        int value;           
        struct ListNode* next;  
    };
class List
{
private:
    ListNode* head = NULL;    
    int size;

public:
    List()
    {
        head = nullptr;
        size = 0;
    }

    ~List();
    void insertNode(int);
    void deleteNode(int);
    bool findNode(int);
    int getsize();
    ListNode* gethead() { return head; };
};
int List::getsize()
{
    return size;
}
bool List:: findNode(int num)
{
    bool found = false;;
    ListNode* nodePtr;
    if (!head)
        return found;
    else
    {
        nodePtr = head;
        while (nodePtr != nullptr && nodePtr->value != num)
        {
            nodePtr = nodePtr->next;
        }
        if (nodePtr)
        {
            found = true;
            return found;
        }
        else
        {
            return found;
        }
    }
}

void List::insertNode(int num)
{
    ListNode* newNode; 
    ListNode* nodePtr;  

    newNode = new ListNode;
    newNode->value = num;
    newNode->next = nullptr;

    if (head == NULL) {
        head = newNode;
        size++;
    }
    else 
    {
        nodePtr = head;
        while (nodePtr->next)
            nodePtr = nodePtr->next;
        nodePtr->next = newNode;
        size++;
    }
}

void List::deleteNode(int num)
{
    ListNode* nodePtr;       
    ListNode* previousNode = nullptr;  
    if (!head)
        return;
    if (head->value == num)
    {
        nodePtr = head->next;
        delete head;
        head = nodePtr;
        size--;
    }
    else
    {
        nodePtr = head;
        while (nodePtr != nullptr && nodePtr->value != num)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        if (nodePtr)
        {
            previousNode->next = nodePtr->next;
            delete nodePtr;
            size--;
        }
    }
}

List::~List()
{
    ListNode* nodePtr; 
    ListNode* nextNode;  
    nodePtr = head;


    while (nodePtr != nullptr)
    {
        nextNode = nodePtr->next;


        delete nodePtr;
        nodePtr = nextNode;
    }
}

#endif // LINKEDLIST_H