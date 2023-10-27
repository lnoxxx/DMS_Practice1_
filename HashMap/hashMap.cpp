#include "hashMap.h"

//хэш функция
int HashFun(const std::string& key){
    const int prime = 53;
    int hash = 0;
    for (auto letter : key) {
        hash = (hash * prime + letter) % SIZE;
    }
    return hash;
}

//создание элемента таблицы
HashMapItem* createHashMapItem(const std::string& key, const int& data) {
    auto* item = new HashMapItem;
    item->key = key;
    item->data = data;
    item->next = nullptr;
    return item;
}

//создание таблицы
HashMap* createHashMapTable() {
    auto* table = new HashMap;
    table->count = 0;
    table->items = new HashMapItem*[SIZE];
    for (int i=0; i<SIZE; i++)
        table->items[i] = nullptr;
    return table;
}

//функция вставки от O(1) до O(n), из за борьбы с коллизией с помощью списков
void insertHashMap(HashMap* table,const std::string& key,const int& data){
    //если таблица полная, не вставляем
    if (table->count >= SIZE){
        std::cout << "table is full" << std::endl;
        return;
    }
    //находим индекс для вставки с помощью хэш функции
    int index = HashFun(key);
    auto item = createHashMapItem(key,data);

    //проверяем, что находиться на планируемом месте для вставки
    auto currentItem = table->items[index];
    //если место пустое, вставляем
    if (currentItem == nullptr){
        table->items[index] = item;
        table->count++;
    }
    //если не пустое
    else{
        //и если по такому ключу уже что-то есть, то перезаписываем значение
        if (currentItem->key == item->key){
            currentItem->data = data;
            return;
        }
        // если произошла коллизия, вставляем в начало списка
        else{
            item->next = currentItem->next;
            currentItem->next = item;
            table->count++;
        }
    }
}

//функция поиска от O(1) до O(n), из за борьбы с коллизией с помощью списков
int SearchHashMapItem(HashMap* table, const std::string& key){
    // если таблица пустая, возвращаем 0
    if (table == nullptr){
        std::cout << "table is empty" << std::endl;
        return 0;
    }
    //находим расположения элемента с помощью хэш функции
    int index = HashFun(key);
    HashMapItem* item = table->items[index];
    //если место не пустое
    if (item != nullptr){
        //если ключ совпадает, возвращаем значение
        if (item->key == key){
            return item->data;
        }
        //если ключ отличается, идем до конца списка или пока не найдем такой же ключ
        else{
            while (item->key != key && item->next != nullptr){
                item = item->next;
            }
            //возвращаем значение по ключу
            if (item->key == key){
                return item->data;
            }
        }
    }
    //если значение пустое, возвращаем 0
    return 0;
}

//функция удаления элемента от O(1) до O(n), из за борьбы с коллизией с помощью списков
void deleteHashMapItem(HashMap* table, const std::string& key){
    //если таблица пустая, ниче не делаем
    if (table == nullptr){
        std::cout << "table is empty" << std::endl;
        return;
    }
    //находим элемент по ключу
    int index = HashFun(key);
    HashMapItem* item = table->items[index];
    //если элемент есть
    if (item != nullptr){
        //если ключ совпадает и это единственный элемент в списке
        if (item->key == key && item->next == nullptr){
            delete table->items[index];
            table->items[index] = nullptr;
            table->count--;
        } else{
            // если ключ совпадает, но это не единственный элемент
            if (item->key == key){
                delete table->items[index];
                table->items[index] = item->next;
            }
            //если ключ не совпал
            else{
                //пока не найдем элемент в списке с таким ключом, или пока список не закончился
                while (item->next->key != key && item->next != nullptr){
                    item = item->next;
                }
                //если нашли
                if (item->next->key == key){
                    delete item->next;
                    item->next = nullptr;
                    table->count--;
                }
            }
        }
    }
}