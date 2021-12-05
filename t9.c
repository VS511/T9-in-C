// David Maltby & Vaibhav Singh
// 12/04/2021

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "trie.h"

#define MAX_USER_INPUT_LENGTH 40 // Maximum length of number of digits entered by user

void usage(char * program) {
  printf("Usage: %s FILE\n", program);
  exit(EXIT_FAILURE);
}

int main(int argc, char * argv[]) {
  // Check for correct number of arguments passed
  if (argc != 2) {
    usage(argv[0]);
  }
  char * filename = argv[1];
  TrieNode * root = make_node();   // Make root node
  build_Trie(root, filename);   // Build trie from given file

  // Initialize variables
  char * input;
  char buff[MAX_USER_INPUT_LENGTH];
  TrieNode * node;
  TrieNode * prev_node = NULL;
  int pound_count = 0;

  // Initial text output
  printf("Enter \"exit\" to quit\n");
  printf("Enter Key Sequence (or \"#\" for next word):\n");

  // First user input
  scanf("%s", buff);
  input = (char * ) buff;

  // User input loop, until user enters "exit"
  while (strcmp(input, "exit") != 0) {
    // Check if input starts with '#'
    if (input[0] == '#') {
      int i = 0;
      // Count how many subsequent '#'s there are
      while (i < strlen(input) && input[i] == '#') {
        pound_count++;
        i++;
      }
      if (i == strlen(input)) {    // All chars were '#'
        if (prev_node != NULL && pound_count < prev_node -> size && prev_node -> words[pound_count] != NULL) {
          printf("\'%s\'\n", prev_node -> words[pound_count]);  // Print corresponding word
        } else {
          prev_node = NULL;
          pound_count = 0;
          printf("There are no more T9onyms\n");
        }
      } else {  // chars other than '#' followed, invalid input
        pound_count = 0;
        printf("Not found in current dictionary.\n");
      }
    } else {    // Sequence doesn't start with '#'
      node = get_node(root, input); // might want to move THIS
      prev_node = node;
      pound_count = 0;
      if (node == NULL) {   // Node not found -- separate test for invalid input??
        printf("Not found in current dictionary.\n");
      } else if (strchr(input, '#') != NULL) { //   Sequence contains '#'
        //  Go through similar process as above for # case (basically repeated code from this line until the last else statement)
        char * pounds = strchr(input, '#');
        int i = 0;
        // Count how many subsequent '#'s there are
        while (i < strlen(pounds) && pounds[i] == '#') {
          pound_count++;
          i++;
        }
        if (i == strlen(pounds)) { // all chars were '#'
          if (node -> words[i] != NULL) {
            printf("\'%s\'\n", node -> words[i]); // Print corresponding word
          } else { // Too many '#'s, word doesn't exist
            printf("There are no more T9onyms\n");
          }
        } else { // chars other than '#' followed, invalid input
          pound_count = 0;
          printf("Not found in current dictionary.\n");
        }
      } else {
        printf("\'%s\'\n", node -> words[0]);
      }
    }
    printf("Enter Key Sequence (or \"#\" for next word):\n");
    scanf("%s", buff);
    input = (char * ) buff;
  }
  // Free memory
  free_Trie(root);
  free(root);

  return EXIT_SUCCESS;
}