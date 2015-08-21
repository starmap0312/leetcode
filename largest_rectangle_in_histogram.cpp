/* - the problem can be solved by scanning from left to right and maintain a stack of indices with
 *   increasing heights
 * - how an index with a height can contribute to the final answer is determined when it is popped
 *   out of the stack, or in the final run when the scan is over
 */
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        if (height.size() == 0) return 0;
        stack<int> q;
        int maxArea = INT_MIN;
        for (int i = 0; i < height.size(); i++) {
            while (!q.empty() && height[i] <= height[q.top()]) {
                int y = height[q.top()];
                q.pop();
                int x = (q.empty()? 0: q.top() + 1);
                int area = (i - x) * y;
                if (area > maxArea) maxArea = area;
            }
            q.push(i);
        }
        while (!q.empty()) {
            int y = height[q.top()];
            q.pop();
            int x = (q.empty()? 0: q.top() + 1);
            int area = (height.size() - x) * y;
            if (area > maxArea) maxArea = area;
        }
        return maxArea;
    }
};

int main() {
    int a[] = { 4, 2 }; 
    vector<int> height(a, a + 2);
    Solution solution;
    cout << solution.largestRectangleArea(height) << endl;
    return 0;
}
