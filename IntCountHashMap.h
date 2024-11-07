#ifndef INTCOUNTHASHMAP_H
#define INTCOUNTHASHMAP_H
#include"stdio.h"
#include"stdlib.h"
typedef struct _IntHashMapEntry{
    int key;
    int value;
}IntHashMapEntry;
typedef struct _IntHashMap{
    IntHashMapEntry** entries;
    unsigned capacity;
    // struct _IntHashMap * (*createHashMap)(unsigned size);
    unsigned (*calculateHashValue)(struct _IntHashMap* map, const int key);
    unsigned (*getOrDefault)(struct _IntHashMap*map, const int key);
    int (*existInTable)(struct _IntHashMap* map, const int key);
    void (*insertEntry)(struct _IntHashMap* map, const int key, const int value);
    void (*printHashMap)(struct _IntHashMap* map);

}IntHashMap;
IntHashMap* createIntHashMap(unsigned size);
void freeIntHashMap(IntHashMap*map);
#endif