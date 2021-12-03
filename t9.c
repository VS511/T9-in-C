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

    TrieNode* root = make_node();
    TrieNode* current = root;
    
    do {
        printf("Enter the numeric input. Enter "#" to toggle words.");
        current = root;

        // Exit program if user input is "exit"
        if (strstr(userinput, "exit") != NULL) {
			exit(1);
		}

        for (int i = 0; i < (strlen(userinput)-1); i++) {
			if (current != NULL) {
            }
        }

        // Still need to implement the pound case.

    } while (fgets(userinput, MAX_WORD_SIZE, stdin))
    
    char word[20];

    // make root node


    // open the input text file
    //char* filename = argv[1];
    build_Dictionary(root, f);
    return EXIT_SUCCESS;
}

/* FILE* f;
    f = fopen(argv[1], "r"); // Opening our input dictionary
    if (f == NULL) {
        printf("Invalid Input");
    } else {
        // Build DS Code
    }
*/