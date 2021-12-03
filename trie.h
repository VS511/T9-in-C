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

TrieNode* make_node();

int letter_to_digit(char letter);
int node_insert(TrieNode *previous_node, char word[], int current_letter);
<<<<<<< HEAD

int build_Trie(TrieNode* root, char* filename);

TrieNode* get_node(TrieNode* root, char* digits);

void free_Trie(TrieNode* root);
=======
int build_dictionary(TrieNode* root, char* filename);
TrieNode* search_node(TrieNode* root, char* inputdigits);
>>>>>>> bf99ad7b54642c8f595c00c419e72dc6a8e70a61

#endif 