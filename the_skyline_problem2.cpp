/* - define named constants:
 *   enum MY_TYPE { CONST1, CONST2 }; ==> MY_TYPE var_name = CONST1;
 * - priority_queue<int> heap; ==> heap.push(3), heap.pop() returns the maximum value
 *                                 heap.pop() deletes the maximum value from queue
 *                                 while (!heap.empty()) { 
 *                                    heap.top();heap.pop(); 
 *                                 } // use the above to traverse the priority queue
 *                                 priority_queue has no iterator
 * - vector<int> v; ==> sort(v.begin(), v.end(), cmp_func)
 *   bool cmp_func(const int &a, const int &b) defines when a precedes b
 *   i.e. cmp_func() returns true if a precedes b, otherwise it returns false
 * - priority_queue<int> heap; ==> heap.push(3), heap.pop() to add/remove elements
 *                                 priority queue has no iterator, use the following
 *   traverse the priority queue:
 *     while(!heap.empty()) {
 *         heap.top(); heap.pop();
 *     }
 * - int a, b; ==> use make_pair(a, b) to create a pair<int, int> instance
 * - use "lazy deletion" of the priority queue to solve this problem
 */
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
private:
    enum POINT_TYPE { LEFT, RIGHT };

    class Point {
    public:
        Point(int x, int y, POINT_TYPE t) {
            pos.first = x, pos.second = y;
            type = t;
        }
        pair<int, int> pos;
        int type;
    };

    static bool comparePoint(const Point &a, const Point &b) {
        // returns true if a precedes b (ex. a < b)
        if (a.pos.first != b.pos.first)
            return (a.pos.first < b.pos.first);
        else if (a.type == LEFT && b.type == LEFT)
            return a.pos.second > b.pos.second;
        else if (a.type == RIGHT && b.type == RIGHT)
            return a.pos.second < b.pos.second;
        else 
            return a.type == LEFT;
    }

public:
    vector<pair<int, int> > getSkyline(vector<vector<int> >& buildings) {
        vector<pair<int, int> > result;
        if (buildings.size() == 0) return result;

        vector<Point> points;
        for (int i = 0; i < buildings.size(); i++) {
            points.push_back(Point(buildings[i][0], buildings[i][2], LEFT));
            points.push_back(Point(buildings[i][1], buildings[i][2], RIGHT));
        }

        sort(points.begin(), points.end(), comparePoint);

        priority_queue<int> heap;
        unordered_map<int, int> mp;
        int prev = 0;
        for (int i = 0; i < points.size(); i++) {
            if (points[i].type == LEFT) {
                heap.push(points[i].pos.second);
            } else {
                mp[points[i].pos.second]++;
                while (!heap.empty() && mp[heap.top()] > 0) {
                    mp[heap.top()]--;
                    heap.pop();
                }
            }
            int cur = (heap.size() > 0? heap.top(): 0);
            if (cur != prev) {
                result.push_back(make_pair(points[i].pos.first, cur));
                prev = cur; 
            }
        }
        return result;
    }
};

int main() {
    vector<vector<int> > buildings;
    int a[5][3] = { {2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8} };
    buildings.push_back(vector<int>(a[0], a[0] + 3));
    buildings.push_back(vector<int>(a[1], a[1] + 3));
    buildings.push_back(vector<int>(a[2], a[2] + 3));
    buildings.push_back(vector<int>(a[3], a[3] + 3));
    buildings.push_back(vector<int>(a[4], a[4] + 3));
    Solution solution;
    vector<pair<int, int> > result = solution.getSkyline(buildings);
    for (int i = 0; i < result.size(); i++)
        cout << result[i].first << " " << result[i].second << endl;
    return 0;
}
