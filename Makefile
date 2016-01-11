CC        := clang++
CFLAGS    := -g -Wall -fPIC -std=c++11

SRC       := src
INC       := include
BUILD     := build
BIN       := bin

TARGET	  := bin/novo
HEADERS   := $(INC)/*.h $(INC)/DBObjects/*.h
CPP       := $(SRC)/*.cpp $(SRC)/DBObjects/*.cpp

$(TARGET): $(HEADERS) $(CPP)
	mkdir -p bin
	$(CC) $(CFLAGS) -o $(TARGET) -I$(INC) $(CPP)

clean:
	rm -rf $(BUILD)/*
	rm -f $(TARGET)
