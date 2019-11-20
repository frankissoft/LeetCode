#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>

template<typename T>
std::ostream& operator<<(std::ostream& s, std::vector<T> t) {
    s << "{";
    for (std::size_t i = 0; i < t.size(); i++) {
        s << t[i] << (i == t.size() - 1 ? "" : ",");
    }
    return s << "}";
}

std::vector<std::string> good;
std::string cur;

void letterHelper(std::string& S, int pos) {
    if (pos == S.length()) {
        good.push_back(cur);
    }
    else {
        char c = S[pos];
        // std::cout << c << std::endl;
        if (c <= 57) {
            // if it's a number add the number
            cur[pos] = c;
            letterHelper(S, pos + 1);
            // std::cout << "I'm a number!" << std::endl;
        }
        else {
            // add the case
            // std::cout << "I'm a letter!" << std::endl;
            cur[pos] = c;
            letterHelper(S, pos + 1);
            // add another case
            if (c <= 90) {
                // it's an uppercase
                cur[pos] = c + 32;
                letterHelper(S, pos + 1);
            }
            else {
                // its' a lowercase
                cur[pos] = c - 32;
                letterHelper(S, pos + 1);
                }
            }
        }
    }


std::vector<std::string> letterCasePermutation(std::string S) {
    cur.resize(S.size());
    if (!S.size()) {
        return std::vector<std::string>();
    }
    letterHelper(S, 0);
    return good;
}

int main() {
    std::cout << letterCasePermutation("") << std::endl;
    return 0;
}
