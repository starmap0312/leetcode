/* - pair<int, string> v(1, "abc"); ==> use v.first & v.second to access
 *   pair<int, string> u = make_pair(2, string("cde")); ==> use u.first & u.second to access
 * - vector<int> v; ==> v.insert(v.begin() + 1, 3) inserts 3 as v[1], i.e. before v.begin() + 1
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<pair<int, int> > getSkyline(vector<vector<int> >& buildings) {
        if (buildings.size() == 0) return result;
        vector<pair<int, int> > ends;
        push(ends, make_pair(INT_MAX, 0));
        x = 0;
        int i = 0;
        while (i < buildings.size()) {
            if (getLeftBound(buildings, i) <= getLeftBound(ends)) {
                if (push(ends, make_pair(buildings[i][1], buildings[i][2]))) {
                    result.push_back(make_pair(x , buildings[i][2]));
                }
                x = getLeftBound(buildings, i);
                i++;
            } else {
                x = getLeftBound(ends);
                ends.erase(ends.begin());
                if (ends.size() != 0) result.push_back(make_pair(x , ends.begin() -> second));
            }
        }
        while (!ends.empty()) {
            int x = getLeftBound(ends);
            ends.erase(ends.begin());
            if (ends.size() != 0) result.push_back(make_pair(x , ends.begin() -> second));
        }
        result.erase(result.begin());
        if (result.size() == 1 && result[0].first < INT_MAX)
            result.push_back(make_pair(INT_MAX, 0));
        for (int j = 0; j < result.size() - 1;) {
            if (result[j].second == result[j + 1].second) {
                result.erase(result.begin() + j);
            } else j++;
        }
        return result;
    }

    int getLeftBound(vector<vector<int> >& v, int i) {
        if (v.size() - i > 0) return v[i][0];
        else return INT_MAX;
    }

    int getLeftBound(vector<pair<int, int> >& v) {
        if (v.size() > 0) return v[0].first;
        else return INT_MAX;
    }

    int findLowerBound(vector<pair<int, int> > &v, int x) {
        /*int i;
        for (i = v.size() - 1; i >= 0; i--)
            if (v[i].first <= x ) break;
        return i;
        */
        int first = 0, last = v.size();
        while (last - first > 0) {
            int i = (first + last) / 2;
            if (v[i].first > x) last = i;
            else first = i + 1;
        }
        if (first == v.size()) return v.size() - 1; 
        if (v[first].first > x) return first - 1;
        else return first;
    }

    bool push(vector<pair<int, int> > &v, pair<int, int> u) {
        int i;
        for (i = findLowerBound(v, u.first); i >= 0; i--) {
            if (u.second >= v[i].second) v.erase(v.begin() + i);
            else break;
        }
        v.insert(v.begin() + i + 1, u);
        if (i + 1 == 0) return true;
        else return false;
    }

private:
    int x;
    vector<pair<int, int> > result;
};

int main() {
    vector<vector<int> > buildings;
    /*
    int a[5][3] = { {2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8} };
    buildings.push_back(vector<int>(a[0], a[0] + 3));
    buildings.push_back(vector<int>(a[1], a[1] + 3));
    buildings.push_back(vector<int>(a[2], a[2] + 3));
    buildings.push_back(vector<int>(a[3], a[3] + 3));
    buildings.push_back(vector<int>(a[4], a[4] + 3));
    */
    vector<int> a; a.push_back(0), a.push_back(2), a.push_back(3);
    buildings.push_back(a);
    vector<int> b; b.push_back(2), b.push_back(5), b.push_back(3);
    buildings.push_back(b);
    Solution solution;
    vector<pair<int, int> > result = solution.getSkyline(buildings);
    for (int i = 0; i < result.size(); i++)
        cout << result[i].first << " " << result[i].second << endl;
    return 0;
}
