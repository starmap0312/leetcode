/* - an O(n)-time algorithm: improve upon previous solution
 *   start from outmost lines
 *   move the line with shorter height inward (so move the line with higher height inward is not beneficial)
 *   record the best solution on the fly and continue until no more combinations
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.size() <= 1) return 0;
        int maxArea = INT_MIN;
        int left = 0, right = height.size() - 1;
        while (left < right) {
            int area = min(height[left], height[right]) * (right - left);
            if (area > maxArea) maxArea = area;
            if (height[left] < height[right]) left++;
            else right--;
        }
        return maxArea;
    }
};

int main() {
    int a[7] = { 2, 3, 10, 5, 7, 8, 9 };
    vector<int> height(a, a + sizeof(a) / sizeof(a[0]));
    Solution solution;
    cout << solution.maxArea(height) << endl;
    return 0;
}
