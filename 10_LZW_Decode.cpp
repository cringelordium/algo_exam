#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

std::string LZWDecode(const std::vector<int>& encoded) {
    std::unordered_map<int, std::string> dictionary = {{0, "A"}, {1, "B"}, {2, "C"}};
    int dictSize = 3; 

    std::string w = dictionary[encoded[0]]; 
    std::string result = w;  

    for (size_t i = 1; i < encoded.size(); ++i) {
        int k = encoded[i];
        std::string entry;

        if (dictionary.count(k)) {
            entry = dictionary[k];  
        } else if (k == dictSize) {
            entry = w + w[0];  
        }

        result += entry;

        dictionary[dictSize++] = w + entry[0];

        w = entry;
    }

    return result;
}

int main() {
    std::vector<int> encoded = {2, 0, 1, 3, 1, 4, 3};

    std::string decoded = LZWDecode(encoded);

    std::cout << decoded << std::endl;

    return 0;
}
