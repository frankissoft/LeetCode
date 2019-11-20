#include <iostream>
#include <vector>
#include <string>

template<typename T>
std::ostream& operator<<(std::ostream& s, std::vector<T> t) {
    s << "{";
    for (std::size_t i = 0; i < t.size(); i++) {
        s << t[i] << (i == t.size() - 1 ? "" : ",");
    }
    return s << "}";
}

std::string shiftingLetters(std::string S, std::vector<int>& shifts) {
    int len = S.length(), size = shifts.size();
    std::cout << "len: " << len << ", size: " << size << std::endl;
    // for (int i = 0, j = size - 1; i < )
    for (int i = size - 2; i >= 0; i--) {
        shifts[i] = shifts[i] + shifts[i + 1];
    }
    // std::cout << shifts << std::endl;
    // for (int i = 0; i < len; i++) {
    //     std::cout << "here" << std::endl;
    //     shifts[i] += shifts[len];
    // }
    // std::cout << shifts << std::endl;
    for (int i = 0; i < len; i++) {
        S[i] = (S[i] - 'a' + shifts[i]) % 26 + 'a';
    }
    // std::cout << S << std::endl;
    return "";
}

int main() {
    std::vector<int> shifts = {3,5};
    std::string S = "abc";
    std::cout << shiftingLetters(S, shifts);
    return 0;
}
