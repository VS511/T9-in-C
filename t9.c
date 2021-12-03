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
    char* filename = argv[1];
    /* FILE* f;
    f = fopen(argv[1], "r"); // Opening our input dictionary
    if (f == NULL) {
        printf("Invalid Input");
    } else {
        // Build DS Code
    } */
    
    /* do {
        printf("Enter the numeric input. Enter "#" to toggle words.");
        scanf("%s", input);

    } while (strcmp("#", input) == 0)
    
    char word[20]; */
    

    // make root node
    TrieNode* root = makeNode();

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

    return EXIT_SUCCESS;
}