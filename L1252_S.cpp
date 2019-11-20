#include <iostream>
#include <vector>

int oddCells(int n, int m, std::vector<std::vector<int>>& indices) {
    std::vector<int> row_sum (n, 0), col_sum (m, 0);
    for (std::vector<int> v : indices) {
        row_sum[v[0]]++;
        col_sum[v[1]]++;
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            sum += (row_sum[i] + col_sum[j]) % 2;
        }
    }
    return sum;
}

int main() {
    std::vector<std::vector<int>> indices = {{0,1},{1,1}};
    std::cout << oddCells(2, 3, indices);
}
