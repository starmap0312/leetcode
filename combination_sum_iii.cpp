#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum3(int k, int n) {
        vector<int> path;
        DFS(k, n, 1, path);
        return result; 
    }
    void DFS(int k, int n, int index, vector<int> &path) {
        if (path.size() > k || n < 0) return;
        if (path.size() == k && n == 0) {
            result.push_back(path);
            return;
        }
        for (int i = index; i <= 9; i++) {
            path.push_back(i);
            DFS(k, n - i, i + 1, path);
            path.pop_back();
        }
    }
private:
    vector<vector<int> > result;
};

int main() {
    Solution solution;
    vector<vector<int> > result = solution.combinationSum3(3, 15);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++)
            cout << result[i][j] << " ";
        cout << endl;
    }
    return 0;
}
