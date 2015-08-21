/* - the problem can be solved by solving the more general problem:
 *   find the k-th largest number in two sorted arrays
 * - a_0 <= a_1 <= ... <= a_{m/2} <= ... <= a_{m - 1}
 *                            |
 *   b_0 <= b_1 <= ... <= b_{n/2} <= ... <= b_{n - 1}
 *   compare k with (m/2 + n/2 + 1) and compare a_{m/2} with b_{n/2}
 *   there are 4 possibilities:
 *   1. if (m/2 + n/2 + 1) > k and a_{m/2} > b_{n/2}, then we can drop a_{m/2+1}, ..., a_{m-1}
 *   2. if (m/2 + n/2 + 1) > k and a_{m/2} < b_{n/2}, then we can drop b_{n/2+1}, ..., b_{n-1}
 *   3. if (m/2 + n/2 + 1) < k and a_{m/2} > b_{n/2}, then we can drop b_0, ..., b_{n/2}
 *   4. if (m/2 + n/2 + 1) < k and a_{m/2} < b_{n/2}, then we can drop a_0, ..., a_{m/2}
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if ((m + n) % 2 == 0) 
            return (find(nums1, nums2, (m + n) / 2, 0, m, 0, n) +
                    find(nums1, nums2, (m + n) / 2 + 1, 0, m, 0, n)) / 2.0;
        else
            return find(nums1, nums2, (m + n) / 2 + 1, 0, m, 0, n);
    }
    double find(vector<int>& nums1, vector<int>& nums2, int k,
        int i1, int j1, int i2, int j2) {
        // boundary conditions
        if (i1 == j1) return nums2[i2 + k - 1];
        if (i2 == j2) return nums1[i1 + k - 1];
        if (k <= 1) return min(nums1[i1], nums2[i2]);

        // eliminate at least one portion
        int mid1 = (i1 + j1) / 2, mid2 = (i2 + j2) / 2;
        int m = mid1 - i1 + 1, n = mid2 - i2 + 1;
        if (k >= m + n) {
            if (nums1[mid1] > nums2[mid2])
                return find(nums1, nums2, k - n, i1, j1, mid2 + 1, j2);
            else
                return find(nums1, nums2, k - m, mid1 + 1, j1, i2, j2);
        } else { // k < m + n
            if (nums1[mid1] > nums2[mid2])
                return find(nums1, nums2, k, i1, mid1, i2, j2);
            else
                return find(nums1, nums2, k, i1, j1, i2, mid2);
        }
    }
};

int main() {
    int a[] = { 1, 2 }, b[] = { 1, 2, 3 };
    vector<int> nums1(a, a + 1), nums2(b, b + 3);
    Solution solution;
    cout << solution.findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}
