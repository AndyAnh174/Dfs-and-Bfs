#include <iostream>
#include "graph.h"
using namespace std;

int main()
{
    Node* node1 = new Node('1');
    Node* node2 = new Node('2');
    Node* node3 = new Node('3');
    Node* node4 = new Node('4');
    Node* node5 = new Node('5');
    Node* node6 = new Node('6');
    Node* node7 = new Node('7');
    Node* node8 = new Node('8');
    Node* node9 = new Node('9');

    node1->connect(node2);
    node1->connect(node3);

    node2->connect(node3);
    node2->connect(node9);

    node3->connect(node4);
    node3->connect(node5);

    node4->connect(node5);
    node4->connect(node9);

    node5->connect(node6);
    node5->connect(node7);

    node7->connect(node8);

    Graph* graph = new Graph();
    Node* nodes[] = {node1, node2, node3, node4, node5, node6, node7, node8, node9};
    graph->addNodes(9, nodes);
    graph->print();

    graph->dfs(node1);
    graph->bfs(node1);
}