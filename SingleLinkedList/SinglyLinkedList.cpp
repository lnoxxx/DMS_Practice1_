#include "SinglyLinkedList.h"

//функция добавления в начало O(1)
void pushSingleList(SingleListNode*& head, int data){
    auto* addNode = new SingleListNode;
    addNode->data = data;
    addNode->next = head;
    head = addNode;
}

//функция вывода списка
void printSingleList(SingleListNode* head){
    SingleListNode* printedNode = head;
    if (head == nullptr){
        return;
    }
    while (printedNode->next != nullptr){
        std::cout << printedNode->data << " -> (" << (printedNode->next)->data << ")" <<std::endl;
        printedNode = printedNode->next;
    }
    std::cout << printedNode->data << " -> ()" << std::endl;
}

//функция поиска O(n)
SingleListNode* searchSingleList(SingleListNode* head,const int& data){
    if(head == nullptr){
        std::cout << "list empty" << std::endl;
        return nullptr;
    }
    while(head->data != data && head->next != nullptr){
        head = head->next;
    }
    if (head->data == data){
        return head;
    }
    return nullptr;
}

//добавление в список по адресу O(1)
void addNodeByAddressSingleList (SingleListNode*& address, int data){
    if (address == nullptr){
        return;
    }
    auto* addingNode = new SingleListNode;
    addingNode->data = data;
    addingNode->next = address->next;
    address->next = addingNode;
}

//функция отчистки списка
void clearSingleList(SingleListNode*& head){
    while (head != nullptr){
        SingleListNode* deletedNode = head;
        head = deletedNode->next;
        delete deletedNode;
    }
}

//функция вставки по индексу (написал по приколу, можно использовать поиск + вставку по адресу)
void addIndexSingleList(SingleListNode*& head, int index, int data){
    if(index<0){
        std::cout<<"index must be > 0" << std::endl;
        return;
    }
    auto* addNode = new SingleListNode;
    addNode->data = data;
    addNode->next = nullptr;
    if (head == nullptr || index == 0){
        addNode->next = head;
        head = addNode;
        return;
    }
    SingleListNode* selected = head;
    for (int k = 0; k<(index-1); k++){
        if (selected->next == nullptr){
            std::cout << "index out of list range" << std::endl;
            return;
        }
        selected = selected->next;
    }
    addNode->next = selected->next;
    selected->next = addNode;
}

//поп О(1)
int popSingleList(SingleListNode*& head){
    if (head == nullptr){
        std::cout << "list empty" << std::endl;
        return 0;
    }
    SingleListNode* popNode = head;
    head = popNode->next;
    int result = popNode->data;
    delete popNode;
    return result;
}

//функция удаления по адресу О(1)
void deleteByAddressSingleList (SingleListNode*& address){
    if (address == nullptr){
        return;
    }
    SingleListNode* deletedNode = address->next;
    address->next = deletedNode->next;
    delete deletedNode;
}

void addToEndSingleList(SingleListNode*& head, int data){

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