#include <vector>
#include <string>
#include <iostream>

template<typename T>
std::ostream& operator<<(std::ostream& s, std::vector<T> t) {
    s << "{";
    for (std::size_t i = 0; i < t.size(); i++) {
        s << t[i] << (i == t.size() - 1 ? "" : ",");
    }
    return s << "}";
}


std::vector<int> mins = {8, 4, 2, 1, 32, 16, 8, 4, 2, 1};
std::vector<std::string> goodTime;

std::string minuteToClock(std::string& minute) {
    int hours;
    int minutes;
    for (int i = 0; i <= 3; i++) {
        if (minute[i] == '1') {
            hours += mins[i];
        }
    }
    for (int i = 4; i <= 9; i++) {
        if (minute[i] == '1') {
            minutes += mins[i];
        }
    }
    std::string s_hours = std::to_string(hours + (minutes / 60));
    std::string s_minutes = std::to_string(minutes % 60);
    // if (s_hours.length() == 1) {
    //     s_hours.insert(s_hours.begin(), '0');
    // }
    if (s_minutes.length() == 1) {
        s_minutes.insert(s_minutes.begin(), '0');
    }
    // goodTime.push_back(s_hours + ':' + s_minutes);
    // hours = 0;
    // minutes = 0;
    return s_hours + ":" + s_minutes;
}

void watchHelper(int num, std::string prefix) {
    if (prefix.length() == 10) {
        if (num == 0) {
            if ((prefix[0] == '1' and prefix[1] == '1') or (prefix[5] == '1' and prefix[6] == '1' and prefix[7] == '1' and prefix[8] == '1')) {
                return ;
            } else {
                goodTime.push_back(prefix);

            }

        } else {
            return ;
        }
    }
    else {
        watchHelper(num, prefix + '0');
        watchHelper(num - 1, prefix + '1');
    }
}

std::vector<std::string> readBinaryWatch(int num) {
    if (num == 0) {
        return std::vector<std::string> {"0:00"};
    }
    watchHelper(num, "");
    for (int i = 0; i <= goodTime.size(); i++) {
        goodTime[i] = minuteToClock(goodTime[i]);
    }
    return goodTime;
}

int main() {
    std::cout << readBinaryWatch(3) << std::endl;
    return 0;
}
