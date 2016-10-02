vpath %.h src test
vpath %.cpp src test
vpath %.o 
vpath %.hpp test

TARGETDIR := bin
OBJS := part_controller.o part.o
CXXFLAGS =-std=c++14 -w

all: executable
debug: CXXFLAGS += -g
rebuild: clean executable

executable: main.cpp $(OBJS)
	$(CXX) $(CXXFLAGS) $^
part_controller.o: part_controller.cpp part.h
	$(CXX) $(CXXFLAGS) -c $< -o $@ 
part.o: part.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ 

test: main_test.cpp
	$(CXX) $(CXXFLAGS) $^ 
clean:
	rm -f *.o src/*.o a.out test/*.o
