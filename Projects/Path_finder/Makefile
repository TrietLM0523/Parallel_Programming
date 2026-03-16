CXX = g++
CXXFLAGS = -Wall -std=c++11

# Tên file chạy đầu ra
TARGET = main

all: $(TARGET)

# Biên dịch tất cả các file cpp
$(TARGET): main.cpp Graph.cpp Algorithms.cpp
	$(CXX) $(CXXFLAGS) main.cpp Graph.cpp Algorithms.cpp -o $(TARGET)

# Dọn rác (Dùng lệnh del cho Windows)
clean:
	del *.exe