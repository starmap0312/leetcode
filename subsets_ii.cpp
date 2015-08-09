/* - to dedup, sort the answer by size and numbers in the set, and remove duplication from the
 *   answer
 */
#include <iostream>
#include <vector>

using namespace std;

bool isEqual(vector<int> &a, vector<int> &b) {
    if (a.size() != b.size()) return false;
    for (int i = 0; i < a.size(); i++)
        if (a[i] != b[i]) return false;
    return true;
}
bool compare(vector<int> &a, vector<int> &b) {
    if (a.size() < b.size()) return true;
    else if (a.size() > b.size()) return false;
    else {
        for (int i = 0; i < a.size(); i++) {
            if (a[i] > b[i]) return false;
            else if (a[i] < b[i]) return true;
        }
        return true;
    }
}

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > result;
        result.push_back(vector<int>());
        for (int i = 0; i < nums.size(); i++) {
            vector<vector<int> > copy = result;
            addElement(copy, nums[i]);
            result.insert(result.end(), copy.begin(), copy.end());
            dedup(result);
        }
        return result;
    }
    void dedup(vector<vector<int> > &v) {
        sort(v.begin(), v.end(), compare);
        for (int i = v.size() - 1; i > 0; i--) {
            if (isEqual(v[i], v[i - 1])) v.erase(v.begin() + i);
        }
    }
    void addElement(vector<vector<int> > &v, int n) {
        for (int i = 0; i < v.size(); i++) {
            v[i].push_back(n);
        }
    }
};

int main() {
    vector<int> nums;
    nums.push_back(1), nums.push_back(1);
    Solution solution;
    vector<vector<int> > result = solution.subsetsWithDup(nums);
    for (int i = 0; i < result.size(); i++) {
        cout << "[";
        int j;
        for (j = 0; j < (int)result[i].size() - 1; j++)
            cout << result[i][j] << ",";
        if (result[i].size() > 0) cout << result[i][j];
        cout << "]" << endl;
    }
    return 0;
}
