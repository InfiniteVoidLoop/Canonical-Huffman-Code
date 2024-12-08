SRCS = src/main.cpp src/utils.cpp src/codec.cpp src/globalVar.cpp
TARGET = huffman

all: $(TARGET)

$(TARGET):
	g++ -std=c++11 -w $(SRCS) -o $(TARGET)

.PHONY: clean run

clean:
	-rm -f $(TARGET) $(TARGET).exe 2>/dev/null || del $(TARGET).exe 2>nul

run: $(TARGET)
	./$(TARGET) $(word 2,$(MAKECMDGOALS)) $(word 3,$(MAKECMDGOALS))

%:
	@:
