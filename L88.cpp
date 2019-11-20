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

void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
    int k = nums1.size();
    while (m > 0 and n > 0 and k > 0) {
        if (nums1[m - 1] > nums2[n - 1]) {
            nums1[k - 1] = nums1[m - 1];
            m--;
            k--;
        } else {
            nums1[k - 1] = nums2[n - 1];
            n--;
            k--;
        }
    }
    if (m == 0) {
        for (int i = 0; i < n; i++) {
            nums1[i] = nums2[i];
        }
    }
}

int main() {
    std::vector<int> nums1 = {1,2,3,0,0,0};
    std::vector<int> nums2 = {2,5,6};
    merge(nums1, 3, nums2, 3);
    std::cout << nums1 << std::endl;
    return 0;
}
