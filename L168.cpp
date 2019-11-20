#include <iostream>
#include <string>

std::string convertToTitle(int n) {
    std::string answer;
    int left = 0;
    while (n >= 26) {
        answer.push_back('0' + ((n / 26) + 16));
        n = n / 26;
        left = n % 26;
    }
    answer.push_back('0' + (left + 16));
    return answer;
}

int main() {
    std::cout << convertToTitle(500) << std::endl;
    return 0;
}
