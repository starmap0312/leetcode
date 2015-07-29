/* 
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool compare_nums(int num1, int num2) {
    string s1 = to_string(num1), s2 = to_string(num2);
    for(int i = 0, j = 0; i < s1.size() && j < s2.size(); i++, j++) {
        if(s1[i] < s2[j]) return false;
    }
    return true;
}

class Solution {
public:
    string largestNumber(vector<int> &nums);
private:
    void permute(vector<int> &selected, vector<int> &remaining);
    string convert(const vector<int> &nums);
    int compare(const string &s1, const string &s2);
    vector<int> max_nums;
};

string Solution::largestNumber(vector<int> &nums) {
    sort(nums.begin(), nums.end(), compare_nums);
    vector<int> selected, remaining = nums;
    permute(selected, remaining);
    return convert(max_nums);
}

string Solution::convert(const vector<int> &nums) {
    string results = "";
    for(int i = 0; i < nums.size() ; i++) {
        results += to_string(nums[i]);
    }
    return results;
}

int Solution::compare(const string &s1, const string &s2) {
    for(int i = 0, j = 0; i < s1.length() && j < s2.length(); i++, j++) {
        if(s1[i] > s2[j]) return 1;
        else if(s1[i] < s2[j]) return -1;
    }
    return 0;
}

void Solution::permute(vector<int> &selected, vector<int> &remaining) {
    if(compare(convert(max_nums), convert(selected)) > 0) return;
    if(remaining.size() == 0) {
        if(max_nums.size() == 0 || compare(convert(max_nums), convert(selected)) < 0)
            max_nums = selected;
    } else {
        for(int i = 0; i < remaining.size() ; i++) {
            if(i > 0 && !compare_nums(remaining[i], remaining[i-1])) break;
            if(i > 0 && remaining[i] == remaining[i-1]) break;
            vector<int> new_selected = selected;
            vector<int> new_remaining = remaining;
            new_selected.push_back(remaining[i]);
            new_remaining.erase(new_remaining.begin() + i);
            permute(new_selected, new_remaining);
        }
    }
}

int main() {
    Solution solution;
    //int a[10] = {6,5,6,5,6,5,6,5,6,5};
    int a[100] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    vector<int> nums(a, a + sizeof(a)/sizeof(a[0]));
    cout << solution.largestNumber(nums) << endl;
    return 0;
}
