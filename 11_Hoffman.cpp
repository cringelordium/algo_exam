#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

// Узел дерева Хаффмана
struct Node {
    char ch;            // Символ
    int freq;           // Частота
    Node* left;         // Левое поддерево
    Node* right;        // Правое поддерево

    Node(char ch, int freq) : ch(ch), freq(freq), left(nullptr), right(nullptr) {}
};

// Компаратор для приоритетной очереди
struct Compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;  // Узел с меньшей частотой имеет больший приоритет
    }
};

// Функция для рекурсивного обхода дерева и вычисления длины кодов
void calculateHuffmanCodeLengths(Node* root, std::unordered_map<char, int>& lengths, int currentLength) {
    if (!root) return;

    // Если это лист дерева (символ), сохраняем длину его кода
    if (!root->left && !root->right) {
        lengths[root->ch] = currentLength;
    }

    // Рекурсивно вычисляем длину для левого и правого поддеревьев
    calculateHuffmanCodeLengths(root->left, lengths, currentLength + 1);
    calculateHuffmanCodeLengths(root->right, lengths, currentLength + 1);
}

// Основная функция
int main() {
    // Частоты символов
    std::unordered_map<char, int> freq = {
        {'A', 10}, {'B', 5}, {'C', 7}, {'D', 20},
        {'E', 4}, {'F', 12}, {'G', 30}
    };

    // Приоритетная очередь для построения дерева Хаффмана
    std::priority_queue<Node*, std::vector<Node*>, Compare> pq;

    // Создаем узлы для каждого символа и добавляем их в очередь
    for (const auto& pair : freq) {
        pq.push(new Node(pair.first, pair.second));
    }

    // Строим дерево Хаффмана
    while (pq.size() > 1) {
        // Извлекаем два узла с наименьшей частотой
        Node* left = pq.top();
        pq.pop();
        Node* right = pq.top();
        pq.pop();

        // Создаем новый внутренний узел с частотой, равной сумме частот двух узлов
        Node* newNode = new Node('\0', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;

        // Добавляем новый узел обратно в очередь
        pq.push(newNode);
    }

    // Корень дерева Хаффмана
    Node* root = pq.top();

    // Вычисляем длины кодов
    std::unordered_map<char, int> huffmanCodeLengths;
    calculateHuffmanCodeLengths(root, huffmanCodeLengths, 0);

    // Выводим длины кодов в требуемом формате
    std::cout << huffmanCodeLengths['A'] << " "
              << huffmanCodeLengths['B'] << " "
              << huffmanCodeLengths['C'] << " "
              << huffmanCodeLengths['D'] << " "
              << huffmanCodeLengths['E'] << " "
              << huffmanCodeLengths['F'] << " "
              << huffmanCodeLengths['G'] << std::endl;

    return 0;
}
