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

std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
    std::sort(intervals.begin(), intervals.end());
    std::cout << intervals << std::endl;
    int i = 0;
    while (1) {
        if (i == intervals.size() - 1) {
            break;
        }
        if (intervals[i][1] >= intervals[i + 1][0]) {
            intervals[i][1] = intervals[i + 1][1];
            intervals.erase(intervals.begin() + i + 1);
        } else {
            i++;
        }
    }
    return intervals;
}

int main() {
    std::vector<std::vector<int>> intervals = {{1,3},{5,11},{2,6},{8,10},{15,18}};
    std::vector<std::vector<int>> intervals2 = {{1,4},{4,5}};
    std::cout << merge(intervals) << std::endl;
    return 0;
}
