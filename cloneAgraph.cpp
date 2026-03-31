#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
// Node definition
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node(int _val) {
        val = _val;
    }
};
class Solution {
public:
    unordered_map<Node*, Node*> mp;

    Node* dfs(Node* node) {
        if (!node) return NULL;

        // If already cloned
        if (mp.find(node) != mp.end())
            return mp[node];

        // Create clone
        Node* clone = new Node(node->val);
        mp[node] = clone;

        // Clone neighbors
        for (Node* neigh : node->neighbors) {
            clone->neighbors.push_back(dfs(neigh));
        }

        return clone;
    }

    Node* cloneGraph(Node* node) {
        return dfs(node);
    }
};
// Helper function to print graph (DFS)
void printGraph(Node* node, unordered_map<Node*, bool> &visited) {
    if (!node || visited[node]) return;

    visited[node] = true;
    cout << "Node " << node->val << " -> ";

    for (Node* neigh : node->neighbors) {
        cout << neigh->val << " ";
    }
    cout << endl;

    for (Node* neigh : node->neighbors) {
        printGraph(neigh, visited);
    }
}
int main() {
    // Create graph manually
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    // Connect nodes (undirected graph)
    node1->neighbors = {node2, node4};
    node2->neighbors = {node1, node3};
    node3->neighbors = {node2, node4};
    node4->neighbors = {node1, node3};

    cout << "Original Graph:\n";
    unordered_map<Node*, bool> visited1;
    printGraph(node1, visited1);
    // Clone graph
    Solution obj;
    Node* clonedGraph = obj.cloneGraph(node1);

    cout << "\nCloned Graph:\n";
    unordered_map<Node*, bool> visited2;
    printGraph(clonedGraph, visited2);

    return 0;
}