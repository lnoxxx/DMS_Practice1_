#pragma once

#include "DoubleLinkedList/DblLnkdList.h"
#include "HashMap/hashMap.h"
#include "SingleLinkedList/SinglyLinkedList.h"
#include "Set/Set.h"
#include <fstream>

using namespace std;

void stackDao(const string& path,const int& argc,char* argv[]);
void queueDao(const string& path,const int& argc,char* argv[]);
void hashMapDao(const string& path,const int& argc,char* argv[]);
void setDao(const string& path,const int& argc,char* argv[]);