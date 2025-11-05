TARGET = main

CXX = g++
CXXFLAGS = -Wall -std=c++17

DATAFILE = Mobile_phone.csv

all: $(TARGET)

$(TARGET): main.cpp Analyzer.cpp
	$(CXX) $(CXXFLAGS) main.cpp Analyzer.cpp -o $(TARGET)

run: $(TARGET)
	./$(TARGET) $(DATAFILE)

clean:
	rm -f $(TARGET)
