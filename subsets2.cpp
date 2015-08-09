#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &nums);
private:
    vector<vector<int> > subsets_partial(vector<int> &nums, vector<int>::iterator end);
};

vector<vector<int> > Solution::subsets(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    return subsets_partial(nums, nums.end());
}

vector<vector<int> > Solution::subsets_partial(vector<int> &nums, vector<int>::iterator end) {
    vector<vector<int> > results;
    if (end - nums.begin() == 0) {
        vector<int> empty;
        results.push_back(empty);
        return results;
    }
    int max_num = *(end - 1);
    vector<vector<int> > no_max_subsets = subsets_partial(nums, end - 1);
    for (vector<vector<int> >::iterator itr = no_max_subsets.begin();
        itr != no_max_subsets.end(); itr++) {
        results.push_back(*itr);
        (*itr).push_back(max_num);
        results.push_back(*itr);
    }
    return results;
}

int main() {
    const int n[4] = { 3, 5, 1, 8 };
    vector<int> nums(n, n + 4);
    Solution s;
    vector<vector<int> > subsets = s.subsets(nums);
    for (vector<vector<int> >::iterator itr = subsets.begin(); itr != subsets.end(); itr++) {
        cout << "[";
        for (vector<int>::iterator itr_n = (*itr).begin(); itr_n != (*itr).end(); itr_n++) {
            if (itr_n + 1 != (*itr).end())
                cout << *itr_n << ", ";
            else
                cout << *itr_n;
        }
        cout << "]" << endl;
    }
    return 0;
}
