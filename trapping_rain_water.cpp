/* - the problem can be solved by a two-phases algorithm:
 *   first, scan from left to right to find the left largest height at each position
 *   next, scan from right to left to find the right largest height at each position
 *   finally, find the amount of water that can be sustained at each position using the left
 *   and right largest heights
 * - the problem is similar to the problem of "candy" 
 */ 
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() == 0) return 0;
        vector<int> leftBounds, rightBounds;
        int maxHeight = INT_MIN;
        for (int i = 0; i < height.size(); i++) {
            maxHeight = max(maxHeight, height[i]);
            leftBounds.push_back(maxHeight);
        }
        maxHeight = INT_MIN;
        for (int i = height.size() - 1; i >= 0; i--) {
            maxHeight = max(maxHeight, height[i]);
            rightBounds.push_back(maxHeight);
        }
        int sum = 0;
        for (int i = 0; i < height.size(); i++) {
            sum += min(leftBounds[i], rightBounds[height.size() - i - 1]) - height[i];
        }
        return sum;
    }
};

int main() {
    int a[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
    vector<int> height(a, a + 11);
    Solution solution;
    cout << solution.trap(height) << endl;
    return 0;
}
