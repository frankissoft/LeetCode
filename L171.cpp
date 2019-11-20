#include <iostream>
#include <string>

int titleToNumber(std::string s) {
    int sum = 1;
    long int total = 0;
    s = {s.rbegin(), s.rend()};
    for (char c : s){
        int left = c - 'A' + 1;
        total += sum * left;
        sum *= 26;
    }
    return total;
}

int main() {
    std::cout << titleToNumber("CFDGSXM") << std::endl;
    return 0;
}
