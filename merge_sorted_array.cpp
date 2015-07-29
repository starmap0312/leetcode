#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        shift(nums1, m, n);
        int i = n, j = 0, itr = 0;
        while (i < m + n && j < n) {
            if (nums1[i] < nums2[j]) nums1[itr++] = nums1[i++];
            else nums1[itr++] = nums2[j++];
        }
        while (i < m + n) nums1[itr++] = nums1[i++];
        while (j < n) nums1[itr++] = nums2[j++];
    }
    void shift(vector<int>& nums1, int m, int n) {
        for (int i = m - 1, j = m + n - 1; i >= 0; i--, j--)
            nums1[j] = nums1[i];
    }
};

int main() {
    int a[] = { 0, 0, 0, 0, 0 };
    int b[] = { 1, 2, 3, 4, 5 };
    vector<int> nums1(a, a + 5), nums2(b, b + 5);
    Solution solution;
    solution.merge(nums1, 0, nums2, 5);
    return 0;
}
