#include "Dao.h"

//--file <filename.txt> --type <stack/queue/hashmap/set>
// --query <
//SADD SREM SISMEMBER
//SPUSH SPOP
//QPUSH QPOP
//HSET HDEL HGET>

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
