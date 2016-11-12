/* - an O(n log n)-time algorithm
 * - observe that if point 7 is the right side of the max area and is "the lower side",
 *   we have that point 7 should be paired with point 4 (its upperbound)
 *   1) points 1, 2, 3 are lower than point 7, and hence they are not the candidates
 *   2) points marked with o cannot be the left side, because they have one higher point on the
 *      left, which are better choices for the left side
 *   ex.
 *                             6
 *                 "4"   5     x
 *                  x    o        "7"
 *               3  |<------------ x
 *       2       x    o      o
 *   1   x    o            o
 *   x      o 
 *
 * - therefore, scanning from left to right and maintaining a list of increasing points
 *   (i.e. points 1, 2, 3, 4, 5), one can binary search for the upperbound of point 7, i.e. point 4
 * - a second-phase scan from right to left identifies the other possibility of max area
 * - the total time required by the two-phases algorithm is O(n log n)
 * - observe that the time can be improved to O(n) by scanning from both ends at the same time,
 *   identifying the upperbound of each point in one-phase scan
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.size() <= 1) return 0;
        int maxArea = findMaxArea(height);
        reverse(height.begin(), height.end());
        int maxArea2 = findMaxArea(height);
        return max(maxArea, maxArea2);
    }

    int findMaxArea(vector<int>& height) {
        int maxArea = INT_MIN;
        vector<pair<int, int> > heights;
        heights.push_back(make_pair(0, height[0]));
        for (int i = 1; i < height.size(); i++) {
            int index = upperbound(heights, height[i]);
            if (index < heights.size()) {
                int area = min(heights[index].second, height[i]) *
                    (i - heights[index].first);
                if (area > maxArea) maxArea = area;
            }
            if (height[i] > heights.back().second)
                heights.push_back(make_pair(i, height[i]));
        }
        return maxArea;
    }

    int upperbound(vector<pair<int, int> > &heights, int value) {
        int start = 0, end = heights.size();
        while (start < end) {
            int mid = (start + end) / 2;
            if (heights[mid].second == value) {
                return mid;
            } else if (heights[mid].second < value) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }
        return start;
    }
};

int main() {
    int a[7] = { 2, 3, 10, 5, 7, 8, 9 };
    vector<int> height(a, a + sizeof(a) / sizeof(a[0]));
    Solution solution;
    cout << solution.maxArea(height) << endl;
    return 0;
}
