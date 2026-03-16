#include "Graph.h"

// Dùng const std::string& để truyền tên tòa nhà cho tối ưu RAM
void Graph::addEdge(const std::string& u, const std::string& v, int weight) {
    // Đồ thị vô hướng: Nối từ u sang v, và từ v sang u với cùng khoảng cách
    adjList[u].push_back({v, weight});
    adjList[v].push_back({u, weight}); 
}

void Graph::printGraph() {
    for (const auto& pair : adjList) {
        std::cout << "VTT " << pair.first << " co the di den:\n";
        
        // Quét từng lối đi (edge) của tòa nhà hiện tại
        for (const auto& edge : pair.second) {
            std::cout << "  -> " << edge.destination << " (khoang cach: " << edge.weight << "m)\n";
        }
    }
}