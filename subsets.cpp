#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &nums);

private:
    int find_max_index(vector<int> &nums);
    vector<int> erase_max(vector<int> &nums);
};

vector<vector<int> > Solution::subsets(vector<int> &nums) {
    vector<vector<int> > results;
    if(nums.size() == 0) {
        results.push_back(nums);
        return results;
    }
    int max_num = nums[find_max_index(nums)];
    vector<int> no_max_nums = erase_max(nums);
    vector<vector<int> > no_max_subsets = subsets(no_max_nums);
    for(vector<vector<int> >::iterator itr = no_max_subsets.begin();
        itr != no_max_subsets.end(); itr++) {
        results.push_back(*itr);
        (*itr).push_back(max_num);
        results.push_back(*itr);
    }
    return results;
}

int Solution::find_max_index(vector<int> &nums) {
    if(nums.size() == 0) return -1;
    int max_index = 0;
    for(int i = 1; i < nums.size() ; i++)
        if(nums[max_index] < nums[i]) max_index = i;
    return max_index;
}

vector<int> Solution::erase_max(vector<int> &nums) {
    vector<int> results = nums;
    if(nums.size() == 0) return results;
    int max_index = find_max_index(nums);
    results.erase(results.begin() + max_index);
    return results;
}

int main() {
    const int n[4] = {3, 5, 1, 8};
    vector<int> nums(n, n + 4);
    Solution s;
    vector<vector<int> > subsets = s.subsets(nums);
    for(vector<vector<int> >::iterator itr = subsets.begin(); itr != subsets.end(); itr++) {
        cout << "[";
        for(vector<int>::iterator itr_n = (*itr).begin(); itr_n != (*itr).end(); itr_n++) {
            if(itr_n + 1 != (*itr).end()) cout << *itr_n << ", ";
            else cout << *itr_n;
        }
        cout << "]" << endl;
    }
    return 0;
}
