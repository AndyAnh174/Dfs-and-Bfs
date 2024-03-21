#include <iostream>
#include <queue>
#include <stack>
#include <algorithm> // Include algorithm for sorting
using namespace std;

struct Node {
    Node* nodes[100] = {};
    int conns = 0;
    char label;

    Node(char label) {
        this->label = label;
    }

    void connect(Node* node) {
        if (isConnected(node)) return;
        nodes[conns] = node;
        conns++;
        node->connect(this);
    }

    bool isConnected(Node* node) {
        for (int i = 0; i < conns; i++) {
            if (node == nodes[i]) return true;
        }
        return false;
    }
};

struct Graph {
    Node* nodes[100] = {};
    int gSize = 0;

    void addNodes(int n, Node* nodes[]) {
        for (int i = 0; i < n; i++) {
            this->nodes[gSize + i] = nodes[i];
        }
        gSize += n;
    }

    void print() {
        for (int i = 0; i < gSize; i++) {
            cout << this->nodes[i]->label << ", ";
        }
        cout << endl;
    }

void dfsUtil(Node* node, bool visited[], bool inStack[], stack<Node*>& s) {
    visited[node->label - '1'] = true;
    inStack[node->label - '1'] = true;

    cout << node->label << " ";

    for (int i = 0; i < node->conns; i++) {
        Node* neighbor = node->nodes[i];
        if (!visited[neighbor->label - '1']) {
            dfsUtil(neighbor, visited, inStack, s);
        } else if (inStack[neighbor->label - '1']) {
            // Neighbor is already in the stack, indicating a cycle
            // Avoid further traversal to prevent cycle
            continue;
        }
    }

    inStack[node->label - '1'] = false;
    s.push(node); // Push node to stack after traversal
}

void dfs(Node* startNode) {
    bool visited[gSize] = {false};
    bool inStack[gSize] = {false};
    stack<Node*> s;

    dfsUtil(startNode, visited, inStack, s);

    cout << endl;
}

    void bfs(Node* startNode) {
        bool visited[gSize];
        for (int i = 0; i < gSize; i++) {
            visited[i] = false;
        }
        queue<Node*> q;
        q.push(startNode);
        visited[startNode->label - '1'] = true;

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            cout << current->label << " ";

            // Sort neighbors based on label in ascending order
            sort(current->nodes, current->nodes + current->conns, [](Node* a, Node* b) {
                return a->label < b->label;
            });

            for (int i = 0; i < current->conns; i++) {
                Node* neighbor = current->nodes[i];
                if (!visited[neighbor->label - '1']) {
                    visited[neighbor->label - '1'] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }
};
