#include "Graph.h"
#include "Algorithms.h"
#include "MapData.h"
#include <iostream>
#include <chrono>
#include <vector>

int main() {
    Graph hustMap;
    loadHUSTMap(hustMap);
    
    std::string start = "Cong_Parabol";
    std::string end = "Thu_Vien_TQB";

    std::cout << "--- DO LUONG KHACH QUAN VOI CO CHE XOA CACHE ---\n\n";

    // 1. Chạy Dijkstra (Cold Start)
    auto startDijkstra = std::chrono::high_resolution_clock::now();
    Dijkstra(hustMap, start, end);
    auto endDijkstra = std::chrono::high_resolution_clock::now();
    
    std::chrono::duration<double, std::micro> timeDijkstra = endDijkstra - startDijkstra;
    std::cout << "=> [Dijkstra] Thoi gian chay: " << timeDijkstra.count() << " micro-giay\n\n";

    // ==========================================
    std::cout << "[Hethong] Dang don dep RAM va Cache...\n\n";
    flushCPUCache(); 
    // ==========================================

    // 2. Chạy A* (Lại là Cold Start, công bằng tuyệt đối)
    auto startAStar = std::chrono::high_resolution_clock::now();
    AStar(hustMap, start, end);
    auto endAStar = std::chrono::high_resolution_clock::now();
    
    std::chrono::duration<double, std::micro> timeAStar = endAStar - startAStar;
    std::cout << "=> [A*]       Thoi gian chay: " << timeAStar.count() << " micro-giay\n";

    return 0;
}