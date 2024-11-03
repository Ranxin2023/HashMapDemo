#include"StringCountHashMap.h"
StringCountHashMap* createHashMap(unsigned size){
    StringCountHashMap * map=malloc(sizeof(StringCountHashMap));
    map->capacity=2*size;
    map->entries=malloc(sizeof(HashMapEntry*)*map->capacity);
    for(unsigned i=0; i<map->capacity; i++){
        map->entries[i]=NULL;
    }
    return map;
}

unsigned calculateHashValue(StringCountHashMap* map, const char * key, const unsigned key_len){
    unsigned hash=5381;
    for(unsigned i=0; i<key_len; i++){
        hash = ((hash << 5) + hash) + key[i];
        hash%=map->capacity;
    }
    
    return hash;
}
unsigned getOrDefault(StringCountHashMap*map, const char * key, const unsigned key_len){
    unsigned hash=calculateHashValue(map, key, key_len);
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
int existInTable(StringCountHashMap* map, const char * key, unsigned key_len){
    unsigned hash=calculateHashValue(map, key, key_len);
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
void insertEntry(StringCountHashMap* map, const char * key, const unsigned key_len, const unsigned value){
    unsigned hash=calculateHashValue(map, key, key_len);
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
    map->entries[hash]=malloc(sizeof(HashMapEntry));
    map->entries[hash]->key=malloc(sizeof(char)*(key_len+1));
    map->entries[hash]->key[key_len]='\0';
    strcpy(map->entries[hash]->key,key);
    map->entries[hash]->count=value;
}

void printHashMap(StringCountHashMap* map){
    for(int i=0; i<map->capacity; i++){
        if(map->entries[i]!=NULL){
            printf("word: %s, frequency: %d\n", map->entries[i]->key, map->entries[i]->count);
        }
    }
}