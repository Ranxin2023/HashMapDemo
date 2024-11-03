#include"StringCountHashMap.h"
#include "time.h"
#define WORDSLEN 100000
// #define WORDLEN 10
int main(){
    char * words[WORDSLEN];
    for(unsigned i=0; i<WORDSLEN; i++){
        unsigned word_len=rand()%6+6;
        words[i]=malloc(sizeof(char)*(word_len+1));
        words[i][word_len]='\0';
        for(unsigned j=0; j<word_len; j++){
            words[i][j]=(char)(rand()%26+'a');
        }
    }
    StringCountHashMap* map=createHashMap(WORDSLEN);
    for(unsigned i=0; i<WORDSLEN; i++){
        unsigned frequency=getOrDefault(map, words[i], strlen(words[i]))+1;
        insertEntry(map, words[i], strlen(words[i]), frequency);
    }
    // printf("hello world");
    // printHashMap(map);
    for(unsigned i=0; i<WORDSLEN; i++){
        unsigned word_len=rand()%6+6;
        words[i]=malloc(sizeof(char)*(word_len+1));
        for(unsigned j=0; j<word_len; j++){
            words[i][j]=(char)(rand()%26+'a');
        }
    }
    clock_t start_time=clock();
    for(unsigned i=0; i<WORDSLEN; i++){
        existInTable(map, words[i], strlen(words[i]));
        // printf("Whether word %s exist in map:%d\n",words[i], existInTable(map, words[i], strlen(words[i])));
    }
    clock_t end_time=clock();
    double runtime=(double)(end_time-start_time)/CLOCKS_PER_SEC;
    printf("time spent for checking:%f second", runtime);
    return 0;
}