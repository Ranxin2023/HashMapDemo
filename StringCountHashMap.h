#ifndef STRINGCOUNTHASHMAP_H
#define STRINGCOUNTHASHMAP_H
#include"stdio.h"
#include"stdlib.h"
#include"string.h"
typedef struct _StringHashMapEntry{
    char * key;
    unsigned count;
} StringHashMapEntry;
typedef struct _StringCountHashMap{
    StringHashMapEntry ** entries;
    unsigned capacity;
    struct _StringCountHashMap* (*createHashMap)(unsigned size);
    unsigned (*calculateHashValue)(struct _StringCountHashMap*map,const char * key, unsigned key_len);
    int (*existInTable)(struct _StringCountHashMap* map, const char * key, unsigned key_len);
    unsigned (*getOrDefault)(struct _StringCountHashMap* map, const char * key, unsigned key_len);
    void (*insertEntry)(struct _StringCountHashMap* map, const char * key, unsigned key_len ,unsigned value);
    void (*printHashMap)(struct _StringCountHashMap* map);

}StringCountHashMap;
StringCountHashMap* createStringHashMap(unsigned size);
void freeStringHashMap(StringCountHashMap*map);
#endif
