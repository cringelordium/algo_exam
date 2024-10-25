#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> vertices(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> vertices[i].first >> vertices[i].second;
    }

    long long area = 0;
    for (int i = 0; i < n; ++i) {
        int x1 = vertices[i].first;
        int y1 = vertices[i].second;
        int x2 = vertices[(i + 1) % n].first;
        int y2 = vertices[(i + 1) % n].second;
        area += x1 * y2 - x2 * y1;
    }

    double polygonArea = std::abs(area) / 2.0;
    std::cout << std::fixed << std::setprecision(5) << polygonArea << std::endl;

    return 0;
}
