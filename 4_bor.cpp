#include <iostream>
#include <unordered_map>
#include <string>

struct TrieNode {
    std::unordered_map<char, TrieNode*> children;  // Дети текущего узла
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
        totalNodes = 1;  // Начинаем с корневого узла
    }

    void addWord(const std::string& word) {
        TrieNode* current = root;
        for (char c : word) {
            if (!current->children.count(c)) {
                current->children[c] = new TrieNode();
                totalNodes++;  // Добавляем новую вершину
            }
            current = current->children[c];
        }
    }

    int getTotalNodes() const {
        return totalNodes;
    }

private:
    TrieNode* root;
    int totalNodes;
};

int main() {
    Trie trie;
    int n = 10;  // Количество слов
    std::string words[] = {"can", "cane", "code", "ann", "cone", 
                           "mane", "mode", "one", "main", "cat"};
    
    for (int i = 0; i < n; ++i) {
        trie.addWord(words[i]);
    }

    std::cout << trie.getTotalNodes() << std::endl;
    return 0;
}
