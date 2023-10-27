#include "DoubleLinkedList/DblLnkdList.h"
#include "HashMap/hashMap.h"
#include "SingleLinkedList/SinglyLinkedList.h"
#include "Set/Set.h"

#include <fstream>

//закрывать файлы
//хранение в 1 файле
//строковый тип даты
//удалить лишние функции

using namespace std;

void stackDao(const string& path,const int& argc,const char* argv[]){
    SingleListNode* head = nullptr;
    ifstream fileRead;
    fileRead.open(path);
    if (fileRead.is_open()){
        while (!fileRead.eof()){
            if(fileRead.peek() == EOF){
                break;
            }
            int item;
            fileRead >> item;
            addToEndSingleList(head,item);
        }
    }

    cout << endl;

    for (int i = 1; i < argc; i++) {
        string arg = argv[i];
        if (arg == "--query"){
            string query = argv[i+1];
            if (query == "SPUSH"){
                pushSingleList(head,stoi(argv[i+2]));
            }
            if (query == "SPOP"){
                cout << popSingleList(head) << endl;
            }
        }
    }

    if (head != nullptr){
        ofstream returnedFile;
        returnedFile.open(path);
        SingleListNode* currentNode = head;
        while (currentNode != nullptr){
            if (currentNode->next == nullptr){
                returnedFile << currentNode->data;
            } else{
                returnedFile << currentNode->data << endl;
            }
            currentNode = currentNode->next;
        }
    } else{
        ofstream returnedFile;
        returnedFile.open(path);
    }
}


int main(int argc, char* argv[]) {
    string path;
    string type;

    for (int i = 1; i < argc; i++) {
        string arg = argv[i];
        if (arg == "--file"){
            path = argv[i+1];
        }
        if (arg == "--type"){
            type = argv[i+1];
        }
    }

    if (type == "stack"){
        SingleListNode* head = nullptr;
        ifstream fileRead;
        fileRead.open(path);
        if (fileRead.is_open()){
            while (!fileRead.eof()){
                if(fileRead.peek() == EOF){
                    break;
                }
                int item;
                fileRead >> item;
                addToEndSingleList(head,item);
            }
        }

        cout << endl;

        for (int i = 1; i < argc; i++) {
            string arg = argv[i];
            if (arg == "--query"){
                string query = argv[i+1];
                if (query == "SPUSH"){
                    pushSingleList(head,stoi(argv[i+2]));
                }
                if (query == "SPOP"){
                    cout << popSingleList(head) << endl;
                }
            }
        }

        if (head != nullptr){
            ofstream returnedFile;
            returnedFile.open(path);
            SingleListNode* currentNode = head;
            while (currentNode != nullptr){
                if (currentNode->next == nullptr){
                    returnedFile << currentNode->data;
                } else{
                    returnedFile << currentNode->data << endl;
                }
                currentNode = currentNode->next;
            }
        } else{
            ofstream returnedFile;
            returnedFile.open(path);
        }
    }

    if (type == "queue"){
        DLList list = {0, nullptr, nullptr};
        ifstream fileRead;
        fileRead.open(path);
        if (fileRead.is_open()){
            while (!fileRead.eof()){
                if(fileRead.peek() == EOF){
                    break;
                }
                int item;
                fileRead >> item;
                enqueueDoubleList(list,item);
            }
        }

        for (int i = 1; i < argc; i++) {
            string arg = argv[i];
            if (arg == "--query"){
                string query = argv[i+1];
                if (query == "QPUSH"){
                    enqueueDoubleList(list,stoi(argv[i+2]));
                }
                if (query == "QPOP"){
                    cout << dequeueDoubleList(list) << endl;
                }
            }
        }

        if (list.head != nullptr){
            ofstream returnedFile;
            returnedFile.open(path);
            NodeDoubleList* currentNode = list.head;
            while (currentNode != nullptr){
                if (currentNode->next == nullptr){
                    returnedFile << currentNode->data;
                } else{
                    returnedFile << currentNode->data << endl;
                }
                currentNode = currentNode->next;
            }
        } else{
            ofstream returnedFile;
            returnedFile.open(path);
        }
    }

    if (type == "hashmap"){
        auto table = createHashMapTable();
        ifstream fileRead;
        fileRead.open(path);
        if (fileRead.is_open()){
            while (!fileRead.eof()){
                string tableItemKey;
                fileRead >> tableItemKey;
                int tableItemData;
                fileRead >> tableItemData;
                insertHashMap(table,tableItemKey,tableItemData);
            }
        }
        for (int i = 1; i < argc; i++) {
            string arg = argv[i];
            if (arg == "--query"){
                string query = argv[i+1];
                if (query == "HSET"){
                    string tableItemKey = argv[i+2];
                    int tableItemData = stoi(argv[i+3]);
                    insertHashMap(table,tableItemKey,tableItemData);
                }
                if (query == "HDEL"){
                    string tableItemKey = argv[i+2];
                    deleteHashMapItem(table,tableItemKey);
                }
                if (query == "HGET"){
                    string tableItemKey = argv[i+2];
                    cout << SearchHashMapItem(table,tableItemKey) << endl;
                }
            }
        }
        ofstream returnedFile;
        returnedFile.open(path);
        for (int i=0; i<SIZE; i++){
            if (table->items[i] != nullptr && !table->items[i]->key.empty()){
                returnedFile << table->items[i]->key<< " " <<table->items[i]->data << endl;
            }
        }
    }

    if (type == "set"){
        auto set = createSet();
        ifstream fileRead;
        fileRead.open(path);
        if (fileRead.is_open()){
            while (!fileRead.eof()){
                string setItem;
                fileRead >> setItem;
                insertSet(set,setItem);
            }
        }
        for (int i = 1; i < argc; i++) {
            string arg = argv[i];
            if (arg == "--query"){
                string query = argv[i+1];
                if (query == "SADD"){
                    string data = argv[i+2];
                    insertSet(set,data);
                }
                if (query == "SREM"){
                    string data = argv[i+2];
                    deleteSetItem(set,data);
                }
                if (query == "SISMEMBER"){
                    string data = argv[i+2];
                    cout << SearchSetItem(set,data) << endl;
                }
            }
        }
        ofstream returnedFile;
        returnedFile.open(path);
        for (int i=0; i<SIZE; i++){
            if (set->items[i] != nullptr && !set->items[i]->data.empty()){
                returnedFile << set->items[i]->data<< endl;
            }
        }
    }

}
