/* - isalnum('C') == true
 * - tolower('C') == 'c'
 */
#include <iostream>
#include <set>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

int binary(vector<int> &nums, int target, int start, int end) {
    if (start >= end) return -1;
    int middle = (start + end) / 2;
    if (nums[middle] == target) return middle;
    else if (target < nums[middle]) return binary(nums, target, start, middle);
    else return binary(nums, target, middle + 1, end);
}

int search(vector<int> &nums, int target) {
    return binary(nums, target, 0, nums.size());
}

int iterSearch(vector<int> &nums, int target) {
    int start = 0, end = nums.size();
    while (start < end) {
        int middle = (start + end) / 2;
        if (nums[middle] == target) return middle;
        else if (target < nums[middle]) end = middle;
        else start = middle + 1;
    }
    return -1;
}

int main() {
    cout << (5 & 6 & 7) << endl;
    return 0;
}
