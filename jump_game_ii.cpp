/* - scan from left to right, maintaining a vector of right extensions
 *   try to update/append extensions of the vector on the fly
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() <= 1) return 0;
        vector<pair<int, int> > v;
        v.push_back(make_pair(nums[0], 1));
        int ind = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (i == nums.size() - 1 && i <= v[ind].first)
                return v[ind].second;
            if (i > v[ind].first) {
                ind++;
                if (ind >= v.size()) return 0;
            }
            if (i + nums[i] > v.back().first) {
                if (v[ind].second + 1 > v.back().second) {
                    v.push_back(make_pair(i + nums[i], v[ind].second + 1));
                } else
                    v.back().first = i + nums[i];
            }
        }
        return v[ind].second;
    }
};

int main() {
    int a[] = { 2, 3, 1, 1, 4 };
    vector<int> nums(a, a + 5);
    Solution solution;
    cout << solution.jump(nums) << endl;
    return 0;
}
