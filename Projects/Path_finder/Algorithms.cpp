#include "Algorithms.h"
#include <queue>
#include <unordered_set>
#include <iostream>

void BFS(Graph& g, const std::string& startNode) {
    std::queue<std::string> q;
    std::unordered_set<std::string> visited;

    q.push(startNode);
    visited.insert(startNode);

    std::cout << "Thu tu duyet BFS: ";
    
    while (!q.empty()) {
        std::string current = q.front();
        q.pop();
        std::cout << current << " -> "; 

        // Quét các lối đi từ tòa nhà hiện tại
        for (const auto& edge : g.adjList[current]) {
            // Lấy tên tòa nhà đích ra để kiểm tra
            std::string neighbor = edge.destination;
            
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                q.push(neighbor);
            }
        }
    }
    std::cout << "HET\n";
}