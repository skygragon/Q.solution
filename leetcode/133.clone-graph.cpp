/*
 * [133] Clone Graph
 *
 * https://leetcode.com/problems/clone-graph
 *
 * Medium (25.05%)
 * Total Accepted:    99914
 * Total Submissions: 398903
 * Testcase Example:  '{}'
 *
 * 
 * Clone an undirected graph. Each node in the graph contains a label and a
 * list of its neighbors.
 * 
 * 
 * 
 * 
 * OJ's undirected graph serialization:
 * 
 * 
 * Nodes are labeled uniquely.
 * 
 * 
 * We use # as a separator for each node, and , as a separator for node label
 * and each neighbor of the node.
 * 
 * 
 * 
 * 
 * As an example, consider the serialized graph {0,1,2#1,2#2,2}.
 * 
 * 
 * 
 * The graph has a total of three nodes, and therefore contains three parts as
 * separated by #.
 * 
 * First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
 * Second node is labeled as 1. Connect node 1 to node 2.
 * Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming
 * a self-cycle.
 * 
 * 
 * 
 * 
 * Visually, the graph looks like the following:
 * 
 * ⁠      1
 * ⁠     / \
 * ⁠    /   \
 * ⁠   0 --- 2
 * ⁠        / \
 * ⁠        \_/
 * 
 * 
 * 
 * 
 */
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    using Node = UndirectedGraphNode;
    unordered_set<Node*> nodes;
    Node* root;

    void fixOld() {
        for (auto p : nodes) p->neighbors.pop_back();
    }

    void fixNew() {
        for (auto p : nodes) {
            Node* p1 = p->neighbors.back();
            for (auto & p2 : p1->neighbors)
                p2 = p2->neighbors.back();
        }
    }

    Node* clone() {
        for (auto p : nodes) {
            Node* p1 = new Node(p->label);
            p1->neighbors = p->neighbors;
            p->neighbors.push_back(p1);
        }
        return root->neighbors.back();;
    }

    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) return NULL;
        root = node;

        stack<Node*> s;
        s.push(node);
        while (!s.empty()) {
            Node* p = s.top(); s.pop();
            if (nodes.find(p) != nodes.end()) continue;
            nodes.insert(p);
            for (auto p1 : p->neighbors) s.push(p1);
        }

        Node* p = clone();

        fixNew();
        fixOld();

        return p;
    }
};
