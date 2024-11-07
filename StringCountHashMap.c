#include"StringCountHashMap.h"


static unsigned calculateHashValue(StringCountHashMap* map, const char * key, const unsigned key_len){
    unsigned hash=5381;
    for(unsigned i=0; i<key_len; i++){
        hash = ((hash << 5) + hash) + key[i];
        hash%=map->capacity;
    }
    
    return hash;
}
static unsigned getOrDefault(StringCountHashMap*map, const char * key, const unsigned key_len){
    unsigned hash=map->calculateHashValue(map, key, key_len);
    while(map->entries[hash]!=NULL){
        if(strcmp(map->entries[hash]->key, key)==0){
            return map->entries[hash]->count;
        }
        hash++;
        if(hash==map->capacity){
            hash=0;
        }
    }
    return 0;
}
static int existInTable(StringCountHashMap* map, const char * key, unsigned key_len){
    unsigned hash=map->calculateHashValue(map, key, key_len);
    while(map->entries[hash]!=NULL){
        if(strcmp(map->entries[hash]->key, key)==0){
            return 1;
        }
        hash++;
        if(hash==map->capacity){
            hash=0;
        }
    }
    return 0;
}
static void insertEntry(StringCountHashMap* map, const char * key, const unsigned key_len, const unsigned value){
    unsigned hash=map->calculateHashValue(map, key, key_len);
    while(map->entries[hash]!=NULL){
        if(strcmp(map->entries[hash]->key, key)==0){
            map->entries[hash]->count=value;
            return ;
        }
        hash++;
        if(hash==map->capacity){
            hash=0;
        }
    }
    map->entries[hash]=malloc(sizeof(StringHashMapEntry));
    map->entries[hash]->key=malloc(sizeof(char)*(key_len+1));
    map->entries[hash]->key[key_len]='\0';
    strcpy(map->entries[hash]->key,key);
    map->entries[hash]->count=value;
}

static void printHashMap(StringCountHashMap* map){
    for(int i=0; i<map->capacity; i++){
        if(map->entries[i]!=NULL){
            printf("word: %s, frequency: %d\n", map->entries[i]->key, map->entries[i]->count);
        }
    }
}

StringCountHashMap* createStringHashMap(unsigned size){
    StringCountHashMap * map=malloc(sizeof(StringCountHashMap));
    map->capacity=2*size;
    map->entries=malloc(sizeof(StringHashMapEntry*)*map->capacity);
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

void freeStringHashMap(StringCountHashMap*map){
    for(unsigned i=0; i<map->capacity; i++){
        if(map->entries[i]!=NULL){
            free(map->entries[i]->key);
            free(map->entries[i]);
        }
    }
    free(map->entries);
    free(map);
    printf("successfully free string map\n");
}