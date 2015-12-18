/* - use two heaps, one max-heap and one min-heap, to solve the problem
 * - the max-heap maintains the smaller numbers, whereas the min-heap maintains the
 *   larger numbers; the two heaps are of almost the identical size
 * - the median is the mean of the top numbers of two heaps if the size of the two heaps is 
 *   identical; otherwise, the median is the top number of the max-heap
 * - to add a new number to the two heaps, compare the top numbers of the two heaps and take
 *   the sizes of the two heaps also into account, so that after the addition of the number
 *   the sizes of two heaps are still almost identical and all the numbers in the max-heap are
 *   still smaller than all the numbers in the min-heap
 * - the time for adding a number is: O(log n)
 *   the time for querying the median is: O(1)
 */
#include <iostream>
#include <queue>

using namespace std;

class MedianFinder {
public:

    // Adds a number into the data structure.
    void addNum(int num) {
        if (maxHeap.size() == 0) {
            maxHeap.push(num);
        } else if (maxHeap.size() > minHeap.size()) {
            if (maxHeap.top() > num) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(num);
            } else {
                minHeap.push(num);
            }
        } else {
            if (minHeap.top() < num) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(num);
            } else {
                maxHeap.push(num);
            }
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if (maxHeap.size() == 0)
            return 0.0;
        else if (minHeap.size() == maxHeap.size())
            return (minHeap.top() + maxHeap.top()) / 2.0;
        else
            return maxHeap.top();
    }
private:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int> > minHeap;
};

int main() {
    MedianFinder mf;
    mf.addNum(1);
    mf.addNum(5);
    mf.addNum(3);
    mf.addNum(2);
    cout << mf.findMedian() << endl;
    return 0;
}
