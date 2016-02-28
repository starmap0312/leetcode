/*
 *
 */
#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    Node() { index = 0, value = 0; next = NULL; }
    Node *next;
    int index, value;
};

class Stack {
public:
    Stack() { head = NULL; }
    void push(int index, int value);
    void pop();
    int peak();
    Node* getHead() { return head; }
private:
    Node *head;
};

class Solution {
public:
    Solution() { area = 0; }
    int maxArea(vector<int> &height);
private:
    void createEndStack(vector<int> &height);
    int evaluateArea(vector<int> &height, int beg_index, int end_index);
    Stack front;
    Stack end;
    int area;
};

int Solution::evaluateArea(vector<int> &height, int beg, int end) {
    return min(height[beg], height[end]) * (end - beg);
}

void Solution::createEndStack(vector<int> &height) {
    for(int i = height.size() - 1; i > 0 ; i--) {
        int index = end.peak();
        if (index == -1 || height[i] > height[index])
            end.push(i, height[i]);
    }
}

int Solution::maxArea(vector<int> &height) {
    createEndStack(height);
    for(int i = 0; i < height.size(); i++) {
        if (i == end.peak()) {
            for(Node *itr = front.getHead(); itr != NULL; itr = itr -> next) {
                int new_area = evaluateArea(height, itr -> index, i);
                if (new_area > area)
                    area = new_area;
            }
            end.pop();
        }
        if (front.peak() == -1 || height[i] > height[front.peak()])
            front.push(i, height[i]);
    }
    return area;
}

int Stack::peak() {
    if (head == NULL) return -1;
    else return head -> index;
}

void Stack::pop() {
    Node *node = head;
    head = head -> next;
    delete node;
}

void Stack::push(int index, int value) {
    Node *new_node = new Node;
    new_node -> next = head;
    new_node -> index = index;
    new_node -> value = value;
    head = new_node;
}

int main() {
    int a[7] = { 2, 3, 10, 5, 7, 8, 9 };
    vector<int> height(a, a + sizeof(a) / sizeof(a[0]));
    Solution solution;
    cout << solution.maxArea(height) << endl;
    return 0;
}
