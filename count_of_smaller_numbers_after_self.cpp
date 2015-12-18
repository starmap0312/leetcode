/* - the problem can be solved via recursion (based on the merge-sort procedure)
 *   if we know the answers in two evenly separated parts and the values in these parts are sorted
 *   we can easily compute the answers of the one merged part
 *   ex.  _   _   _   _      ==> 4 separated parts
 *        5   4   1   8      ==> input array
 *       (0) (0) (0) (0)     ==> the answers in 4 separated part
 *   0. initially, the answer in each part is 0 (no smaller element on its right in each part)
 *        _____   _____      ==> 2 separated parts
 *        5   4   8   1
 *       (1) (0) (0) (0)     ==> the answers in 2 merged part
 *   1. during the first merge:
 *   consider value 5: to merge two parts, we need to know its order in the right part (it is
 *   larger than value 4); as only one element 4 is smaller than 5, the answer of value 5 is 
 *   updated to 1, i.e. 0 (the order in the left part) + 1 (the order in right part)
 *        _____________      ==> 1 merged part
 *        8   5   4   1
 *       (0) (2) (1) (0)     ==> the answers in 1 merged part
 *   2. during the second merge:
 *   consider value 5: to merge two parts, we need to know its order in the right segment (it is
 *   larger than value 1); as only one element 1 is smaller than 5, the answer of value 5 is 
 *   updated to 2, i.e. 1 (the order in left part) + 1 (the order in right part)
 *   3. final result:
 *           5   4   1   8   ==> input array
 *   return (2) (1) (0) (0) as the answer
 * - the total time required is O(n log n)
 * - the problem can be solved via a more intuitive approach using binary search tree
 *   scan the input array from right to left while maintaining a binary search tree
 *   whenever a new number is read, it is inserted into the tree and the count of its smaller
 *   number is computed
 *   this approach also takes O(n log n) if a "balanced" binary search tree is constructed
 *   however, if the tree is not balanced, the worst time complexity is O(n ^ 2)
 */
#include <iostream>
#include <vector>

using namespace std;

class Triple {
public:
    Triple(int a, int b, int c) : value(a), index(b), count(c) { }
    void copy(Triple &t) {
        value = t.value;
        index = t.index;
        count = t.count;
    }
    int value, index, count;
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        if (nums.size() == 0) return vector<int>();
        vector<int> result(nums.size());
        vector<Triple> values;
        for (int i = 0; i < nums.size(); i++)
            values.push_back(Triple(nums[i], i, 0));
        merge(values, 0, values.size());
        for (int i = 0; i < values.size(); i++)
            result[values[i].index] = values[i].count;
        return result;
    }

    void merge(vector<Triple> &values, int i, int j) {
        if (j == i + 1) return;
        int mid = (i + j) / 2;
        merge(values, i, mid);
        merge(values, mid, j);
        vector<Triple> tmp;
        int k = i, l = mid;
        while (k < mid || l < j) {
            if (l == j || (k < mid && values[k].value > values[l].value)) {
                tmp.push_back(Triple(values[k].value, values[k].index, values[k].count + j - l));
                k++;
            } else {
                tmp.push_back(Triple(values[l].value, values[l].index, values[l].count));
                l++;
            }
        }
        for (int k = 0; k < tmp.size(); k++) {
            values[i + k].copy(tmp[k]);
        }
    }
};

int main() {
    int a[] = { 5, 2, 6, 1 };
    vector<int> nums(a, a + 4);
    Solution solution;
    vector<int> counts = solution.countSmaller(nums);
    for (int i = 0; i < counts.size(); i++)
        cout << counts[i] << " ";
    cout << endl;
    return 0;
}
