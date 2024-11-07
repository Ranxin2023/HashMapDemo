#include"IntCountHashMap.h"


static unsigned calculateHashValue(IntHashMap* map, const int key){
    unsigned hash = (unsigned)key;   // Convert key to unsigned for bitwise operations
    hash ^= (hash >> 16);           // XOR upper and lower bits for better mixing
    hash *= 0x45d9f3b;              // Multiply with a prime number for spreading bits
    hash ^= (hash >> 16);           // Additional mixing step
    return hash % map->capacity;    // Constrain to the hash table capacity
}
static unsigned getOrDefault(IntHashMap*map, const int key){
    unsigned hash=map->calculateHashValue(map, key);
    while(map->entries[hash]!=NULL){
        if(map->entries[hash]->key==key){
            return map->entries[hash]->value;
        }
        hash++;
        if(hash==map->capacity){
            hash=0;
        }
    }
    return 0;
}
static int existInTable(IntHashMap* map, const int key){
    unsigned hash=map->calculateHashValue(map, key);
    while(map->entries[hash]!=NULL){
        if(map->entries[hash]->key==key){
            return 1;
        }
        hash++;
        if(hash==map->capacity){
            hash=0;
        }
    }
    return 0;
}
static void insertEntry(IntHashMap* map, const int key, const int value){
    unsigned hash=map->calculateHashValue(map, key);
    while(map->entries[hash]!=NULL){
        if(map->entries[hash]->key==key){
            map->entries[hash]->value=value;
            return ;
        }
        hash++;
        if(hash==map->capacity){
            hash=0;
        }
    }
    map->entries[hash]=malloc(sizeof(IntHashMapEntry));
    map->entries[hash]->key=key;
    map->entries[hash]->value=value;
}

static void printHashMap(IntHashMap* map){
    for(int i=0; i<map->capacity; i++){
        if(map->entries[i]!=NULL){
            printf("number: %d, frequency: %d\n", map->entries[i]->key, map->entries[i]->value);
        }
    }
}

IntHashMap* createIntHashMap(unsigned size){
    IntHashMap * map=malloc(sizeof(IntHashMap));
    map->capacity=2*size;
    map->entries=malloc(sizeof(IntHashMapEntry*)*map->capacity);
    for(unsigned i=0; i<map->capacity; i++){
        map->entries[i]=NULL;
    }
    // map->createHashMap=createHashMap;
    
    map->calculateHashValue=calculateHashValue;
    map->existInTable=existInTable;
    map->getOrDefault=getOrDefault;
    map->insertEntry=insertEntry;
    map->printHashMap=printHashMap;
    return map;
}

void freeIntHashMap(IntHashMap*map){
    for(unsigned i=0; i<map->capacity; i++){
        if(map->entries[i]!=NULL){
            free(map->entries[i]);
        }
    }
    free(map->entries);
    free(map);
    printf("successfully free int map\n");
}