
#ifndef TRIE_H
#define TRIE_H

#include <string>
using namespace std;

const int ALPHABET_SIZE = 26;

struct TrieNode
{
    struct TrieNode* children[ALPHABET_SIZE];
    // isEndOfWord - true, ���� ���� �������� ������ �����
    bool isEndOfWord;
};
void findWords(TrieNode* node, vector<char>& suggestion, const string& prefix);

// ���������� ����� ���� � ������� ������
TrieNode* getNewNode();

// ��������� ���� � ������
void insert(TrieNode* root, string key);

// ���������, ���� �� ���� � ������
bool search(TrieNode* root, string key);

// ������� ���� �� ������
TrieNode* remove(TrieNode* root, string key, int depth = 0);

#endif
