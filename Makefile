CC				:= g++
CFLAGS		:= -g -Wall -fPIC -std=c++11 -pthread

SRC				:= src
INC				:= include
BUILD			:= build
BIN				:= bin
TARGET		:= bin/novo

LINK_OBJS := $(BUILD)/main.o $(BUILD)/Schema.o $(BUILD)/Database.o $(BUILD)/Table.o $(BUILD)/Column.o

$(TARGET): $(BUILD)/main.o
	mkdir -p $(BIN)
	$(CC) $(CFLAGS) -o $(TARGET) $(LINK_OBJS)

$(BUILD)/main.o: $(INC)/main.h $(SRC)/main.cpp $(BUILD)/Schema.o
	mkdir -p $(BUILD)
	$(CC) $(CFLAGS) -c -o $(BUILD)/main.o -I$(INC) $(SRC)/main.cpp

$(BUILD)/Schema.o: $(INC)/Schema.h $(SRC)/Schema.cpp $(BUILD)/Database.o
	mkdir -p $(BUILD)
	$(CC) $(CFLAGS) -c -o $(BUILD)/Schema.o -I$(INC) $(SRC)/Schema.cpp

$(BUILD)/Database.o: $(INC)/Database.h $(SRC)/Database.cpp $(BUILD)/Table.o
	mkdir -p $(BUILD)
	$(CC) $(CFLAGS) -c -o $(BUILD)/Database.o -I$(INC) $(SRC)/Database.cpp

$(BUILD)/Table.o: $(INC)/Table.h $(SRC)/Table.cpp $(BUILD)/Column.o
	mkdir -p $(BUILD)
	$(CC) $(CFLAGS) -c -o $(BUILD)/Table.o -I$(INC) $(SRC)/Table.cpp

$(BUILD)/Column.o: $(INC)/Column.h $(SRC)/Column.cpp
	mkdir -p $(BUILD)
	$(CC) $(CFLAGS) -c -o $(BUILD)/Column.o -I$(INC) $(SRC)/Column.cpp

# $(BUILD)/DB.o: $(INC)/DB.h $(SRC)/DB.cpp
# 	mkdir -p $(BUILD)
# 	$(CC) $(CFLAGS) -c -o $(BUILD)/DB.o -I$(INC) $(SRC)/DB.cpp

clean:
	rm -rf $(BUILD)/*
	rm -f $(TARGET)
