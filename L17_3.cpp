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

void letterHelper(std::string& s, std::string prefix, std::vector<std::string>& alreadyPrinted) {
    if (s.empty()) {
        alreadyPrinted.push_back(prefix);
    }
    else {
        // int c = s[0] - 48;
        auto s_minus = s.erase(0, 1);
        for (char c : letters[s[0]]) {

            letterHelper(s_minus, prefix + c, alreadyPrinted);
        }
    }
}

std::vector<std::string> letterCombinations(std::string digits) {
    std::vector<std::string> alreadyPrinted;
    letterHelper(digits, "", alreadyPrinted);
    return alreadyPrinted;
}



int main() {
    std::cout << letterCombinations("258") << std::endl;
    return 0;
}
