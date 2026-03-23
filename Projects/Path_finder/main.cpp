#include "Graph.h"
#include "Algorithms.h"
#include "MapData.h"
#include <iostream>
#include <chrono> // Thư viện đo thời gian

int main() {
    Graph hustMap;
    loadHUSTMap(hustMap);
    
    std::string start = "Cong_Parabol";
    std::string end = "Thu_Vien_TQB";

    std::cout << "--- SO SANH HIEU NANG TIM DUONG ---\n";
    std::cout << "Tu: " << start << " ---> Den: " << end << "\n\n";

    // 1. Chạy và đo thời gian Dijkstra
    auto startDijkstra = std::chrono::high_resolution_clock::now();
    Dijkstra(hustMap, start, end);
    auto endDijkstra = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> timeDijkstra = endDijkstra - startDijkstra;
    std::cout << "=> Thoi gian chay Dijkstra: " << timeDijkstra.count() << " microseconds\n\n";

    // 2. Chạy và đo thời gian A*
    auto startAStar = std::chrono::high_resolution_clock::now();
    AStar(hustMap, start, end);
    auto endAStar = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> timeAStar = endAStar - startAStar;
    std::cout << "=> Thoi gian chay A*: " << timeAStar.count() << " microseconds\n";

    return 0;
}