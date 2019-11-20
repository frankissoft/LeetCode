#include <iostream>
bool isPalindrome(string s) {
    string t;
    for(int i = 0; i < s.size(); i++)
        if((s[i] >= 97 && s[i] <= 122) || (s[i] >= 65 && s[i] <= 90) || (s[i] >= 48&& s[i] <= 57))
            t += s[i];
    for(int i = 0; i < t.size(); ++i)
        t[i] = tolower(t[i]);
    for(int i = 0; i < t.size(); i++){
        if(t[i] != t[t.size()-1-i])
            return false;
    }
    return true;
}
