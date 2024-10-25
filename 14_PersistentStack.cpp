#include <iostream>
#include <vector>

class PersistentStack {
public:
    // Конструктор: создаем пустую версию 0
    PersistentStack() {
        versions.push_back(std::vector<int>());  // Пустая версия 0
    }

    // Операция push: копируем версию и добавляем элемент
    void push(int version, int value) {
        std::vector<int> newVersion = versions[version];  // Копируем указанную версию
        newVersion.push_back(value);                      // Добавляем новый элемент
        versions.push_back(newVersion);                   // Сохраняем новую версию
    }

    // Операция pop: копируем версию и удаляем элемент
    void pop(int version) {
        if (!versions[version].empty()) {
            std::vector<int> newVersion = versions[version];  // Копируем указанную версию
            newVersion.pop_back();                            // Удаляем последний элемент
            versions.push_back(newVersion);                   // Сохраняем новую версию
        } else {
            versions.push_back(versions[version]);  // Если стек пуст, создаем копию без изменений
        }
    }

    // Возвращает количество элементов в версии стека
    int size(int version) const {
        return versions[version].size();
    }

private:
    std::vector<std::vector<int>> versions;  // Все версии стека
};

int main() {
    PersistentStack stack;

    // Выполняем операции согласно условию задачи
    stack.push(0, 100);   // Версия 1
    stack.push(1, 200);   // Версия 2
    stack.pop(1);         // Версия 3
    stack.push(1, 300);   // Версия 4
    stack.pop(4);         // Версия 5
    stack.push(4, 400);   // Версия 6
    stack.push(0, 500);   // Версия 7
    stack.pop(2);         // Версия 9
    stack.push(6, 600);   // Версия 10

    // Вывод количества элементов в версиях с 0 по 9
    for (int i = 0; i <= 9; ++i) {
        std::cout << stack.size(i) << " ";
    }
    std::cout << std::endl;

    return 0;
}
