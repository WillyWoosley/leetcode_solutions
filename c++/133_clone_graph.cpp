/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        // Filter case for empty graphs
        if (node == nullptr) {
            return node;
        }

        unordered_map<Node*, Node*> created; // Mapping of old to new Node
        queue<Node*> visit;

        // Create and enqueue source node
        Node* new_node = new Node(node->val);
        created[node] = new_node;
        visit.push(node);

        // BFS cloning of all nodes
        while (!visit.empty()) {
            Node* cur = visit.front();
            visit.pop();
            Node* copy = created[cur];

            for (Node* neighbor : cur->neighbors) {
                if (created.find(neighbor) != created.end()) {
                    copy->neighbors.push_back(created[neighbor]);
                } else {
                    Node* new_node = new Node(neighbor->val);
                    created[neighbor] = new_node;
                    visit.push(neighbor);
                    copy->neighbors.push_back(new_node);
                }
            }
        }

        return new_node;
    }
};
