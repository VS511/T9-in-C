#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "trie.h"

#define NUM_CHILDREN 8 // or 10?
// #define NUM_NODES 10

// Resursive TrieNode Data Structure
/* typedef struct TrieNode {
   char *word;
   struct TrieNode *children[NUM_CHILDREN];
} TrieNode; */

// Trie Data Structure
/* typedef struct Trie {
   TrieNode *root;
} Trie; */

TrieNode* makeNode() {
  TrieNode *t = (TrieNode*) malloc(sizeof(TrieNode));
  if (t == NULL) {
    return NULL;
  }
  for (int i = 0; i < NUM_CHILDREN; i++) {
    t->children[i] = NULL;
  }
  t->words[0] = NULL;
  return t;
}

// Function to map letters to digits
// char

int letter_to_digit(char letter) {
  char ref[26] = {2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7,
          8, 8, 8, 9, 9, 9, 9};
  int i = letter - 'a';
  return ref[i];
}


// Function to insert a new Node
// previous_node: 
// word: String we're trying to add to the trieset
// current_letter: 
int node_insert(TrieNode *previous_node, char word[], int current_letter) {
  if (word[current_letter] == '\0') {
    // word is empty
    printf("word is empty");
    return EXIT_FAILURE;
  }
  int digit = letter_to_digit(word[current_letter]); 

  TrieNode* current_node;
  if (previous_node->children[digit] == NULL) { 
    // node doesn't exist, create it
    previous_node->children[digit] = makeNode();
  }
  current_node = previous_node->children[digit]; //next unexamined child of previous node

  if (word[current_letter + 1] == '\0') { // at the end of the word     
    if (current_node->words[0] == NULL) { // current node doesn’t have a word yet
      current_node->words[0] = word;
    } else {
      // current node already has a word, add it as an additional completion
      int i = 1;
      while (current_node->words[i] != NULL) {
        i++;
      }

    }
  } else { // not at the end of the string, so continue to the next letter
    return node_insert(current_node, word, current_letter + 1);
  }
  return 0;
}

int read_Dictionary(TrieNode *previous_node, FILE* dictionary) {
  
}