#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "trie.h"

// #define NUM_CHILDREN 8 // or 10?
// #define NUM_NODES 10
#define MAX_WORD_SIZE 15

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
  TrieNode* t = (TrieNode*) malloc(sizeof(TrieNode));
  if (t == NULL) {
    return NULL;
  }

  t->words = (char**) malloc(sizeof(char*) * DEFAULT_SIZE);
  if (t->words == NULL) {
    return NULL;
  }
  for (int i = 0; i < DEFAULT_SIZE; i++) {
    t->words[i] = NULL;
  }

  t->size = DEFAULT_SIZE;
  for (int i = 0; i < NUM_CHILDREN; i++) {
    t->children[i] = NULL;
  }
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
  char** current_words = current_node->words;
  int current_size = current_node->size;

  if (word[current_letter + 1] == '\0') { // at the end of the word     
    if (current_words[0] == NULL) { // current node doesn’t have a word yet
      current_words[0] = word;
    } else {
      // current node already has a word, add it as an additional completion
      int i = 1;
      while (current_words[i] != NULL) {
        i++;
        if (i > current_size) {
          current_node->words = realloc(current_words, current_size + DEFAULT_SIZE);
        }
      }
      current_node->words[i] = word;
    }
  } else { // not at the end of the string, so continue to the next letter
    return node_insert(current_node, word, current_letter + 1);
  }

  return 0;
}

// iterate through each word in file and add to the trie
int build_Dictionary(TrieNode* root, char* filename) {
  // open the file
  FILE* dictionary = fopen(filename, "r");

  // check if file exists
  if (!dictionary) {    
    fprintf(stderr, "Failed to open %s for input.\n", filename);
    return EXIT_FAILURE;
  }

  // create a buffer to store the lines
  char* buff = (char*) malloc(sizeof(char) * MAX_WORD_SIZE);
  size_t buff_size = MAX_WORD_SIZE;

  // store first word in the buffer
  char* line = fgets(buff, buff_size, dictionary);
  size_t word_len = strlen(buff);

  // check for newline character
  if (buff[word_len - 1] == '\n') {
    buff[word_len - 1] = '\0';
    word_len--;
  }

  // add all words to dictionary
  char* word;
  while(line[0] != '\0') {
    // get word from buffer
    word = (char*) malloc(sizeof(char) * (word_len + 1));
    strncpy(word, buff, word_len + 1);

    // add current word to dictionary
    node_insert(root, word, 0);

    // store next word in the buffer
    line = fgets(buff, buff_size, dictionary);
    word_len = strlen(buff);
    if (buff[word_len - 1] == '\n') {
      buff[word_len - 1] = '\0';
      word_len--;
    }
  }

  free(buff);
  free(word);

  return 0;
}