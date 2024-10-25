#include <iostream>
#include <vector>
#include <cmath>
#include <string>

std::vector<bool> HammingEncode(const std::vector<bool>& data) {
    int m = data.size();
    int r = 0;

    while ((1 << r) < (m + r + 1)) {
        ++r;
    }

    std::vector<bool> encoded(m + r, 0);

    int j = 0;
    for (int i = 0; i < m + r; ++i) {
        if ((i & (i + 1)) == 0) {
            continue;
        }
        encoded[i] = data[j++];
    }

    for (int i = 0; i < r; ++i) {
        int parity = 0;
        int step = 1 << i;
        for (int j = step - 1; j < m + r; j += 2 * step) {
            for (int k = j; k < j + step && k < m + r; ++k) {
                parity ^= encoded[k];
            }
        }
        encoded[step - 1] = parity;
    }

    return encoded;
}

int main() {
    std::vector<bool> code;
    std::string input;
    std::cin >> input;

    for (char c : input) {
        if (c == '0') {
            code.push_back(false);
        } else if (c == '1') {
            code.push_back(true);
        }
    }

    std::vector<bool> encoded = HammingEncode(code);

    for (bool bit : encoded) {
        std::cout << bit;
    }

    return 0;
}
