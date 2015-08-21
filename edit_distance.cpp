#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int> > distance(word1.size() + 1, vector<int>(word2.size() + 1));
        for (int i = 0; i <= word1.size(); i++)
            distance[i][0] = i;
        for (int j = 1; j <= word2.size(); j++)
            distance[0][j] = j;
        for (int i = 1; i <= word1.size(); i++)
            for (int j = 1; j <= word2.size(); j++)
                distance[i][j] = min(min(distance[i - 1][j] + 1, distance[i][j - 1] + 1), 
                    distance[i - 1][j - 1] + (word1[i - 1] != word2[j - 1]));
        return distance[word1.size()][word2.size()];
    }
};

int main() {
    Solution solution;
    cout << solution.minDistance("abc", "adc") << endl;
    return 0;
}
