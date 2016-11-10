/* merge sort
 *   divide and conquer:
 *   sort nums[left..right]
 *   1) sort  nums[left..mid-1] and nums[mid..right-1], recursively
 *   2) merge nums[left..mid-1] and nums[mid..right-1] to an extra array 
 *      there is no easy in-place merge that does not downgrade the performance 
 *      naive in-place merge downgrades the performance to overall O(n^2)-time
 */
#include <iostream>
#include <vector>

using namespace std;

void merge_sort(vector<int> &nums, int left, int right) {
    // base case
    if (right - left <= 1) return; // if at most one element to be sorted, return immediately

    // inductive case
    int mid = (left + right) / 2;
    merge_sort(nums, left, mid);
    merge_sort(nums, mid, right);
    // merge sorted nums[left..mid-1] and sorted nums[mid..right-1]
    int i = left, j = mid;
    vector<int> merged;
    while (i < mid || j < right) {
        if (i == mid) {
            merged.push_back(nums[j]);
            j++;
        } else if (j == right) {
            merged.push_back(nums[i]);
            i++;
        } else {
            if (nums[i] < nums[j]) {
                merged.push_back(nums[i]);
                i++;
            } else {
                merged.push_back(nums[j]);
                j++;
            }
        }
    }
    // copy merged array to nums[left..right]
    for (int i = 0; i < merged.size(); i++) {
        nums[left + i] = merged[i]; 
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
