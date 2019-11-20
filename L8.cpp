#include <iostream>
#include <string>

int myAtoi(std::string str) {
    while (str[0] == ' ') {
        str.begin()++;
    }
    int flag = 1;
    if (str[0] == '+' or str[0] == '-') {
        if (str[0] == '-') {
            flag = -1;
        }
    }
    int total = 0;
    int time = 1;
    // while (str.end() != str.begin()) {
    for (int i = str.length() - 1; i >= 0; i--) {
        std::cout << "str[i]: " << str[i] << std::endl;
        int num = str[i] - '0';
        total += time * num;
        std::cout << "Total: " << total << std::endl;
        time *= 10;
        std::cout << "Time: " << time << std::endl;
        // str.end()--;
    }
    // total += time * (int)*(str.end());
    return flag * total;
}

int main() {
    std::cout << myAtoi("123") << std::endl;
    return 0;
}
