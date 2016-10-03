vpath %.cpp src test
vpath %.o 
vpath %.hpp src test

TARGETDIR := bin
OBJS := part_controller.o part.o part_view.o rss_io.o
CXXFLAGS =-std=c++14 -w

all: executable
debug: CXXFLAGS += -g
rebuild: clean executable

executable: main.cpp $(OBJS)
	$(CXX) $(CXXFLAGS) $^
part_controller.o: part_controller.cpp part.hpp part_view.hpp rss_io.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ 
part.o: part.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ 
part_view.o: part_view.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ 
rss_io.o: rss_io.cpp part.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ 

test: main_test.cpp
	$(CXX) $(CXXFLAGS) $^ 
clean:
	rm -f *.o src/*.o a.out test/*.o
