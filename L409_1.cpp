#include <iostream>
#include <map>
#include <string>

template<typename T>
std::ostream& operator<<(std::ostream& s, std::vector<T> t) {
    s << "{";
    for (std::size_t i = 0; i < t.size(); i++) {
        s << t[i] << (i == t.size() - 1 ? "" : ",");
    }
    return s << "}";
}

std::map<char, int> count;
int max = 0;
int total = 0;
int flag = 0;

int longestPalindrome(std::string s) {
    for (char a : s) {
        if (count.find(a) == count.end()) {
            count[a] = 1;
            std::cout << "New: " << a << std::endl;
        } else {
            count[a]++;
            std::cout << "Add: " << a << std::endl;
        }
    }

    // std::cout << count << std::endl;

    for (auto x : count) {
        if (x.second % 2 == 0) {
            total += x.second;
            std::cout << "Total: " << total << std::endl;
        }
        else {
            flag = 1;
            max = std::max(max, x.second);
            std::cout << "Max: " << max << std::endl;
        }
        std::cout << "<" << x.first << ", " << x.second << ">" << std::endl;
    }
    return total + flag;
}

int main() {
    std::string s = "abccaefesrgtdrlehsvduibascrlnsvtiuaeifsriuSIFUDHGLERGRTHIULSDFGLSKHUGccdd";
    std::string s1 = "abccaefesrgtdrlehsvduibascrlnsvtiuaeifsriuccdd";
    std::string s2 = "bascrlnsvtiuaeifsriuccdd";
    std::string s3 = "aabcceefrgtdrlehssvdui";
    std::string s4 = "qwertyuiopqasdfgqhjklzxqcvbqnm";
    std::cout << longestPalindrome(s2) << std::endl;
    return 0;
}
