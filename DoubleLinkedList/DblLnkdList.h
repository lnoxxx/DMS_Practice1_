#pragma once

#include <iostream>

//узел
struct NodeDoubleList{
    int data;
    NodeDoubleList* next;
    NodeDoubleList* prev;
};

//двусвязный список
struct DLList{
    int size;
    NodeDoubleList* head;
    NodeDoubleList* tail;
};

void printDoubleList(DLList& list);
void pushDoubleList(DLList& list, int data);
void enqueueDoubleList(DLList& list, int data);
void deleteDoubleList(DLList& list);
int dequeueDoubleList(DLList& list);