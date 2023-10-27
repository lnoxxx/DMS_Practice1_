#include "Dao.h"
#include <fstream>

//закрывать файлы
//хранение в 1 файле
//строковый тип даты
//удалить лишние функции

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
        stackDao(path,argc,argv);
    } else if (type == "queue"){
        queueDao(path,argc,argv);
    } else if (type == "hashmap"){
        hashMapDao(path,argc,argv);
    }else if (type == "set"){
        setDao(path,argc,argv);
    }
}
