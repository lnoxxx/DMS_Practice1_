#pragma once

//размер хэш таблицы
#define SIZE 500

#include <iostream>
#include <string>

//элемент хэш таблицы
struct HashMapItem {
    //ключ
    std::string key;
    //значение
    int data;
    //указатель на след, если произошла коллизия
    HashMapItem* next;
};

//таблица
struct HashMap {
    //указатель на массив из указателей на элементы таблицы
    HashMapItem** items;
    //счетчик кол-ва элементов
    int count;
};

HashMap* createHashMapTable();
void insertHashMap(HashMap* table,const std::string& key,const int& data);
int SearchHashMapItem(HashMap* table, const std::string& key);
void deleteHashMapItem(HashMap* table, const std::string& key);
