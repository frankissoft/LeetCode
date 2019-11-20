#include <iostream>
// #include <vector>
#include <string>

int oddCount = 0;
int sum = 0;

int findnum(std::string& s, char c) {
    int count;
    std::string::iterator p;

    while (s.find(c) != std::string::npos) {
        count++;
        std::cout << "Count: " << count << std::endl;
        p = s[s.find(c)];
        s.erase(p);
        // std::cout
    }
    return count++;
}

int longestPalindrome(std::string s) {
    while (s.length() > 0){
        if (findnum(s, s[0]) % 2 == 0) {
            sum += findnum(s, s[0]);
            std::cout << "sum: " << sum << std::endl;
        }
        else {
            std::cout << "oddCount: " << oddCount << std::endl;
            oddCount = (findnum(s, s[0]) > oddCount) ? findnum(s, s[0]) : oddCount;
        }
    }
    return sum + oddCount;
}

int main() {
    std::cout << longestPalindrome("abcdefgfdecba") << std::endl;
    return 0;
}
