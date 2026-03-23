CXX = g++
CXXFLAGS = -Wall -std=c++11

# Tên file chạy đầu ra
TARGET = main

all: $(TARGET)

# Biên dịch tất cả 4 file cpp
$(TARGET): main.cpp Graph.cpp Algorithms.cpp MapData.cpp
	$(CXX) $(CXXFLAGS) main.cpp Graph.cpp Algorithms.cpp MapData.cpp -o $(TARGET)

# Dọn rác (Dùng lệnh del cho Windows)
clean:
	del *.exe