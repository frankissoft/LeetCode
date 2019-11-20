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
    int n = grid.size();
    int m = grid[0].size();
    std::vector<int> res;
    for (int i = 0; i < n; i++) {
        res.insert(res.end(), grid[i].begin(), grid[i].end());
    }
    std::cout << res << std::endl;
    std::vector<int> tmp = res;
    for (int i = 0; i < res.size(); i++) {
        res[(i + k) % res.size()] = tmp[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            grid[i][j] = res[i * m + j];
        }
    }
    return grid;
}

int main () {
    std::vector<std::vector<int>> grid = {{3,8,1,9},{19,7,2,5},{4,6,11,10},{12,0,21,13},{1,2,3,4}};
    std::vector<std::vector<int>> grid2 = {{1,2,3},{4,5,6},{7,8,9}};
    int k = 8;
    std::cout << shiftGrid(grid2, k) << std::endl;
    return 0;
}
