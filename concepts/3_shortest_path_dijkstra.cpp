class Node {
public:
    vector<Node> neighbors;
    vector<int> weights;
    int min;
    Node previous;
};

class PriorityQueue {
public:
    void add(Node);
    Node top();        // get the top node with minimum priority
    void remove(Node); // must support the operation of removing random node from the queue
};

class Dijkstra {   
public:
    void dijkstra(Node start, vector<Node> &nodes) {
        start.min = 0;
        PriorityQueue q = new PriorityQueue();
        for(int i = 0; i < nodes.size()) {
            q.add(nodes[i]);
        }

        while (!q.empty()) {
            Node u = q.top();
            q.pop();
            for (int i = 0; i < u.neighbors.size(); i++) { // visit each neighbor of node u
                Node v = u.neighbors[i];
                int weight = u.weights[i]; // weight of edge between node u and u.neighbors[i]
                int new_distance = u.min + weight;
                if (new_distance < v.min) {
                    q.remove(v);           // remove to re-insert it in the queue with the new cost.
                    v.min = new_distance;
                    q.add(v);
                    v.previous = u;
                }
            }
        }
    }
};
