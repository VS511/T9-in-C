#include <stdio.h>
#include <string.h>

typedef struct TrieNode {
   char *word;
   struct TrieNode *children[NUM_CHILDREN];
} TrieNode;

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

