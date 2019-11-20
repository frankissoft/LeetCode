#include <iostream>
#include <vector>

template<typename T>
std::ostream& operator<<(std::ostream& s, std::vector<T> t) {
    s << "{";
    for (std::size_t i = 0; i < t.size(); i++) {
        s << t[i] << (i == t.size() - 1 ? "" : ",");
    }
    return s << "}";
}

int numFriendRequests(std::vector<int>& ages) {
    // sort for condition 2
    std::sort(ages.begin(), ages.end());
    // split for condition 3
    std::vector<int>::iterator p1, p2, p3;
    int sum = 0;
    p1 = std::find(ages.begin(), ages.end(), 100);
    p2 = p1;
    std::cout << "p1: " << *p1 << ", p2: " << *p2 << std::endl;
    while (p2 != ages.end()) {
        p3 = p2;
        p2 = std::find(p2 + 1, ages.end(), 100);
        std::cout << "p2: " << *p2 << ", p3: " << *p3 << std::endl;
        // p3 = p2;
    }
    std::cout << "p1: " << *p1 << ", p2: " << *p2 << ", p3: " << *p3 << std::endl;
    std::cout << ages << std::endl;
    for (std::vector<int>::iterator i = p3; i >= ages.begin() + 1; i--) {
        std::cout << "i: " << *i << std::endl;
        for (std::vector<int>::iterator j = i - 1; j >= ages.begin(); j--) {
            std::cout << "j: " << *j << std::endl;
            if (*j > 0.5 * (*i) + 7) {
                sum++;
            }
            std::cout << "sum: " << sum << std::endl;
        }
    }
    std::cout << "----------------100----------------" << std::endl;
    for (std::vector<int>::iterator i = ages.end(); i != p1 + 1; i--) {
        std::cout << "i: " << *i << std::endl;
        for (std::vector<int>::iterator j = i - 1; j != p1; j--) {
            std::cout << "j: " << *j << std::endl;
            if (*j > 0.5 * (*i) + 7) {
                sum++;
            }
            std::cout << "sum: " << sum << std::endl;
        }
    }
    // find for condition 1
    return sum;
}

int main() {
    std::vector<int> ages = {1, 1, 2, 2, 3, 3, 5, 5, 60, 61, 7, 7, 4, 100, 102, 100, 99, 99, 130, 132, 101, 102};
    std::vector<int> ages2 = {20,30,100,110,120};
    // std::sort(ages.begin(), ages.end());
    // std::cout << ages << std::endl;
    std::cout << numFriendRequests(ages2) << std::endl;
    return 0;
}
