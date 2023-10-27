#pragma once

#include <iostream>

using namespace std;

struct NodeDoubleList{
    string data;
    NodeDoubleList* next;
    NodeDoubleList* prev;
};

struct DLList{
    int size;
    NodeDoubleList* head;
    NodeDoubleList* tail;
};

void enqueueDoubleList(DLList& list,const string& data);
string dequeueDoubleList(DLList& list);