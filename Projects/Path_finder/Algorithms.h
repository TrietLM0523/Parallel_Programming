#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "Graph.h"
#include <string>

void Dijkstra(Graph& g, const std::string& startNode, const std::string& endNode);
void AStar(Graph& g, const std::string& startNode, const std::string& endNode);
void flushCPUCache();
int getHeuristic(const std::string& nodeA, const std::string& nodeB);
#endif