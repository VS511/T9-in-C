// David Maltby & Vaibhav Singh
// 12/04/2021

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "trie.h"

#define MAX_WORD_SIZE 30

// Function to initialize a single node
// Returns a node
TrieNode * make_node() {
  TrieNode * t = (TrieNode * ) malloc(sizeof(TrieNode));
  if (t == NULL) {
    return NULL;
  }
  t -> words = (char ** ) malloc(sizeof(char * ) * DEFAULT_SIZE);
  if (t -> words == NULL) {
    return NULL;
  }
  for (int i = 0; i < DEFAULT_SIZE; i++) {
    t -> words[i] = NULL;
  }
  t -> size = DEFAULT_SIZE;
  for (int i = 0; i < NUM_CHILDREN; i++) {
    t -> children[i] = NULL;
  }
  return t;
}

// Function to map letters to digits
//    char letter: Input character to be mapped to a digit
//
//    Returns digit conversion   
int letter_to_digit(char letter) {
  char ref[26] = {
    2, 2, 2, // ABC
    3, 3, 3, // DEF
    4, 4, 4, // JKL
    5, 5, 5, // MNO
    6, 6, 6, // LMN
    7, 7, 7, 7, // PQRS 
    8, 8, 8, // TUV
    9, 9, 9, 9 // WXYZ
  };
  int j = letter - 'a';
  return ref[j];
}

// Function to insert a new Node
//    previous_node: The node where we start the 
//    word: String we're trying to add to the trieset
//    current_letter: The current letter for which node is to be inserted
int node_insert(TrieNode * previous_node, char word[], int current_letter) {
  if (word[current_letter] == '\0') {
    // Word is empty
    printf("word is empty");
    return EXIT_FAILURE;
  }
  int digit = letter_to_digit(word[current_letter]);
  TrieNode * current_node;

  // Node doesn't exist, create it
  if (previous_node -> children[digit] == NULL) {
    previous_node -> children[digit] = make_node();
  }
  current_node = previous_node -> children[digit]; // Next unexamined child of previous node
  if (current_node == NULL) {
    return 0;
  }

  int current_size = current_node -> size;

  if (word[current_letter + 1] == '\0') { // End of word   

    if (current_node -> words[0] == NULL) { // Current node doesn’t have a word yet
      current_node -> words[0] = word;
    } else {
      // Current node already has a word, add it as an additional completion
      int i = 1;
      while (current_node -> words[i] != NULL) {
        i++;
        if (i >= current_size) {
          // Resize words array
          current_size = current_size + DEFAULT_SIZE;
          current_node -> size = current_size;
          current_node -> words = (char ** ) realloc(current_node -> words, sizeof(char * ) * current_size);
          for (int j = i; j < current_size; j++) {
            current_node -> words[j] = NULL;
          }
        }
      }
      current_node -> words[i] = word;
    }
  } else { // Not at the end of the string, so continue to the next letter
    return node_insert(current_node, word, current_letter + 1);
  }
  return 0;
}

// Function to iterate through each word in file and add to the trie
//    root: root of the trie being constructed
//    filename: Input file
int build_Trie(TrieNode * root, char * filename) {
  FILE * dictionary = fopen(filename, "r");

  // Check if file exists
  if (!dictionary) {
    fprintf(stderr, "Failed to open %s for input.\n", filename);
    return EXIT_FAILURE;
  }

  // Create a buffer to store the lines
  char * buff = (char * ) malloc(sizeof(char) * MAX_WORD_SIZE);
  size_t buff_size = MAX_WORD_SIZE;

  char * line = fgets(buff, buff_size, dictionary);
  size_t word_len = strlen(buff);

  // Check for newline character
  if (buff[word_len - 1] == '\n') {
    buff[word_len - 1] = '\0';
    word_len--;
  }

  // Add all words to dictionary
  char * word;               
  while (line != NULL) {
    // Get word from buffer
    word = (char * ) malloc(sizeof(char) * (word_len + 1));
    strncpy(word, buff, word_len + 1);

    // Add current word to dictionary
    node_insert(root, word, 0);

    // Store next word in the buffer
    line = fgets(buff, buff_size, dictionary);
    word_len = strlen(buff);
    if (buff[word_len - 1] == '\n') {
      buff[word_len - 1] = '\0';
      word_len--;
    }
  }

  free(buff);
  fclose(dictionary);
  return 0;
}

// Function to return the node corresponding to input "digits"
//    root: Root of the TrieNode data structure
//
//    Returns the requried node
TrieNode * get_node(TrieNode * root, char * digits) {
  // Length of digit sequence (may have to account for /0 or /n, we will see)
  size_t digits_len = strlen(digits);

  // Initialize nodes
  TrieNode * current_node = root;
  TrieNode * next_node;
  int n;

  // Find node corresponding to digit sequence
  for (int i = 0; i < digits_len; i++) {
    // If '#' symbol, return current_node
    // Count number of '#'s and access corresponding index in words array
    if (digits[i] == '#') {
      return current_node;
    }
    n = digits[i] - '0';
    next_node = current_node -> children[n];

    // If node doesn't exist, return it as NULL and we will print according message
    if (next_node == NULL) {
      return NULL;
    } else {
      current_node = next_node;
    }
  }
  return current_node;
}

// Function to recursively frees each node in the trie
//    root: Root of the TrieNode data structure
void free_Trie(TrieNode * node) {
  for (int i = 2; i < NUM_CHILDREN; i++) {
    if (node -> children[i] != NULL) {
      free_Trie(node -> children[i]);
      free(node -> children[i]);
    }
  }
  // Clears the words on whichever node is running the code
  if (node -> words != NULL) {
    for (int i = 0; i < node -> size; i++) {
      free(node -> words[i]);
    }
    free(node -> words);
  }
}