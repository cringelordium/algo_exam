#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

std::vector<int> LZWEncode(const std::string& input) {
    std::unordered_map<std::string, int> dictionary = {{"A", 0}, {"B", 1}, {"C", 2}};
    int dictSize = 3;

    std::string w;
    std::vector<int> lzw_code;

    for (char c : input) {
        std::string wc = w + c;
        if (dictionary.count(wc)) {
            w = wc;
        } else {
            lzw_code.push_back(dictionary[w]);
            dictionary[wc] = dictSize++;    
            w = std::string(1, c);
        }
    }

    if (!w.empty()) {
        lzw_code.push_back(dictionary[w]);
    }

    return lzw_code;
}

int main() {
    std::string input = "BABACABACA";

    std::vector<int> encoded = LZWEncode(input);

    for (int code : encoded) {
        std::cout << code << " ";
    }
    std::cout << std::endl;

    return 0;
}
