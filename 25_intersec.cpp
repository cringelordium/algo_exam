#include <iostream>
#include <iomanip>

struct Line {
    int A, B, C;
};

Line get_my_line(int x1, int y1, int x2, int y2) {
    Line funny;
    funny.A = y1 - y2;
    funny.B = x2 - x1;
    funny.C = x1 * y2 - x2 * y1;
    return funny;
}

bool are_parallel(const Line& l1, const Line& l2) {
    return l1.A * l2.B == l2.A * l1.B;
}

bool are_same(const Line& l1, const Line& l2) {
    return are_parallel(l1, l2) && l1.A * l2.C == l2.A * l1.C && l1.B * l2.C == l2.B * l1.C;
}

int main() {
    int x1, y1, x2, y2, x3, y3, x4, y4;
    std::cin >> x1 >> y1 >> x2 >> y2;
    std::cin >> x3 >> y3 >> x4 >> y4;

    Line firstLine = get_my_line(x1, y1, x2, y2);
    Line secondLine = get_my_line(x3, y3, x4, y4);

    if (are_same(firstLine, secondLine)) {
        std::cout << 2 << std::endl;
    } else if (are_parallel(firstLine, secondLine)) {
        std::cout << 0 << std::endl;
    } else {
        double det = firstLine.A * secondLine.B - secondLine.A * firstLine.B;
        double x = (secondLine.B * (-firstLine.C) - firstLine.B * (-secondLine.C)) / det;
        double y = (firstLine.A * (-secondLine.C) - secondLine.A * (-firstLine.C)) / det;
        std::cout << 1 << " " << std::fixed << std::setprecision(2) << x << " " << y << std::endl;
    }

    return 0;
}
