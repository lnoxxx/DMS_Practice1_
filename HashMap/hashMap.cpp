#include "hashMap.h"

int HashFun(const std::string& key){
    const int prime = 53;
    int hash = 0;
    for (auto letter : key) {
        hash = (hash * prime + letter) % SIZE;
    }
    return hash;
}

HashMapItem* createHashMapItem(const std::string& key, const std::string& data) {
    auto* item = new HashMapItem;
    item->key = key;
    item->data = data;
    item->next = nullptr;
    return item;
}

HashMap* createHashMapTable() {
    auto* table = new HashMap;
    table->count = 0;
    table->items = new HashMapItem*[SIZE];
    for (int i=0; i<SIZE; i++)
        table->items[i] = nullptr;
    return table;
}

void insertHashMap(HashMap* table,const std::string& key,const std::string& data){
    if (table->count >= SIZE){
        std::cout << "table is full" << std::endl;
        return;
    }
    int index = HashFun(key);
    auto item = createHashMapItem(key,data);

    auto currentItem = table->items[index];
    if (currentItem == nullptr){
        table->items[index] = item;
        table->count++;
    }
    else{
        if (currentItem->key == item->key){
            currentItem->data = data;
            return;
        }
        else{
            item->next = currentItem->next;
            currentItem->next = item;
            table->count++;
        }
    }
}

std::string SearchHashMapItem(HashMap* table, const std::string& key){
    if (table == nullptr){
        std::cout << "table is empty" << std::endl;
        return "not found";
    }
    int index = HashFun(key);
    HashMapItem* item = table->items[index];
    if (item != nullptr){
        if (item->key == key){
            return item->data;
        }
        else{
            while (item->key != key && item->next != nullptr){
                item = item->next;
            }
            if (item->key == key){
                return item->data;
            }
        }
    }
    //если значение пустое, возвращаем 0
    return "not found";
}

void deleteHashMapItem(HashMap* table, const std::string& key){
    if (table == nullptr){
        std::cout << "table is empty" << std::endl;
        return;
    }
    int index = HashFun(key);
    HashMapItem* item = table->items[index];
    if (item != nullptr){
        if (item->key == key && item->next == nullptr){
            delete table->items[index];
            table->items[index] = nullptr;
            table->count--;
        } else{
            if (item->key == key){
                delete table->items[index];
                table->items[index] = item->next;
            }
            else{
                while (item->next->key != key && item->next != nullptr){
                    item = item->next;
                }
                if (item->next->key == key){
                    delete item->next;
                    item->next = nullptr;
                    table->count--;
                }
            }
        }
    }
}