#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites) {
        while (numCourses > 0) {
            set<int> sink;
            for (int i = 0; i < prerequisites.size(); i++) {
                sink.insert(prerequisites[i].second);
            }
            if (numCourses == sink.size()) return false;
            for (int i = prerequisites.size() - 1; i >= 0; i--) {
                if (sink.count(prerequisites[i].first) == 0) {
                    prerequisites.erase(prerequisites.begin() + i);
                }
            }
            numCourses = sink.size();
        }
        return true;
    }
};

int main() {
    vector<pair<int, int> > courses;
    courses.push_back(make_pair(0, 3));
    courses.push_back(make_pair(1, 3));
    courses.push_back(make_pair(2, 0));
    courses.push_back(make_pair(2, 1));
    Solution solution;
    cout << solution.canFinish(4, courses) << endl;
    return 0;
}
