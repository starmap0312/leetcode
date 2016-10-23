/* merge sort
 *   divide and conquer:
 *   sort nums[i..j]
 *   1) sort  nums[i..mid-1] and nums[mid..j-1] recursively
 *   2) merge nums[i..mid-1] and nums[mid..j-1] 
 */
#include <iostream>
#include <vector>

using namespace std;

void merge_sort(vector<int> &nums, int i, int j) {
    // base case
    if (j - i <= 1) return; // if at most one element to be sorted, return immediately

    // inductive case
    int mid = (i + j) / 2;
    merge_sort(nums, i, mid);
    merge_sort(nums, mid, j);
    // merge sorted nums[i..mid-1] and sorted nums[mid..j-1]
    int k1 = i, k2 = mid;
    vector<int> sorted;
    while (k1 < mid || k2 < j) {
        if (k1 == mid) {
            sorted.push_back(nums[k2]);
            k2++;
        } else if (k2 == j) {
            sorted.push_back(nums[k1]);
            k1++;
        } else {
            if (nums[k1] < nums[k2]) {
                sorted.push_back(nums[k1]);
                k1++;
            } else {
                sorted.push_back(nums[k2]);
                k2++;
            }
        }
    }
    // copy sorted array to nums[i..j]
    for (int k = 0; k < sorted.size(); k++) {
        nums[i + k] = sorted[k]; 
    }
}

int main() {
    int a[] = { 3, 1, 2, 5, 4 };
    vector<int> nums(a, a + 5);
    merge_sort(nums, 0, nums.size());
    for (int i = 0; i < nums.size(); i++)
        cout << nums[i] << " ";
    cout << endl;
    return 0;
}