#build executive named main from main.cc

#compiler: g++
CXX = g++

#remove command
RM = rm -f

#compile flags:
# -g debugging
# -Wall most warnings
# -MMD build dependency files (for headers)
CXXFLAGS = --std=c++11 -g -Wall -MMD

#source files, object files, and dependencies
SRC := $(wildcard *.cc)
OBJ := $(SRC:.cc=.o)
DEP := $(OBJ:.o=.d)	

TXT := $(wildcard *.txt)

#target executive name
TARGET = runProg

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^
	
-include $(DEP)

.PHONY: clean
clean:
	$(RM) $(OBJ) $(DEP) $(TARGET) $(TXT)
