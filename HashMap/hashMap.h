#pragma once

#define SIZE 500

#include <iostream>

struct HashMapItem {
    std::string key;
    std::string data;
    HashMapItem* next;
};

struct HashMap {
    HashMapItem** items;
    int count;
};

HashMap* createHashMapTable();
void insertHashMap(HashMap* table,const std::string& key,const std::string& data);
std::string SearchHashMapItem(HashMap* table, const std::string& key);
void deleteHashMapItem(HashMap* table, const std::string& key);
