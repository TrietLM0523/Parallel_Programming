#include "Graph.h"
#include "Algorithms.h"
#include <iostream>

int main() {
    Graph g;
    
    // Nối các đỉnh với tên thực tế và trọng số (khoảng cách)
    g.addEdge("C1", "C2", 50);
    g.addEdge("C1", "C3", 60);
    g.addEdge("C2", "C9", 40);
    g.addEdge("C3", "C4", 30);
    g.addEdge("C9", "Nga_5", 100);
    g.addEdge("Nga_5", "Thu_Vien", 150);

    std::cout << "--- HINH HAI MAP BACH KHOA ---\n";
    g.printGraph();

    std::cout << "\n--- CHAY THUAT TOAN BFS (Chua xet trong so) ---\n";
    BFS(g, "C1"); // Bắt đầu loang từ nhà C1

    return 0;
}