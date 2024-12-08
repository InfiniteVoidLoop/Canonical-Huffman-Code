CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wno-char-subscripts -Wno-sign-compare -Wno-unused-variable
SRCS = src/main.cpp src/utils.cpp src/codec.cpp src/globalVar.cpp
TARGET = main

$(TARGET):
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

.PHONY: clean run

clean:
	del /Q $(TARGET).exe 2>NUL

# Ignore all targets
.PRECIOUS: %
%:
	@:

# Run with direct arguments
run: $(TARGET)
	./$(TARGET) $(wordlist 2,3,$(MAKECMDGOALS))
