#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
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
        for (int i = index; i < candidates.size(); i++) {
            path.push_back(candidates[i]);
            DFS(candidates, target - candidates[i], i, path);
            path.pop_back();
        }
    }
private:
    vector<vector<int> > result;
};

int main() {
    Solution solution;
    vector<int> candidates;
    candidates.push_back(3), candidates.push_back(2);
    candidates.push_back(7), candidates.push_back(6);
    vector<vector<int> > result = solution.combinationSum(candidates, 7);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++)
            cout << result[i][j] << " ";
        cout << endl;
    }
    return 0;
}
