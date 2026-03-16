#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "Graph.h"
#include <string> // Phải thêm thư viện string

// Dùng const std::string& để truyền tên cho tối ưu
void BFS(Graph& g, const std::string& startNode);

#endif