#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include "trie.h"

void usage(char* program) {
    printf("Usage: %s FILE\n", program);
    exit(EXIT_FAILURE);
}

int main (int argc, char* argv[]) {
    // Check for correct number of arguments passed
    if (argc != 2) {
        // Print usage and exit
        usage(argv[0]);
    }

    // make root node
    TrieNode* root = makeNode();

    // open the input text file
    char* filename = argv[1];

    build_Dictionary(root, filename);

    return EXIT_SUCCESS;
}