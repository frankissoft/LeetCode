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

std::vector<int> sortArrayByParity(std::vector<int>& A) {
    int i = 0, j = 1;
    while (1) {
        if (j >= A.size()) {
            break;
        }
        if (A[i] % 2 == 1 and A[j] % 2 == 1) {
            j++;
        } else if (A[i] % 2 == 1 and A[j] % 2 == 0) {
            std::swap(A[i], A[j]);
            std::cout << A << std::endl;
            i++;
            j++;
        // } else if (A[i] % 2 == 0 and A[j] % 2 == 0) {
        } else {
            i++;
            j++;
        }
        // } else {
        //     i += 2;
        //     j += 2;
        // }
    }
    // int pos = 0;
    // for (int i = 0; i < A.size(); i++) {
    //     if (A[i] % 2 == 1) {
    //         pos = i;
    //         break;
    //     }
    // }
    // std::sort(A.begin(), A.begin() + pos);
    // std::sort(A.begin() + pos, A.end());
    return A;
}

int main() {
    std::vector<int> A = {0,1,2};
    std::cout << sortArrayByParity(A) << std::endl;
    return 0;
}
