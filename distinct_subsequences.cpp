#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int dist[t.size() + 1][s.size() + 1];
        int choices[t.size() + 1][s.size() + 1];
        for (int j = 0; j <= s.size(); j++) { dist[0][j] = 0; choices[0][j] = 1; }
        for (int i = 1; i <= t.size(); i++) { dist[i][0] = i; choices[i][0] = 0; }
        for (int i = 1; i <= t.size(); i++) {
            for (int j = 1; j <= s.size(); j++) {
                if (t[i - 1] == s[j - 1]) {
                    dist[i][j] = min(dist[i - 1][j - 1], dist[i][j - 1]);
                    if (dist[i - 1][j - 1] < dist[i][j - 1])
                        choices[i][j] = choices[i - 1][j - 1];
                    else if (dist[i - 1][j - 1] > dist[i][j - 1])
                        choices[i][j] = choices[i][j - 1];
                    else
                        choices[i][j] = choices[i - 1][j - 1] + choices[i][j - 1];
                } else {
                    dist[i][j] = dist[i][j - 1];
                    choices[i][j] = choices[i][j - 1];
                }
            }
            for (int j = 0; j <= s.size(); j++) cout << choices[i][j] << " ";
            cout << endl;
        }
        return (dist[t.size()][s.size()] == 0? choices[t.size()][s.size()]: 0);
    }
};

int main() {
    string s = "b", t = "a";
    Solution solution;
    cout << solution.numDistinct(s, t) << endl;
    return 0;
}
