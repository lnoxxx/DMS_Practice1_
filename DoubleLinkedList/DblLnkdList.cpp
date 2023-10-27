#include "DblLnkdList.h"

//функция вывода списка
void printDoubleList(DLList& list){
    if (list.head == nullptr){
        return;
    }
    NodeDoubleList* prntdNode = list.head;
    while (prntdNode->next != nullptr){
        if (prntdNode->prev != nullptr){
            std::cout << "(" << prntdNode->prev->data << ") ";
        }
        std::cout << prntdNode->data;
        std::cout << " (" << prntdNode->next->data << ")" << std::endl;
        prntdNode = prntdNode->next;
    }
    std::cout << "(" << prntdNode->prev->data << ") ";
    std::cout << prntdNode->data << std::endl;
}

//пуш О(1)
void pushDoubleList(DLList& list, int data){
    auto* newNode = new NodeDoubleList;
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if (list.head == nullptr){
        list.head = newNode;
        list.tail = newNode;
    } else{
        list.head->prev = newNode;
        newNode->next = list.head;
        list.head = newNode;
    }
    list.size++;
}

//вставка по индексу О(n/2)
void addToIndexDoubleList(DLList& list, int data,int index){
    auto* newNode = new NodeDoubleList;
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if (list.head == nullptr || index == 0){
        pushDoubleList(list, data);
        return;
    }

    if (index == list.size){
        enqueueDoubleList(list, data);
        return;
    }

    if(index > list.size){
        return;
    }

    if(index < 0){
        return;
    }

    if (index < list.size/2){
        NodeDoubleList* currentNode = list.head;
        for (int k=0; k<index-1; k++){
            currentNode = currentNode->next;
        }
        newNode->next = currentNode->next;
        newNode->prev = currentNode;
        currentNode->next->prev = newNode;
        currentNode->next = newNode;
    } else{
        NodeDoubleList* currentNode = list.tail;
        for (int k=0; k<list.size-index; k++){
            currentNode = currentNode->prev;
        }
        newNode->next = currentNode->next;
        newNode->prev = currentNode;
        currentNode->next->prev = newNode;
        currentNode->next = newNode;
    }
    list.size++;
}

//вставка в конец списка
void enqueueDoubleList(DLList& list, int data){
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

//взятие из конца списка
int dequeueDoubleList(DLList& list){
    if(list.tail == nullptr){
        std::cout << "list empty" << std::endl;
        return 0;
    }
    NodeDoubleList* dequeueNode = list.tail;
    if (list.head == dequeueNode){
        int result = dequeueNode->data;
        delete dequeueNode;
        list.head = nullptr;
        list.tail = nullptr;
        list.size--;
        return result;
    }
    list.tail = dequeueNode->prev;
    dequeueNode->prev->next = nullptr;
    int result = dequeueNode->data;
    delete dequeueNode;
    list.size--;
    return result;
}

//отчистка списка
void deleteDoubleList(DLList& list){
    if (list.head == nullptr){
        return;
    }
    while (list.head != nullptr){
        NodeDoubleList* deletedNode = list.head;
        list.head = deletedNode->next;
        delete deletedNode;
    }
}