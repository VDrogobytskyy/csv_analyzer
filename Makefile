TARGET = main

CXX = g++
CXXFLAGS = -Wall -std=c++17

DATAFILE = YOUR_FILE_NAME.csv

all: $(TARGET)

$(TARGET): main.cpp Analyzer.cpp
	$(CXX) $(CXXFLAGS) main.cpp Analyzer.cpp -o $(TARGET)

run: $(TARGET)
	./$(TARGET) $(DATAFILE)

clean:
	rm -f $(TARGET)
