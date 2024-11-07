#include"StringCountHashMap.h"
#include"IntCountHashMap.h"
#include "time.h"
#define LEN 100000
// #define WORDLEN 10
void test_string_map(){
    char * words[LEN];
    for(unsigned i=0; i<LEN; i++){
        unsigned word_len=rand()%6+6;
        words[i]=malloc(sizeof(char)*(word_len+1));
        words[i][word_len]='\0';
        for(unsigned j=0; j<word_len; j++){
            words[i][j]=(char)(rand()%26+'a');
        }
    }
    StringCountHashMap* map=createStringHashMap(LEN);
    for(unsigned i=0; i<LEN; i++){
        unsigned frequency=map->getOrDefault(map, words[i], strlen(words[i]))+1;
        map->insertEntry(map, words[i], strlen(words[i]), frequency);
    }
    // printf("hello world");
    // printHashMap(map);
    for(unsigned i=0; i<LEN; i++){
        unsigned word_len=rand()%6+6;
        words[i]=malloc(sizeof(char)*(word_len+1));
        for(unsigned j=0; j<word_len; j++){
            words[i][j]=(char)(rand()%26+'a');
        }
    }
    clock_t start_time=clock();
    for(unsigned i=0; i<LEN; i++){
        map->existInTable(map, words[i], strlen(words[i]));
        // printf("Whether word %s exist in map:%d\n",words[i], existInTable(map, words[i], strlen(words[i])));
    }
    clock_t end_time=clock();
    double runtime=(double)(end_time-start_time)/CLOCKS_PER_SEC;
    printf("time spent for checking string map:%f second\n", runtime);
    freeStringHashMap(map);
}
void test_int_map(){
    // int arr[10]={1, 4, 5, 2, 4, 3, 6, 10, 8, 6};
    // IntHashMap* map=createIntHashMap(10);
    // for(unsigned i=0; i<10; i++){
    //     // printf("enter the loop %d", i);
    //     unsigned frequency=map->getOrDefault(map, arr[i])+1;
    //     map->insertEntry(map, arr[i], frequency);
    // }
    // map->printHashMap(map);
    int arr[LEN];
    for(unsigned i=0; i<LEN; i++){
        arr[i]=(rand()<<15)+rand();
    }
    IntHashMap* map=createIntHashMap(LEN);
    for(unsigned i=0; i<LEN; i++){
        unsigned frequency=map->getOrDefault(map, arr[i])+1;
        map->insertEntry(map, arr[i], frequency);
    }
    // printf("hello world");
    // printHashMap(map);
    for(unsigned i=0; i<LEN; i++){
        arr[i]=(rand()<<15)+rand();
    }
    clock_t start_time=clock();
    for(unsigned i=0; i<LEN; i++){
        map->existInTable(map, arr[i]);
        // printf("Whether number %d exist in map:%d\n",arr[i], map->existInTable(map, arr[i]));
    }
    clock_t end_time=clock();
    double runtime=(double)(end_time-start_time)/CLOCKS_PER_SEC;
    printf("time spent for checking int map:%f second\n", runtime);
    freeIntHashMap(map);
}
int main(){
    test_string_map();
    test_int_map();
    return 0;
}