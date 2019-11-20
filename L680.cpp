#include <iostream>

int flag = 1;
bool palindromeHelper(std::string& s, int flag) {
    if (s.empty()) {
        return true;
    }
    else {
        if (s[0] == s[s.length() - 1]) {
            return palindromeHelper(s, flag - 1);
        }
        else {
            return palindromeHelper(s.erase(0, 1), flag - 1) or palindromeHelper(s.erase(s.length() - 1, 1), flag - 1);
        }
    }
}

bool validPalindrome(std::string s) {
    if (flag >= 0) {
        return palindromeHelper(s, flag);
    }
    else {
        return false;
    }
}

int main() {
    std::cout << validPalindrome("abcdedcba") << std::endl;
    std::cout << "Here!" << std::endl;
    return 0;
}
