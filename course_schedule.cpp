/* - set<int> s; ==> s.insert(1), s.insert(2); s.erase(1); s.erase(1);
 *                   it is OK to erase an non-existing element
 */
#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites) {
        set<int> courses;
        for (int i = 0; i < numCourses; i++)
            courses.insert(i);
        while (!courses.empty()) {
            set<int> initials = courses;
            for (int i = 0; i < prerequisites.size(); i++) {
                initials.erase(prerequisites[i].second);
            }
            if (initials.size() == 0) return false;
            for (int i = prerequisites.size() - 1; i >= 0; i--) {
                if (initials.count(prerequisites[i].first) > 0)
                    prerequisites.erase(prerequisites.begin() + i);
            }
            for (set<int>::iterator itr = initials.begin(); itr != initials.end(); itr++) {
                courses.erase(*itr);
                cout << *itr << endl;
            }
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
    courses.push_back(make_pair(1, 4));
    courses.push_back(make_pair(4, 5));
    courses.push_back(make_pair(4, 6));
    Solution solution;
    solution.canFinish(7, courses);
    return 0;
}
