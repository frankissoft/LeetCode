#include <iostream>
#include <vector>

std::vector<int> small = {0, 1, 2, 4};
int getMoneyHelper(int n) {
    if (n > 4) {
        if (n == 1) {
            return 0;
        } else {
            std::cout << "getMoneyHelper(" << n - 4 << "), n - 3: " << n - 3 << std::endl;
            std::cout << "n - 3: " << n - 3 << ", n - 1: " << n - 1 <<std::endl;
            return std::max(getMoneyHelper(n - 4) + (n - 3), (n - 3) + (n - 1));
        }
    } else {
        return small[n];
    }
}

int main() {
    std::cout << getMoneyHelper(18) << std::endl;
    return 0;
}
