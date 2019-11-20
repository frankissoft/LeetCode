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

std::vector<std::vector<int>> shiftGrid(std::vector<std::vector<int>>& grid, int k) {
    std::vector<std::vector<int>> res = grid;
    int n = res.size();
    int m = res[0].size();
    int num = k % m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res[i][(j + num) % m] = grid[i][j];
        }
    }
    std::cout << num << std::endl;
    return res;
}

int main () {
    std::vector<std::vector<int>> grid = {{3,8,1,9},{19,7,2,5},{4,6,11,10},{12,0,21,13},{1,2,3,4}};
    std::vector<std::vector<int>> grid2 = {{1,2,3},{4,5,6},{7,8,9}};
    int k = 1;
    std::cout << shiftGrid(grid2, k) << std::endl;
    return 0;
}
