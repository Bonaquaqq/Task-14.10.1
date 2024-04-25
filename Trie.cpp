#include <iostream>
#include <string>
#include <vector>
#include "Trie.h" 

using namespace std;


void buildTrie(TrieNode* root, const vector<string>& dictionary) {
    for (const string& word : dictionary) {
        insert(root, word);
    }
}


void autoComplete(TrieNode* root, const string& prefix) {
    TrieNode* node = root;


    for (char ch : prefix) {
        int index = ch - 'a';
        if (!node->children[index]) {
            cout << "Нет слов, начинающихся с этого префикса." << endl;
            return;
        }
        node = node->children[index];
    }


    vector<char> suggestion;
    findWords(node, suggestion, prefix);
}


void findWords(TrieNode* node, vector<char>& suggestion, const string& prefix) {

    if (node->isEndOfWord) {
        cout << prefix;
        for (char ch : suggestion) {
            cout << ch;
        }
        cout << endl;
    }


    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        if (node->children[i]) {
            suggestion.push_back(i + 'a');
            findWords(node->children[i], suggestion, prefix);
            suggestion.pop_back();
        }
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    TrieNode* root = getNewNode();


    vector<string> dictionary = { "apple", "banana", "app", "ape", "dog", "cat", "car", "care" };


    buildTrie(root, dictionary);


    string input;
    while (true) {
        cout << "Введите часть слова для автодополнения (или 'exit' для выхода): ";
        cin >> input;
        if (input == "exit") {
            break;
        }
        autoComplete(root, input);
    }

    return 0;
}

TrieNode* getNewNode()
{
    TrieNode* newNode = new TrieNode;
    newNode->isEndOfWord = false;
    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        newNode->children[i] = nullptr;
    }
    return newNode;
}


void insert(TrieNode* root, string key)
{
}

bool search(TrieNode* root, string key)
{
    return false;
}

TrieNode* remove(TrieNode* root, string key, int depth)
{
    return nullptr;
}
