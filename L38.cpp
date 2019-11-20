#include <iostream>
#include <string>

// std::string res = "";

std::string countHelper(int n) {
    std::string res = "";
    if (n == 1) {
        return "1";
    } else {
        int i = 0, j = 0;
        std::string last = countHelper(n - 1);
        while (1) {
            if (last[j] == last[i]) {
                j++;
            } else {
                res += j - i + '0';
                res += last[i];
                i = j;
            }
            if (j == last.length()) {
                res += j - i + '0';
                res += last[i];
                break;
            }
        }
    }
    return res;
}

std::string countAndSay(int n) {
    return countHelper(n);
}


// std::string countAndSay(int n) {
//     if (n == 1) {
//         return "1";
//     } else {
//         std::string last = countAndSay(n - 1);
//         std::string res = "";
//         int i = 0, j = 0;
//         while (1) {
//             std::cout << "i: " << i << ", j: " << j << std::endl;
//             if (j == last.length()) {
//                 std::cout << "Here0!" << std::endl;
//                 std::cout << "End - i: " << i << ", j: " << j << std::endl;
//                 res += (j - i) + '0' + last[i];
//                 std::cout << "res: " << res << std::endl;
//                 std::cout << "to_string(" << j << " - " << i << ")" << std::endl;
//                 std::cout << "last[" << i << "]: " << last[i] << std::endl;
//                 break;
//             }
//             if (last[i] == last[j]) {
//                 std::cout << "Equ - i: " << i << ", j: " << j << std::endl;
//                 std::cout << "Here1!" << std::endl;
//                 j++;
//             } else {
//                 std::cout << "Non - i: " << i << ", j: " << j << std::endl;
//                 std::cout << "Here2!" << std::endl;
//                 res += std::to_string(j - i) + last[i];
//                 i = j;
//             }
//         }
//     }
//     return res;
// }

int main() {
    for (int i = 1; i < 11; i++) {
        std::cout << countAndSay(i) << std::endl;
    }
    return 0;
}
