#include <iostream>
#include <vector>

void printMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int value : row) {
            if (value != 0) {
                std::cout << value << " ";
            }
        }
        std::cout << std::endl;
    }
}

void fillUpperTriangularSpiral(std::vector<std::vector<int>>& matrix, int n) {
    int num = 1;
    int startX = 0, startY = 0;
    int endX = n - 1, endY = n - 1;
    
    while (startX <= endX && startY <= endY) {
        // 从左上到右上
        for (int i = startY; i <= endY; ++i) {
            matrix[startX][i] = num++;
        }
        if (++startX > endX) break;

        // 从右上到左下
        for (int i = startX; i <= endX; ++i) {
            matrix[i][endY] = num++;
            endY--;
        }
        if (++startX > endX) break;

        // 从左下到右上
        for (int i = endY; i >= startY; --i) {
            matrix[endX][i] = num++;
        }
        if (--endX < startX) break;

        // 从右上到左下
        for (int i = endX; i >= startX; --i) {
            matrix[i][startY] = num++;
            startY++;
        }
        if (startY > endY) break;
    }
}

int main() {
    int n;
    std::cout << "请输入矩阵的阶数 n: ";
    std::cin >> n;

    std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));
    fillUpperTriangularSpiral(matrix, n);
    printMatrix(matrix);

    return 0;
}
