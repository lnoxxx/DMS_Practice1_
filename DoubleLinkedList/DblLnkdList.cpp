#include "DblLnkdList.h"

void enqueueDoubleList(DLList& list, const string& data){
    auto* newNode = new NodeDoubleList;
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    if (list.tail == nullptr){
        list.head = newNode;
        list.tail = newNode;
    } else{
        list.tail->next = newNode;
        newNode->prev = list.tail;
        list.tail = newNode;
    }
    list.size++;
}

string dequeueDoubleList(DLList& list){
    if(list.tail == nullptr){
        return "list empty";
    }
    NodeDoubleList* dequeueNode = list.tail;
    if (list.head == dequeueNode){
        string result = dequeueNode->data;
        delete dequeueNode;
        list.head = nullptr;
        list.tail = nullptr;
        list.size--;
        return result;
    }
    list.tail = dequeueNode->prev;
    dequeueNode->prev->next = nullptr;
    string result = dequeueNode->data;
    delete dequeueNode;
    list.size--;
    return result;
}