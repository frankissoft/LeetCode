#include <iostream>
#include <string>

int globalColor = 2;
int numIslands(vector<vector<char>>& grid) {
    // put water around the grid
    std::vector<std::vector<int>> waterGrid = grid;
    for (int i = 0; i < waterGrid.size(); i++) {
        waterGrid[i].insert(waterGrid[i].begin(), 0);
        waterGrid[i].push_back(0);
    }
    waterGrid.insert(waterGrid.begin(), {0} * waterGrid[0].size());
    waterGrid.push_back({0} * waterGrid[0].size())
    int m = waterGrid.size();
    int n = waterGrid[0].size();

    // draw
    for (int i = 1; i < m)
}
