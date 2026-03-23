#include "Algorithms.h"
#include <queue>
#include <unordered_map>
#include <vector>
#include <limits>
#include <algorithm>
#include <iostream>
#include <cmath>

using NodePair = std::pair<int, std::string>;

// --- THUẬT TOÁN 1: DIJKSTRA ---
void Dijkstra(Graph& g, const std::string& startNode, const std::string& endNode) {
    std::unordered_map<std::string, int> distances;
    std::unordered_map<std::string, std::string> previous;
    std::priority_queue<NodePair, std::vector<NodePair>, std::greater<NodePair>> pq;

    for (const auto& pair : g.adjList) {
        distances[pair.first] = std::numeric_limits<int>::max();
    }

    distances[startNode] = 0;
    pq.push({0, startNode});

    while (!pq.empty()) {
        int currentDist = pq.top().first;
        std::string current = pq.top().second;
        pq.pop();

        if (current == endNode) break;
        if (currentDist > distances[current]) continue;

        for (const auto& edge : g.adjList[current]) {
            std::string neighbor = edge.destination;
            int weight = edge.weight;
            int newDist = currentDist + weight;

            if (newDist < distances[neighbor]) {
                distances[neighbor] = newDist;
                previous[neighbor] = current;
                pq.push({newDist, neighbor});
            }
        }
    }

    // In đường đi của Dijkstra
    if (distances[endNode] == std::numeric_limits<int>::max()) return;
    std::vector<std::string> path;
    for (std::string at = endNode; at != ""; at = previous[at]) path.push_back(at);
    std::reverse(path.begin(), path.end());
    
    std::cout << "[Dijkstra] Lo trinh: ";
    for (size_t i = 0; i < path.size(); ++i) std::cout << path[i] << (i == path.size() - 1 ? "" : " -> ");
    std::cout << "\n[Dijkstra] Tong khoang cach: " << distances[endNode] << "m\n";
}

// --- HÀM HEURISTIC CHO A* ---
// Tạm thời trả về 0 (khiến A* hoạt động giống hệt Dijkstra).
// Sau này có tọa độ X, Y, fen thay bằng: sqrt(pow(x1-x2, 2) + pow(y1-y2, 2))
int getHeuristic(const std::string& current, const std::string& goal) {
    return 0; 
}

// --- THUẬT TOÁN 2: A-STAR (A*) ---
void AStar(Graph& g, const std::string& startNode, const std::string& endNode) {
    std::unordered_map<std::string, int> gScore; // Quãng đường thực tế đã đi
    std::unordered_map<std::string, std::string> previous;
    // Hàng đợi ưu tiên xếp theo fScore = gScore + Heuristic
    std::priority_queue<NodePair, std::vector<NodePair>, std::greater<NodePair>> pq;

    for (const auto& pair : g.adjList) {
        gScore[pair.first] = std::numeric_limits<int>::max();
    }

    gScore[startNode] = 0;
    // fScore ban đầu = khoảng cách dự đoán từ điểm xuất phát đến đích
    pq.push({getHeuristic(startNode, endNode), startNode});

    while (!pq.empty()) {
        std::string current = pq.top().second;
        pq.pop();

        if (current == endNode) break;

        for (const auto& edge : g.adjList[current]) {
            std::string neighbor = edge.destination;
            int tentative_gScore = gScore[current] + edge.weight;

            if (tentative_gScore < gScore[neighbor]) {
                previous[neighbor] = current;
                gScore[neighbor] = tentative_gScore;
                
                // Công thức cốt lõi của A*: f(n) = g(n) + h(n)
                int fScore = tentative_gScore + getHeuristic(neighbor, endNode);
                pq.push({fScore, neighbor});
            }
        }
    }

    // In đường đi của A*
    if (gScore[endNode] == std::numeric_limits<int>::max()) return;
    std::vector<std::string> path;
    for (std::string at = endNode; at != ""; at = previous[at]) path.push_back(at);
    std::reverse(path.begin(), path.end());
    
    std::cout << "[A*] Lo trinh: ";
    for (size_t i = 0; i < path.size(); ++i) std::cout << path[i] << (i == path.size() - 1 ? "" : " -> ");
    std::cout << "\n[A*] Tong khoang cach: " << gScore[endNode] << "m\n";
}