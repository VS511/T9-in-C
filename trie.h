#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef _TRIE
#define _TRIE

#define NUM_CHILDREN 10
#define DEFAULT_SIZE 4

// typedef struct TrieNode;
// typedef struct Trie;

// Resursive TrieNode Data Structure
typedef struct TrieNode {
   int size;
   char** words;
   struct TrieNode* children[NUM_CHILDREN];
} TrieNode;

// Trie Data Structure
/* typedef struct Trie {
   TrieNode *root;
} Trie; */

TrieNode* makeNode();

int letter_to_digit(char letter);

int node_insert(TrieNode *previous_node, char word[], int current_letter);

int build_Dictionary(TrieNode* root, char* filename);

#endif 