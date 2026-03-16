#include "Algorithms.h"
#include <queue>
#include <unordered_set> // Dùng để đánh dấu các đỉnh đã thăm
#include <iostream>

void BFS(Graph& g, int startNode) {
    std::queue<int> q;
    std::unordered_set<int> visited;

    // Bắt đầu từ đỉnh gốc
    q.push(startNode);
    visited.insert(startNode);

    std::cout << "Thu tu duyet BFS: ";
    
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        std::cout << current << " "; // In ra đỉnh đang đứng

        // Quét tất cả hàng xóm của đỉnh hiện tại trong Danh sách kề
        for (int neighbor : g.adjList[current]) {
            // Nếu hàng xóm chưa được thăm
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor); // Đánh dấu đã thăm
                q.push(neighbor);         // Cho vào hàng đợi chờ xử lý
            }
        }
    }
    std::cout << "\n";
}