#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include "trie.h"

// **** Not sure if we should have this or not but I don't see how to avoid it *****
#define MAX_USER_INPUT_LENGTH 40

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
<<<<<<< HEAD
    char* filename = argv[1];
    /* FILE* f;
    f = fopen(argv[1], "r"); // Opening our input dictionary
    if (f == NULL) {
        printf("Invalid Input");
    } else {
        // Build DS Code
    } */
=======

    TrieNode* root = make_node();
    TrieNode* current = root;
>>>>>>> bf99ad7b54642c8f595c00c419e72dc6a8e70a61
    
    /* do {
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

<<<<<<< HEAD
    } while (strcmp("#", input) == 0)
    
    char word[20]; */
    
=======
        // Still need to implement the pound case.

    } while (fgets(userinput, MAX_WORD_SIZE, stdin))
    
    char word[20];
>>>>>>> bf99ad7b54642c8f595c00c419e72dc6a8e70a61

    // make root node


<<<<<<< HEAD
    // build trie from given file
    build_Trie(root, filename);

    // initialize variables
    char input[MAX_USER_INPUT_LENGTH];
    TrieNode* node;
    TrieNode* prev_node = NULL;
    int pound_count = 0;

    // initial text output
    printf("Enter \"exit\" to quit\n");
    printf("Enter Key Sequence (or \"#\" for next word):\n");

    // first user input
    scanf("%s", input);

    // main process, should account for all cases
    while (strcmp(input, "exit") != 0) {
        node = get_node(root, input);
        // check if input starts with '#'
        if (input[0] == '#') {
            pound_count++;
            int i = 1;
            // count how many subsequent '#'s there are
            while (i < strlen(input) && input[i] == '#') {
                pound_count++;
                i++; 
            }
            // three possible outputs (for now)
            if (i + 1 == strlen(input)) {                   // all chars were '#'
                if (prev_node->words[i] != NULL) {          
                    printf("\'%s\'\n", prev_node->words[i]);  // print corresponding word
                } else {                                    // too many '#'s, word doesn't exist
                    printf("There are no more T9onyms\n");
                }
            } else {                                        // chars other than '#' followed, invalid input
                pound_count = 0;
                printf("Not found in current dictionary.\n");
            }
        } else {                                            // sequence doesn't start with '#'
            pound_count = 0;
            if (node == NULL) {                             // node not found -- separate test for invalid input??
                printf("Not found in current dictionary.\n");
            } else if (strchr(input, '#') != NULL) {        // input contains '#'
                // go through similar (same?) process as above
                pound_count++;
            } else {
                printf("\'%s\'\n", node->words[0]);
            }
        }
        prev_node = node;
        scanf("%s", input);
    }

=======
    // open the input text file
    //char* filename = argv[1];
    build_Dictionary(root, f);
>>>>>>> bf99ad7b54642c8f595c00c419e72dc6a8e70a61
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