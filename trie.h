#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef _TRIE
#define _TRIE

#define NUM_CHILDREN 10
#define DEFAULT_SIZE 4

// typedef struct TrieNode;
// typedef struct Trie;

// Recursive TrieNode Data Structure
// char** words: Array of words at a node, NULL if node is not word end
// size: Max number of words per node.

typedef struct TrieNode {
   int size;
   char** words;
   struct TrieNode* children[NUM_CHILDREN];
} TrieNode;

TrieNode* make_node();

int letter_to_digit(char letter);
int node_insert(TrieNode *previous_node, char word[], int current_letter);
int build_Trie(TrieNode* root, char* filename);
TrieNode* get_node(TrieNode* root, char* digits);
void free_Trie(TrieNode* root);

#endif 