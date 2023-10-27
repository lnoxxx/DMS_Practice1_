#pragma once

#include <iostream>

//узел списка
struct SingleListNode{
    //значение
    int data;
    //следующий элемент
    SingleListNode* next;
};

void pushSingleList(SingleListNode*& head, int data);
void printSingleList(SingleListNode* head);
SingleListNode* searchSingleList(SingleListNode* head,const int& data);
void clearSingleList(SingleListNode*& head);
void addNodeByAddressSingleList (SingleListNode*& address, int data);
int popSingleList(SingleListNode*& head);
void deleteByAddressSingleList (SingleListNode*& address);
void addToEndSingleList(SingleListNode*& head, int data);