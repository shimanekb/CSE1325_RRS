vpath %.cpp src:test
vpath %.hpp src:test
vpath %.o src:test

TARGETDIR := bin
OBJS := part_controller.o part.o part_view.o rss_io.o battery.o arm.o locomotor.o torso.o head.o
CXXFLAGS =-std=c++14 -w

all: executable
debug: CXXFLAGS += -g
rebuild: clean executable

executable: main.cpp $(OBJS)
	$(CXX) $(CXXFLAGS) $^
part_controller.o: part_controller.cpp battery.hpp part.hpp part_view.hpp rss_io.hpp arm.hpp locomotor.hpp torso.hpp head.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ 
part.o: part.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ 
part_view.o: part_view.cpp part.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ 
rss_io.o: rss_io.cpp part.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ 
battery.o: battery.cpp part.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ 
arm.o: arm.cpp part.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ 
locomotor.o: locomotor.cpp part.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ 
torso.o: torso.cpp part.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ 
head.o: head.cpp part.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ 

test: main_test.cpp catch.hpp part.o battery.o battery_test.o torso.o torso_test.o head.o head_test.o
	$(CXX) $(CXXFLAGS) $^ 
battery_test.o: battery_test.cpp catch.hpp part.hpp battery.hpp
	$(CXX) $(CXXFLAGS) -Isrc -c $< -o $@ 
torso_test.o: torso_test.cpp catch.hpp part.hpp torso.hpp
	$(CXX) $(CXXFLAGS) -Isrc -c $< -o $@ 
head_test.o: head_test.cpp catch.hpp part.hpp head.hpp
	$(CXX) $(CXXFLAGS) -Isrc -c $< -o $@ 
clean:
	rm -f *.o src/*.o a.out test/*.o test/*.gch
