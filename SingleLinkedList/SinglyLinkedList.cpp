#include "SinglyLinkedList.h"

void pushSingleList(SingleListNode*& head,const string& data){
    auto* addNode = new SingleListNode;
    addNode->data = data;
    addNode->next = head;
    head = addNode;
}

string popSingleList(SingleListNode*& head){
    if (head == nullptr){
        return "list empty";
    }
    SingleListNode* popNode = head;
    head = popNode->next;
    string result = popNode->data;
    delete popNode;
    return result;
}

void addToEndSingleList(SingleListNode*& head,const string& data){
    if(head == nullptr){
        pushSingleList(head, data);
        return;
    }

    SingleListNode* currentNode = head;
    while (currentNode->next != nullptr){
        currentNode = currentNode->next;
    }

    auto* addNode = new SingleListNode;
    addNode->data = data;
    addNode->next = nullptr;

    currentNode->next = addNode;
}