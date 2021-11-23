#include <stdio.h>
#include <string.h>


// TrieNode Data Structure
typedef struct TrieNode {
   char *word;
   struct TrieNode *children[NUM_CHILDREN];
} TrieNode;

// Trie Data Structure
typedef struct Trie {
   TrieNode *root;
} Trie;

TrieNode* makeNode() {
  TrieNode *t = (TrieNode*) malloc(sizeof(TrieNode));
  if (t == NULL) {
    return NULL;
  }
  for (int i = 0; i < NUM_NODES; i++) {
    t->next[i] = NULL;
  }
  t->word = NULL;
  return t;
}

// Function to insert a new Node
// previous_node: 
// word: String we're trying to add to the trieset
// current_letter: 
int node_insert(TrieNode *previous_node, char word[], int current_letter) {
   if (word[current_letter] == '\0') { // word is empty
       // word is empty
   }
   int digit = letter_to_digit(word[current_letter]);

   if (previous_node->children[digit] == NULL) { 
       // node doesn't exist, create it
   } else { // node already exists
       current_node = //next unexamined child of previous node
   }
   if (word[current_letter + 1] == '\0') { // at the end of the word     
       if (current_node->word == NULL) { // current node doesn’t have a word yet
		// save word here
       } else {  
           // current node already has a word, add it as an additional completion
       }
   } else { // not at the end of the string, so continue to the next letter
       return node_insert(current_node, word, current_letter + 1);
   }
}

