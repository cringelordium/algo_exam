#include <iostream>
#include <vector>
#include <memory>

class PersistentArray {
public:
    // Узел двоичного дерева
    struct Node {
        int value;  // Значение листа (если это лист)
        std::shared_ptr<Node> left, right;  // Указатели на левое и правое поддерево

        Node(int val) : value(val), left(nullptr), right(nullptr) {}
        Node(std::shared_ptr<Node> l, std::shared_ptr<Node> r) : value(0), left(l), right(r) {}
    };

    // Конструктор: создаем начальный массив
    PersistentArray(const std::vector<int>& initialArray) {
        root = build(initialArray, 0, initialArray.size() - 1);
        versionRoots.push_back(root);  // Версия 0
    }

    // Операция set: копируем дерево, изменяя только путь к нужному листу
    void set(int version, int index, int value) {
        std::shared_ptr<Node> newRoot = set(versionRoots[version], 0, size - 1, index, value);
        versionRoots.push_back(newRoot);
    }

    // Возвращает количество узлов во всех версиях
    int getTotalNodes() const {
        return totalNodes;
    }

private:
    std::shared_ptr<Node> root;  // Корень дерева для текущей версии
    std::vector<std::shared_ptr<Node>> versionRoots;  // Корни деревьев всех версий
    int size = 4;  // Размер начального массива
    int totalNodes = 0;  // Общее количество узлов во всех версиях

    // Построение двоичного дерева из начального массива
    std::shared_ptr<Node> build(const std::vector<int>& arr, int left, int right) {
        if (left == right) {
            totalNodes++;
            return std::make_shared<Node>(arr[left]);  // Лист с значением
        }
        int mid = (left + right) / 2;
        totalNodes++;
        return std::make_shared<Node>(build(arr, left, mid), build(arr, mid + 1, right));  // Внутренний узел
    }

    // Рекурсивное обновление дерева для создания новой версии
    std::shared_ptr<Node> set(std::shared_ptr<Node> node, int left, int right, int index, int value) {
        if (left == right) {
            totalNodes++;
            return std::make_shared<Node>(value);  // Лист с новым значением
        }
        int mid = (left + right) / 2;
        totalNodes++;
        if (index <= mid) {
            return std::make_shared<Node>(set(node->left, left, mid, index, value), node->right);  // Копируем только левое поддерево
        } else {
            return std::make_shared<Node>(node->left, set(node->right, mid + 1, right, index, value));  // Копируем только правое поддерево
        }
    }
};

int main() {
    // Начальный массив {1, 2, 3, 4}
    std::vector<int> initialArray = {1, 2, 3, 4};
    PersistentArray pArray(initialArray);

    // 9 операций set
    pArray.set(0, 3, 100);  // Версия 1
    pArray.set(1, 2, 200);  // Версия 2
    pArray.set(0, 0, 300);  // Версия 3
    pArray.set(3, 2, 400);  // Версия 4
    pArray.set(2, 1, 500);  // Версия 5
    pArray.set(4, 1, 600);  // Версия 6
    pArray.set(1, 0, 700);  // Версия 7
    pArray.set(3, 3, 800);  // Версия 8
    pArray.set(5, 2, 900);  // Версия 9

    // Выводим общее количество узлов
    std::cout << pArray.getTotalNodes() << std::endl;

    return 0;
}
