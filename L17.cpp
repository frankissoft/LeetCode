#include <iostream>
#include <string>
#include <vector>

template<typename T>
std::ostream& operator<<(std::ostream& s, std::vector<T> t) {
    s << "{";
    for (std::size_t i = 0; i < t.size(); i++) {
        s << t[i] << (i == t.size() - 1 ? "" : ",");
    }
    return s << "}";
}

std::vector<std::string> letters = {"", "", "abc", "edf",
                              "ghi", "jkl", "mno",
                             "pqrs", "tuv", "wxyz"};

void indent(int n) {
 for (int i = 0; i < n; i++) {
     std::cout << "    ";
 }
}

void letterCombinationsHelper(std::string s, std::string chosen, std::vector<std::string>& alreadyPrinted) {
    indent(chosen.length());
    std::cout << "letterHelper(" << s << ", " << chosen << ")" << std::endl;

    if (s.empty()) {
        indent(chosen.length());
        std::cout << chosen << ", ";
        alreadyPrinted.push_back(chosen);
    }
    else {
        // std::cout << s << std::endl;
        // std::cout << s[1] << std::endl;
        // std::cout << "I'm here!" << std::endl;
        for (int j = 0; j < s.length(); j++) {
            int num = s[j] - 48;
            // check1
            // std::cout << num << std::endl;
            for (int i = 0; i < letters[num].length(); i++) {
                // choose
                chosen += letters[num][i];
                s.erase(j, 1);
                // check2
                // std::cout << "I'm here!" << std::endl;
                // explore
                std::cout << num << std::endl;
                letterCombinationsHelper(s, chosen, alreadyPrinted);
                // unchoose
                s.insert(j, 1, num + 48);
                // check3
                // std::cout << "I'm here!" << std::endl;
                chosen.erase(chosen.length() - 1, 1);
                }
            }
        }
    }


std::vector<std::string> letterCombinations(std::string digits) {
    std::vector<std::string> alreadyPrinted;
    letterCombinationsHelper(digits, "", alreadyPrinted);
    return alreadyPrinted;
}

int main() {
    // std::vector<std::string> result = letterCombinations("1234567");
    std::cout << letterCombinations("258") << std::endl;
    // std::cout << result.empty() << std::endl;
    // std::cout << letters[1][2];
    return 0;
}
