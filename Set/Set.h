#pragma once

#define SIZE 500

#include "iostream"

struct SetItem {
    std::string data;
    SetItem* next;
};

struct Set {
    SetItem** items;
    int count;
};

Set* createSet();
void insertSet(Set* set,const std::string& data);
void deleteSetItem(Set* set, const std::string& data);
std::string SearchSetItem(Set* set, const std::string& data);