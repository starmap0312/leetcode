/* - complete binary-tree index transformation:
 *
 *         1
 *      2     3
 *    4   5 6   7
 *
 *   given node index i:
 *     node i's parent      = i / 2
 *     node i's left child  = i * 2
 *     node i's right child = i * 2 + 1
 *
 * - complete binary-tree size = (1 + 2 + 4 + .. + 2^{k-1}) = 2^k - 1
 * - representing a tree using a vector and index transformation
 */
#include <iostream>
#include <vector>

using namespace std;

class NumArray {
public:
    NumArray(vector<int> &nums) {
        tree = vector<int>(nums.size() * 2);
        size = nums.size();
        buildTree(nums);
    }

    void buildTree(vector<int> &nums) {
        for (int i = nums.size(), j = 0;  i < 2 * nums.size(); i++,  j++) {
            tree[i] = nums[j];
        }
        for (int i = nums.size() - 1; i > 0; i--) {
            tree[i] = tree[i * 2] + tree[i * 2 + 1];
        }
    }

    void update(int pos, int val) {
        pos += size;
        tree[pos] = val;
        while (pos > 0) {
            int left = pos;
            int right = pos;
            if (pos % 2 == 0) {
                right = pos + 1;
            } else {
                left = pos - 1;
            }
            // parent is updated after child is updated
            tree[pos / 2] = tree[left] + tree[right];
            pos /= 2;
        }
    }

    int sumRange(int l, int r) {
        // get leaf with value 'l'
        l += size;
        // get leaf with value 'r'
        r += size;
        int sum = 0;
        while (l <= r) {
            if ((l % 2) == 1) {
               sum += tree[l];
               l++;
            }
            if ((r % 2) == 0) {
               sum += tree[r];
               r--;
            }
            l /= 2;
            r /= 2;
        }
        return sum;
    }

private:
    vector<int> tree;
    int size;
};

int main() {
    int a[] = { 1, 3, 5 };
    vector<int> nums(a, a + 3);
    NumArray numArray(nums);
    cout << numArray.sumRange(0, 1) << endl;
    numArray.update(1, 10);
    cout << numArray.sumRange(1, 2) << endl;
    return 0;
}
