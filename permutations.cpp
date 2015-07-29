#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int>& nums) {
        runPermutation(vector<int>(), nums);
        return result;
    }
    void runPermutation(vector<int> selected, vector<int> rest) {
        if (rest.size() == 0) {
            result.push_back(selected);
        }
        for (int i = 0; i < rest.size(); i++) {
            int val = rest[i];
            selected.push_back(val);
            rest.erase(rest.begin() + i);
            runPermutation(selected, rest);
            rest.insert(rest.begin() + i, val);
            selected.pop_back();
        }
    }
private:
    vector<vector<int> > result;
};

int main() {
    int a[3] = { 1, 2, 3 };
    vector<int> nums(a, a + 3);
    Solution solution;
    vector<vector<int> > result = solution.permute(nums);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++)
            cout << result[i][j] << " ";
        cout << endl;
    }
    return 0;
}
