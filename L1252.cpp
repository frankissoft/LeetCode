#include <iostream>
#include <vector>

template<typename T>
std::ostream& operator<<(std::ostream& s, std::vector<T> t) {
    s << "{";
    for (std::size_t i = 0; i < t.size(); i++) {
        s << t[i] << (i == t.size() - 1 ? "" : ",");
    }
    return s << "}";
}

int oddCells(int n, int m, std::vector<std::vector<int>>& indices) {
    int count = 0;
    std::vector<std::vector<int>> zeros(n, std::vector<int> (m, 0));
    for (int i = 0; i < indices.size(); i++) {
        for (int j = 0; j < m; j++) {
            zeros[indices[i][0]][j]++;
            // std::cout << "i: " << i << ", j: " << j << std::endl;
            // std::cout << "indices[i][0]: " << indices[i][0] << std::endl;
            // std::cout << "zeros " << zeros << std::endl;

        }
        for (int k = 0; k < n; k++) {
            zeros[k][indices[i][1]]++;
            // std::cout << "i: " << i << ", k: " << k << std::endl;
            // std::cout << "indices[i][1] " << indices[i][1] << std::endl;
            // std::cout << "zeros " << zeros << std::endl;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // std::cout << "I'm here!" << std::endl;
            if (zeros[i][j] % 2 != 0) {
                // std::cout << "I'm here!" << std::endl;
                // std::cout << "count: " << count << std::endl;
                count++;
            }
        }
    }
    return count;
    std::cout << count << std::endl;
    std::cout << std::endl;
}

int main() {
    std::vector<std::vector<int>> indices = {{0,1},{1,1}};
    std::cout << oddCells(2, 3, indices);
}
