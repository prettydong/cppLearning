#include <iostream>
#include <vector>
#include <string>
#include <type_traits>

template<typename T>
void printMatrix(const T& matrix) {
    if constexpr (std::is_same_v<T, int>) {
        std::cout << matrix;
    } else {
        std::cout << "[";
        for (size_t i = 0; i < matrix.size(); ++i) {
            if (i > 0) std::cout << ", ";
            printMatrix(matrix[i]);
        }
        std::cout << "]";
    }
}

template<typename T>
void printHighDimVector(const T& vec, const std::vector<std::string>& dims, size_t n,
                        std::vector<size_t>& indices, size_t depth = 0) {
    if (depth == n) {
        std::cout << "<";
        for (size_t i = 0; i < n; ++i) {
            if (i > 0) std::cout << ", ";
            std::cout << dims[i] << " = " << indices[i];
        }
        std::cout << "> --> (";
        for (size_t i = n; i < dims.size(); ++i) {
            if (i > n) std::cout << ", ";
            std::cout << dims[i];
        }
        std::cout << ") = ";
        printMatrix(vec);
        std::cout << std::endl;
        return;
    }

    if constexpr (!std::is_same_v<T, int>) {
        for (size_t i = 0; i < vec.size(); ++i) {
            indices[depth] = i;
            printHighDimVector(vec[i], dims, n, indices, depth + 1);
        }
    }
}

int main() {
    auto highDimsVec4 = std::vector<std::vector<std::vector<std::vector<int>>>>{
        {
            {
                {1, 2, 3},
                {4, 5, 6},
                {7, 8, 9}
            }
        },
        {
            {
                {10, 11, 12},
                {13, 14, 15},
                {16, 17, 18}
            }
        }
    };
    auto dimsName = std::vector<std::string>{"type", "b", "c", "d"};
    // 我希望你打印出 highDimsVec4 的值，使用模版的方式，这个模版支持任意维度的vector的打印
    // dimsName 是维度名称，比如 type, b, c, d。我还会给你一个参数n，这个n小于数组的维度。
    // 前n维 我希望你用 罗列的方式打印 ，后面的维度我希望你用矩阵的方式打印
    // 比如上面的例子我希望输出这样
    // <type = 0, b = 0> --> (c, d) = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]

    // Example usage
    size_t n = 2;
    std::vector<size_t> indices(n);
    printHighDimVector(highDimsVec4, dimsName, n, indices);
    return 0;
} 