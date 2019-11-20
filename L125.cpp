#include <iostream>
#include <string>

void isHelper(std::string& s) {
    for (int length = s.length() - 1; length >= 0; length--) {
        if ((s[length] <= 122 and s[length] >= 97) or (s[length] <= 90 and s[length] >= 65) or (s[length] <= 57 and s[length] >= 48)) {
            if (s[length] >= 97) {
                s[length] -= 32;
            }
        }
        else {
            s.erase(length, 1);
        }
    }
}

bool palindromeHelper(std::string s) {
    // for (int i = 0, int j = (s.length() - 1 - i); i <= ((s.length() - 1) / 2); i++, j++) {
    //     if (s[i] != s[j]) {
    //         return false;
    //     }
    // }
    // return true;
    if (s.empty()) {
        return true;
    }
    else {
        if (s[0] == s[s.length() - 1]) {
            // std::cout << s.substr(1, s.length() - 2) << std::endl;
            return palindromeHelper(s.substr(1, s.length() - 2));
        }
        else {
            return false;
        }
    }
}


bool isPalindrome(std::string s) {
    isHelper(s);
    return palindromeHelper(s);
}

int main() {
    std::cout << isPalindrome("Zeus was deified, saw Suez.") << std::endl;
    std::cout << "here!" << std::endl;
    return 0;
}
