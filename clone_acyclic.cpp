#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node(int _val) {
        val = _val;
    }
};
unordered_map<Node*, Node*> mp;
Node* cloneGraph(Node* node) {
    if (!node) return NULL;
    if (mp.find(node) != mp.end())
        return mp[node];
    Node* clone = new Node(node->val);
    mp[node] = clone;

    for (Node* neighbor : node->neighbors) {
        clone->neighbors.push_back(cloneGraph(neighbor));
    }
    return clone;
}
int main() {
    // Create a simple DAG
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    n1->neighbors.push_back(n2);
    n1->neighbors.push_back(n3);
    n2->neighbors.push_back(n3);
    Node* cloned = cloneGraph(n1);
    cout << "Original Node: " << n1->val << endl;
    cout << "Cloned Node: " << cloned->val << endl;
    return 0;
}