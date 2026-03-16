#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <unordered_map>
#include <iostream>

class Graph {
public:
    // Danh sách kề: Đỉnh u -> [Danh sách các đỉnh kề v1, v2...]
    std::unordered_map<int, std::vector<int>> adjList;

    // Các hàm cơ bản
    void addEdge(int u, int v);
    void printGraph();
};

#endif