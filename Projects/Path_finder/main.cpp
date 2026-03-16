#include "Graph.h"
#include "Algorithms.h"
#include <iostream>

int main() {
    Graph g;
    
    // Nối một đồ thị test nhỏ (0 nối với 1, 2; 1 nối 3, 4...)
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);

    std::cout << "--- HINH HAI DANH SACH KE ---\n";
    g.printGraph();

    std::cout << "\n--- CHAY THUAT TOAN BFS ---\n";
    BFS(g, 0); // Bắt đầu loang từ đỉnh 0

    return 0;
}