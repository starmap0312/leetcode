/* - vector<int> v; ==> use v.push_back(3) and v.pop_back(); for undo choice of DFS
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string> > partition(string s) {
        if (s.size() == 0) return vector<vector<string> >();
        vector<vector<int> > prev;
        for (int i = 0; i < s.size(); i++) prev.push_back(vector<int>());
        for (int i = 0; i < s.size(); i++) suffixPartition(prev, s, i);
        vector<string> partition;
        DFS(partition, prev, s, s.size() - 1);
        return result; 
    }

    void DFS(vector<string> &partition, vector<vector<int> > &prev, const string &s, int i) {
        if (i < 0) {
            vector<string> p = partition;
            reverse(p.begin(), p.end());
            result.push_back(p);
            return;
        }
        for (int j = 0; j < prev[i].size(); j++) {
            partition.push_back(s.substr(prev[i][j], i - prev[i][j] + 1));
            DFS(partition, prev, s, prev[i][j] - 1);
            partition.pop_back();
        }
    }

    void suffixPartition(vector<vector<int> > &prev, const string &s, int i) {
        for (int j = 0; j <= i; j++) 
            if (isPalindrome(s, j, i)) prev[i].push_back(j);
    }

    bool isPalindrome(const string &s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++; j--;
        }
        return true;
    }
private:
    vector<vector<string> > result;
};

int main() {
    Solution solution;
    vector<vector<string> > result = solution.partition("aab");
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++)
            cout << result[i][j] << " ";
        cout << endl;
    }
    return 0;
}
