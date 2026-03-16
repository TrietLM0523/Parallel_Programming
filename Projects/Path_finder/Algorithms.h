#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "Graph.h"

// Truyền đồ thị g theo tham chiếu (&) để không bị copy tốn RAM
void BFS(Graph& g, int startNode);

#endif