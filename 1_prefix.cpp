#include <iostream>
#include <string>
#include <vector>

std::vector<int> FindPrefix(std::string& s) {
    int n = s.size();

    std::vector<int> prefix(n, 0);
    for (int i = 1; i < n; ++i) {
        
        int elem = prefix[i - 1];
        while (s[i] != s[elem] && elem > 0) {
            elem = prefix[elem - 1];
        }
        if (s[i] == s[elem]) {
            prefix[i] = elem + 1;
        }
    }
    return prefix;
}

int main() {
    std::string s = "";
    
    std::getline(std::cin, s);
    
    std::vector<int> res = FindPrefix(s);

    for (auto& el : res) {
        std::cout << el << " "; 
    }

    return 0;
}