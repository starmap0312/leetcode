#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for (int i = 0; i < n; i++) {
            int sum = gas[i];
            int j;
            for (j = 0; j < n; j++) {
                sum -= cost[(i + j) % n];
                if (sum < 0) break;
                sum += gas[(i + j + 1) % n];
            }
            if (j == n) return 1;
        }
        return -1;
    }
};

int main() {
    return 0;
}
