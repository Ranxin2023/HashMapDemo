#ifndef STRINGCOUNTHASHMAP_H
#define STRINGCOUNTHASHMAP_H
#include"stdio.h"
#include"stdlib.h"
#include"string.h"
typedef struct _HashMapEntry{
    char * key;
    unsigned count;
} HashMapEntry;
typedef struct _StringCountHashMap{
    HashMapEntry ** entries;
    unsigned capacity;

}StringCountHashMap;

StringCountHashMap* createHashMap(unsigned size);
unsigned calculateHashValue(StringCountHashMap*map,const char * key, unsigned key_len);
int existInTable(StringCountHashMap* map, const char * key, unsigned key_len);
unsigned getOrDefault(StringCountHashMap*map, const char * key, unsigned key_len);
void insertEntry(StringCountHashMap* map, const char * key, unsigned key_len ,unsigned value);
void printHashMap(StringCountHashMap* map);
#endif
