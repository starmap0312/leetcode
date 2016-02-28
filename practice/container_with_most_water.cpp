/* - an O(n ^ 2)-time algorithm
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.size() <= 1) return 0;
        int maxArea = INT_MIN;
        for (int i = 0; i < height.size(); i++) {
            for (int j = 0; j < i; j++) {
                int area = min(height[i], height[j]) * (i - j);
                if (area > maxArea) maxArea = area;
            }
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
