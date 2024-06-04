#include <stdio.h>
#include <string.h>
#include <stdbool.h>
bool hasSequentialCohesion(char* sentence) {
    char* keywords[] = {"first", "next", "after", "then"};
    int numKeywords = sizeof(keywords) / sizeof(keywords[0]);
    int i;
    for (i = 0; i < numKeywords; i++) {
        if (strstr(sentence, keywords[i]) != NULL) {
            return true;
        }
    }
    return false;
}
bool hasTemporalCohesion(char* sentence) {
    char* keyword = "initialize";

    if (strstr(sentence, keyword) != NULL) {
        return true;
    }

    return false;
}
int main() {
    char sentence[1000];
    printf("Enter a sentence to describe the function of the module: ");
    fgets(sentence,sizeof(sentence), stdin);
    if (hasSequentialCohesion(sentence)) {
        printf("The sentence has sequential or communicational cohesion.\n");
    } else if (hasTemporalCohesion(sentence)) {
        printf("The sentence has temporal cohesion.\n");
    } else {
        printf("The sentence does not exhibit specific cohesion.\n");
    }
    return 0;
}
