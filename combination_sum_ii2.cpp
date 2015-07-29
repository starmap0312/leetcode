#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        if (candidates.size() == 0) return vector<vector<int> >();
        sort(candidates.begin(), candidates.end());
        vector<int> path;
        DFS(candidates, target, 0, path);
        return result; 
    }
    void DFS(vector<int> &candidates, int target, int index, vector<int> &path) {
        if (target == 0) {
            result.push_back(path);
            return;
        } else if (target < 0) return;
        int pre = -1;
        for (int i = index; i < candidates.size(); i++) {
            if (candidates[i] != pre) {
                path.push_back(candidates[i]);
                DFS(candidates, target - candidates[i], i + 1, path);
                path.pop_back();
                pre = candidates[i];
            }
        }
    }
private:
    vector<vector<int> > result;
};

int main() {
    Solution solution;
    vector<int> candidates;
    candidates.push_back(10), candidates.push_back(1);
    candidates.push_back(2), candidates.push_back(7);
    candidates.push_back(6), candidates.push_back(1);
    candidates.push_back(5);
    vector<vector<int> > result = solution.combinationSum2(candidates, 8);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++)
            cout << result[i][j] << " ";
        cout << endl;
    }
    return 0;
}
