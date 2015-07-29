#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    Solution() : kth(0), chosen_k(0), permute_string("") { }
    string getPermutation(int n, int k) {
        vector<int> selected, rest;
        for(int i = 1; i <= n; i++) rest.push_back(i);
        chosen_k = k;
        permute(selected, rest);
        return permute_string;
    }

    void permute(vector<int> &selected, vector<int> &rest) {
        if (permute_string != "") return;
        if (rest.size() == 0) {
            kth++;
            if (kth == chosen_k) permute_string = convert(selected);
            return;
        }
        for(int i = 0; i < rest.size(); i++) {
            vector<int> new_selected = selected;
            vector<int> new_rest = rest;
            new_selected.push_back(rest[i]);
            new_rest.erase(new_rest.begin() + i);
            permute(new_selected, new_rest);
        }
    }

    string convert(vector<int> &nums) {
        string results = "";
        for(int i = 0; i < nums.size(); i++)
            results += to_string(nums[i]);
        return results;
    }
private:
    int kth, chosen_k;
    string permute_string;
};

int main() {
    Solution solution;
    cout << solution.getPermutation(4, 10) << endl;
    return 0;
}
