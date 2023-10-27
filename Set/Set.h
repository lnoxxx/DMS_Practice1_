#pragma once

#define SIZE 500

#include "string"
#include "iostream"

//элемент множества
struct SetItem {
    //значение
    std::string data;
    //указатель на след, если произошла коллизия
    SetItem* next;
};

//множество
struct Set {
    SetItem** items;
    //счетчик кол-ва элементов
    int count;
};

Set* createSet();
void insertSet(Set* set,const std::string& data);
void deleteSetItem(Set* set, const std::string& data);
std::string SearchSetItem(Set* set, const std::string& data);