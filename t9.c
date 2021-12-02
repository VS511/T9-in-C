#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include "trie.h"

void usage (char* program) {
    printf("Usage: %s FILE\n", program);
    exit(EXIT_FAILURE);
}

int main (int argc, char* argv[]) {
    // Check for correct number of arguments passed
    if (argc != 2) {
        // Print usage and exit
        usage(argv[0]);
    }

    FILE* f;
    f = fopen(argv[1], "r"); // Opening our input dictionary
    if (f == NULL) {
        printf("Invalid Input");
    } else {
        // Build DS Code
    }
    
    do {
        printf("Enter the numeric input. Enter "#" to toggle words.");
        scanf("%s", input);

    } while (strcmp("#", input) == 0)
    
    char word[20];
    

    // make root node
    TrieNode* root = makeNode();

    // open the input text file
    //char* filename = argv[1];
    build_Dictionary(root, f);

    return EXIT_SUCCESS;
}