#include "MapData.h"

void loadHUSTMap(Graph& g) {
    // Khu vực cổng chính và Hiệu bộ
    g.addEdge("Cong_Parabol", "C1", 100);
    g.addEdge("C1", "C2", 50);
    g.addEdge("C1", "C3", 60);
    
    // Khu vực giảng đường C
    g.addEdge("C2", "C9", 80);
    g.addEdge("C3", "D3", 120);
    g.addEdge("C9", "Nga_5", 60);
    
    // Khu vực D và Toà TC
    g.addEdge("D3", "D4", 50);
    g.addEdge("D4", "TC", 90);
    
    // Khu vực trung tâm: Thư viện và Sân vận động
    g.addEdge("Nga_5", "Thu_Vien_TQB", 100);
    g.addEdge("TC", "Thu_Vien_TQB", 120);
    g.addEdge("Thu_Vien_TQB", "San_Van_Dong", 200);
    g.addEdge("TC", "San_Van_Dong", 180);
}