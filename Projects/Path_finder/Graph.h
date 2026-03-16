#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

// Tạo một cấu trúc Cạnh để lưu 2 thông tin: Đi đến đâu? và Bao xa?
struct Edge {
    std::string destination;
    int weight;
};

class Graph {
public:
    // Danh sách kề phiên bản Pro: Tên Tòa nhà -> [Danh sách các lối đi]
    std::unordered_map<std::string, std::vector<Edge>> adjList;

    // Hàm thêm cạnh giờ cần cõng thêm tham số weight
    void addEdge(const std::string& u, const std::string& v, int weight);
    void printGraph();
};

#endif