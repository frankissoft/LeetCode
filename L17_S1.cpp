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


std::string cur;
std::vector<std::string> good;

void letterHelper(std::string& digits, int pos) {
    if (pos == digits.length()) {
        good.push_back(cur);
    } else {
        for (char c : letters[digits[pos] - '0']) {
            cur[pos] = c;
            letterHelper(digits, pos + 1);
        }
    }
}

std::vector<std::string> letterCombinations(std::string digits) {
    cur.resize(digits.size());
    if (!digits.size()) {
        return std::vector<std::string>();
    }
    letterHelper(digits, 0);
    return good;
}

int main() {
    std::cout << letterCombinations("34567") << std::endl;
    return 0;
}
