#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Point {
public:
    int x;
    int y;
    Point() : x(0), y(0) { }
    Point(int a, int b) : x(a), y(b) { }
};

class Solution {
public:
    int maxPoints(vector<Point>& points) {
        if (points.size() == 0) return 0;
        int maxCount = INT_MIN;
        for (int i = 0; i < points.size(); i++) {
            unordered_map<double, int> count;
            int dup = 1, infinity = 0;
            for (int j = 0; j < points.size(); j++) {
                if (i == j) continue; 
                if (points[j].x == points[i].x && points[j].y == points[i].y) dup++;
                else if (points[j].x == points[i].x) infinity++;
                } else {
                    double slope = (double)(points[j].y - points[i].y) / 
                        (points[j].x - points[i].x);
                    count[slope]++;
                }
            }
            maxCount = max(maxCount, max(findMax(count) + dup, infinity + dup));
        }
        return maxCount;
    }
    int findMax(unordered_map<double, int> &count) {
        int result = INT_MIN;
        for (unordered_map<double, int>::iterator itr = count.begin(); itr != count.end(); itr++)
            if (itr -> second > result) result = itr -> second;
        return result;
    }
};

int main() {
    Solution solution;
    vector<Point> points;
    points.push_back(Point(84, 250));
    points.push_back(Point(0, 0));
    points.push_back(Point(1, 0));
    points.push_back(Point(0, -70));
    points.push_back(Point(0, -70));
    points.push_back(Point(1, -1));
    points.push_back(Point(21, 10));
    points.push_back(Point(42, 90));
    points.push_back(Point(-42, -230));
    cout << solution.maxPoints(points) << endl;
    return 0;
}
