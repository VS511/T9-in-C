#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include "trie.h"

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
    
    // make root node
    TrieNode* root = make_node();

    // build trie from given file
    build_Trie(root, filename);

    // initialize variables
    char* input;
    char buff[MAX_USER_INPUT_LENGTH];
    /* int input;
    char buff[MAX_USER_INPUT_LENGTH];
    char* digits; */
    // char digits[MAX_USER_INPUT_LENGTH];
    TrieNode* node;
    TrieNode* prev_node = NULL;
    int pound_count = 0;

    // initial text output
    printf("Enter \"exit\" to quit\n");
    printf("Enter Key Sequence (or \"#\" for next word):\n");

    // first user input
    scanf("%s", buff);
    input = (char*) buff;
    /* scanf("%d", &input);
    sprintf(buff, "%d", input);
    digits = (char*) buff; */

    // char* input = "76257#";

    // main process, should account for all cases
    while (strcmp(input, "exit") != 0) {
        // check if input starts with '#'
        if (input[0] == '#') {
            int i = 0;
            // count how many subsequent '#'s there are
            while (i < strlen(input) && input[i] == '#') {
                pound_count++;
                i++; 
            }
            // three possible outputs (for now)
            if (i == strlen(input)) {                   // all chars were '#'
                if (prev_node != NULL && pound_count < prev_node->size && prev_node->words[pound_count] != NULL) {
                    printf("\'%s\'\n", prev_node->words[pound_count]);  // print corresponding word
                } else {
                    prev_node = NULL;
                    pound_count = 0;
                    printf("There are no more T9onyms\n");
                }         
            } else {                                        // chars other than '#' followed, invalid input
                pound_count = 0;
                printf("Not found in current dictionary.\n");
            }
        } else {                                            // sequence doesn't start with '#'
            node = get_node(root, input);           // might want to move THIS
            prev_node = node;
            pound_count = 0;
            if (node == NULL) {                             // node not found -- separate test for invalid input??
                printf("Not found in current dictionary.\n");
            } else if (strchr(input, '#') != NULL) {        // sequence contains '#'
                // go through similar process as above for # case (basically repeated code from this line until the last else statement)
                char* pounds = strchr(input, '#');
                int i = 0;
                // count how many subsequent '#'s there are
                while (i < strlen(pounds) && pounds[i] == '#') {
                    pound_count++;
                    i++; 
                }
                // three possible outputs (for now)
                if (i == strlen(pounds)) {                   // all chars were '#'
                    if (node->words[i] != NULL) {          
                        printf("\'%s\'\n", node->words[i]);  // print corresponding word
                    } else {                                    // too many '#'s, word doesn't exist
                        printf("There are no more T9onyms\n");
                    }
                } else {                                        // chars other than '#' followed, invalid input
                    pound_count = 0;
                    printf("Not found in current dictionary.\n");
                }
            } else {
                printf("\'%s\'\n", node->words[0]);
            }
        }
        printf("Enter Key Sequence (or \"#\" for next word):\n");
        scanf("%s", buff);
        input = (char*) buff;
        /* scanf("%d", &input);
        sprintf(buff, "%d", input);
        digits = (char*) buff; */
    }

    //

    free_Trie(root);
    free(root);

    return EXIT_SUCCESS;
}