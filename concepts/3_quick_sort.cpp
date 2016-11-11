/* quick_sort():
 * ex.         mid              ==> pivot = nums[3] = 5
 *     0  1  2 (3) 4  5  6
 *    [3, 1, 2, 5, 4, 2, 3]
 * left,i               right,j
 *
 *     0  1  2  3  4  5  6  7
 *    [3, 1, 2,(5),4, 2,(3)]   ==> swap 5 and 3
 *   left       i       right,j
 *
 *    [3, 1, 2, 3, 4, 2,(5)]   ==> swap 5 and 5
 *   left             j i,right
 *
 */
#include <iostream>
#include <vector>

using namespace std;

void quick_sort(vector<int> &nums, int left, int right) {
    if (right <= left) return;
    int i = left, j = right;
    int mid = (left + right) / 2;
    int pivot = nums[mid];        // pick a pivot number
    // partition
    while (i <= j) {
        while (nums[i] < pivot) { // find a number >= pivot from left to right
            i++;
        }
        while (nums[j] > pivot) { // find a number <= pivot from right to left
            j--;
        }
        if (i <= j) {             // swap mis-positioned numbers, i.e. nums[i] >= pivot >= nums[j]
            swap(nums[i], nums[j]);
            i++; j--;
        }
    };
    // when the loop breaks at j < i, we have that:
    //   nums[i'] <= pivot for i' < i
    //   nums[j'] >= pivot for j' > j 
 
    // recursive step: solve the left and right partition recursively
    quick_sort(nums, left, j);
    quick_sort(nums, i, right);
}

void quick_sort2(vector<int> &nums, int left, int right) {
    if (right <= left) return;
    // left < right 
    int mid = (left + right) / 2;
    int pivot = nums[mid];            // pick a pivot number

    swap(nums[mid], nums[right]);     // swap pivot to the last position

    int i = left, j = right - 1;
    while (i <= j) {
        while (nums[i] <= pivot) {    // find a number > pivot from left to right
            i++;
        }
        while (nums[j] > pivot) {     // find a number <= pivot from right to left
            j--;
        }
        if (i <= j) {                 // swap mis-positioned numbers, i.e. nums[i] > pivot >= nums[j]
            swap(nums[i], nums[j]);
            i++; j--;
        }
    };
    if (i <= right) {
        swap(nums[i], nums[right]);      // swap pivot to its correct position
    }
    // recursively solve the problem
    quick_sort2(nums, left, i - 1);
    quick_sort2(nums, i + 1, right);
}

int main() {
    int a[] = { 5, 1, 1, 3, 2, 2, 5 };
    vector<int> nums(a, a + 7);
    quick_sort(nums, 0, nums.size() - 1);
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}
