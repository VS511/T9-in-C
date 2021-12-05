// David Maltby & Vaibhav Singh
// 12/04/2021

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef _TRIE
#define _TRIE

#define NUM_CHILDREN 10 // Maximum number of children per node
#define DEFAULT_SIZE 4 // Maximum number of words per node (by default)

// typedef struct TrieNode;
// typedef struct Trie;

// Recursive TrieNode Data Structure
//    char** words: Array of words at a node, NULL if node is not word end
//    size: Max number of words per node.

typedef struct TrieNode {
   int size;
   char** words;
   struct TrieNode* children[NUM_CHILDREN];
} TrieNode;

TrieNode* make_node();
// Function to map letters to digits
//    char letter: Input character to be mapped to a digit
//
//    Returns digit conversion 
int letter_to_digit(char letter);

// Function to insert a new Node
//    previous_node: The node where we start the 
//    word: String we're trying to add to the trieset
//    current_letter: The current letter for which node is to be inserted
int node_insert(TrieNode *previous_node, char word[], int current_letter);

// Function to iterate through each word in file and add to the trie
//    root: root of the trie being constructed
//    filename: Input file
int build_Trie(TrieNode* root, char* filename);

// Function to return the node corresponding to input "digits"
//    root: Root of the TrieNode data structure
//
//    Returns the requried node
TrieNode* get_node(TrieNode* root, char* digits);

// Function to recursively frees each node in the trie
//    root: Root of the TrieNode data structure
void free_Trie(TrieNode* root);

#endif 