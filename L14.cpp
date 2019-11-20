#include <iostream>
#include <vector>

std::string longestCommonPrefix(std::vector<std::string>& strs) {
    // empty vector
    if (strs.size() == 0) {
        return "";
    }

    int j = 0, len = 0, min = strs[0].length();
    std::string strs1 = strs[0];
    for (int i = 1; i < strs.size(); i++) {
        min = (min < strs[i].length()) ? min : strs[i].length();
    }
    // while (1) {
        for (int j = 0; j < min; j++) {
            char x = strs[0][j];
            std::cout << "x: " << x << std::endl;
            // strs[0].erase(0, 1);
            for (int i = 1; i < strs.size(); i++) {
                std::cout << "i: " << i << ", j: " << j << std::endl;
                if (strs[i][j] and strs[i][j] == x) {
                    // strs[i].erase(0, 1);
                // } else if () {
                } else {
                    return strs1.substr(0, len);
                }
            }
            len++;
        }
    // }
    return strs1.substr(0, len);
}

int main() {
    std::vector<std::string> strs = {"flower","flow","flight"};
    std::vector<std::string> strs2 = {"dog","racecar","car"};
    std::vector<std::string> strs3 = {"abc", "abc", "abc"};
    std::cout << longestCommonPrefix(strs3) << std::endl;
    return 0;
}
