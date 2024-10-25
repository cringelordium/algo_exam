#include <iostream>
#include <vector>
#include <cmath>

int findErrorBit(const std::vector<int>& hammingCode) {
    int n = hammingCode.size();
    int errorPosition = 0;
    
    // Проверяем каждый контрольный бит
    for (int i = 0; i < log2(n); ++i) {
        int pos = pow(2, i);
        int count = 0;

        // Проверяем позиции, которые контролируются текущим контрольным битом
        for (int j = pos; j <= n; j += 2 * pos) {
            for (int k = j; k < j + pos && k <= n; ++k) {
                count += hammingCode[k - 1];
            }
        }

        // Если сумма битов на контролируемых позициях нечётная, то есть ошибка
        if (count % 2 != 0) {
            errorPosition += pos;
        }
    }
    
    return errorPosition;
}

int main() {
    // Пример: код Хэмминга 7 бит (4 информационных и 3 контрольных бита)
    std::vector<int> hammingCode = {1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0};
    
    int errorBit = findErrorBit(hammingCode);

    if (errorBit == 0) {
        std::cout << "Ошибок нет." << std::endl;
    } else {
        std::cout << "Ошибка в бите: " << errorBit << std::endl;
    }

    return 0;
}
