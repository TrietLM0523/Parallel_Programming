#include "Graph.h"

void Graph::addEdge(int u, int v) {
    adjList[u].push_back(v);
    adjList[v].push_back(u); // Đồ thị vô hướng (đường 2 chiều)
}

// Hàm này cực quan trọng để fen test xem đồ thị đã nối đúng chưa
void Graph::printGraph() {
    for (const auto& pair : adjList) {
        std::cout << "Dinh " << pair.first << " noi voi: ";
        for (int neighbor : pair.second) {
            std::cout << neighbor << " ";
        }
        std::cout << "\n";
    }
}