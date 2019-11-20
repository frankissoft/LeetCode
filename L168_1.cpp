#include <iostream>
#include <string>

std::string convertToTitle(int n) {
    std::string result;
    while (n != 0) {
        n--;
        char left = ((n % 26) + 'A');

        std::cout << "left: " << n % 26 << ", " << left << std::endl;
        result += left;
        n = n / 26;
        std::cout << "n: " << n << std::endl;
    }
    // result.insert(result.begin(), (n + 16) + 'A');
    // while (result[0] == '@') {
    //     result.erase(0, 1);
    // }
    return {result.rbegin(), result.rend()};
}

int main() {
    std::cout << convertToTitle(52) << std::endl;
    return 0;
}
