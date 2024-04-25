
#ifndef TRIE_H
#define TRIE_H

#include <string>
using namespace std;

const int ALPHABET_SIZE = 26;

struct TrieNode
{
    struct TrieNode* children[ALPHABET_SIZE];
    // isEndOfWord - true, если ключ является концом слова
    bool isEndOfWord;
};
void findWords(TrieNode* node, vector<char>& suggestion, const string& prefix);

// Возвращает новый узел с пустыми детьми
TrieNode* getNewNode();

// Вставляет ключ в дерево
void insert(TrieNode* root, string key);

// Проверяет, есть ли ключ в дереве
bool search(TrieNode* root, string key);

// Удаляет ключ из дерева
TrieNode* remove(TrieNode* root, string key, int depth = 0);

#endif
