#include "Set.h"

int SetHashFun(const std::string& data){
    const int prime = 53;
    int hash = 0;
    for (auto letter : data) {
        hash = (hash * prime + letter) % SIZE;
    }
    return hash;
}

SetItem* createSetItem(const std::string& data) {
    auto* item = new SetItem;
    item->data = data;
    item->next = nullptr;
    return item;
}

Set* createSet() {
    auto* set = new Set;
    set->count = 0;
    set->items = new SetItem*[SIZE];
    for (int i=0; i<SIZE; i++)
        set->items[i] = nullptr;
    return set;
}

void insertSet(Set* set,const std::string& data){

    if (set->count >= SIZE){
        std::cout << "set is full" << std::endl;
        return;
    }

    int index = SetHashFun(data);
    auto item = createSetItem(data);

    auto currentItem = set->items[index];
    if (currentItem == nullptr){
        set->items[index] = item;
        set->count++;
    }
    else{
        if (currentItem->data == data){
            return;
        }
        else{
            item->next = currentItem->next;
            currentItem->next = item;
            set->count++;
        }
    }
}

void deleteSetItem(Set* set, const std::string& data){
    if (set == nullptr){
        std::cout << "set is empty" << std::endl;
        return;
    }
    int index = SetHashFun(data);
    SetItem* item = set->items[index];
    if (item != nullptr){
        if (item->data == data && item->next == nullptr){
            delete set->items[index];
            set->items[index] = nullptr;
            set->count--;
        } else{
            if (item->data == data){
                delete set->items[index];
                set->items[index] = item->next;
                set->count--;
            }
            else{
                while (item->next->data != data && item->next != nullptr){
                    item = item->next;
                }
                if (item->next->data == data){
                    delete item->next;
                    item->next = nullptr;
                    set->count--;
                }
            }
        }
    }
}

std::string SearchSetItem(Set* set, const std::string& data){
    if (set == nullptr){
        std::cout << "set is empty" << std::endl;
        return "";
    }
    int index = SetHashFun(data);
    SetItem* item = set->items[index];
    if (item != nullptr){
        if (item->data == data){
            return item->data;
        }
        else{
            while (item->data != data && item->next != nullptr){
                item = item->next;
            }
            if (item->data == data){
                return item->data;
            }
        }
    }
    return "";
}