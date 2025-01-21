#include <stdio.h>
#include <string.h>
char * mergeAlternately(char * word1, char * word2){
    static char merged[200];
    int i=0,j=0,k=0;
    while(word1[i] != '\0' && word2[j] != '\0'){
        merged[k++]=word1[i++];
        merged[k++]=word2[j++];

    }
    while (word1[i] != '\0') {
        merged[k++] = word1[i++];
    }
    while (word2[j] != '\0') {
        merged[k++] = word2[j++];
    }

    merged[k] = '\0'; 
    return merged;
}