/* - queue (FIFO)
 *
 *     operations:
 *       push(4); // push to the back of the queue
 *       pop();   // pop the front element of the queue
 *
 *                back            front
 *       push ->    3       2       1   -> pop
 *
 *     while-loop traversal (FIFO):
 *       queue<int> q;
 *       while (q.empty()) {
 *           cout << q.front() << endl;
 *           q.pop();
 *       }
 *
 * - stack (FILO)
 *
 *     operations:
 *       push(4); // push to the top (back) of the stack
 *       pop();   // pop the top (back) element of the stack
 *
 *                   top/back      bottom/front
 *       push/pop <->   3       2       1
 *
 *     while-loop traversal (FILO):
 *       stack<int> q;
 *       while (q.empty()) {
 *           cout << q.top() << endl;
 *           q.pop();
 *       }
 *
 * - vector (FILO): can simulate a stack and provide traversals from both sides
 *
 *     operations:
 *       push_back(4); // push to the back of the vector
 *       pop_back();   // pop the back element of the vector
 *
 *                               back            front
 *       push_back/pop_back <->    3       2       1
 *
 *     while-loop traversal from both sides:
 *       vector<int> q;
 *       for (int i = 0; i < q.size(); i++) {
 *           cout << q[i] << " ";
 *       }
 *       for (int i = q.size() - 1; i >= 0; i--) {
 *           cout << q[i] << " ";
 *       }
 */
