#pragma once

#include <iostream>

using namespace std;

struct SingleListNode{
    string data;
    SingleListNode* next;
};

void pushSingleList(SingleListNode*& head,const string& data);
string popSingleList(SingleListNode*& head);
void addToEndSingleList(SingleListNode*& head,const string& data);