vpath %.hpp src:src/part:src/robot:test:test/part:test/robot
vpath %.cpp src:src/part:src/robot:test:test/part:test/robot
vpath %.o src:src/part:src/robot:test:test/part:test/robot

TARGETDIR := bin
INC = -Isrc/part -Itest -Isrc/robot
OBJS := part_controller.o part.o part_view.o rss_io.o battery.o arm.o locomotor.o torso.o head.o part_repo.o robot.o robot_repo.o
TESTOBJS := part.o battery.o battery_test.o torso.o torso_test.o head.o head_test.o part_repo_test.o part_repo.o robot.o robot_test.o robot_repo.o robot_repo_test.o
CXXFLAGS =-std=c++14 -w

all: executable
debug: CXXFLAGS += -g
rebuild: clean executable

executable: main.cpp $(OBJS)
	$(CXX) $(CXXFLAGS) $(INC) $^
part_controller.o: part_controller.cpp battery.hpp part_view.hpp rss_io.hpp arm.hpp locomotor.hpp torso.hpp head.hpp part_repo.hpp
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
part_repo.o: part_repo.cpp part.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ 
robot.o: robot.cpp part.hpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@ 
robot_repo.o: robot_repo.cpp robot.hpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@ 

test: main_test.cpp catch.hpp $(TESTOBJS)
	$(CXX) $(CXXFLAGS) $^ 
battery_test.o: battery_test.cpp catch.hpp part.hpp battery.hpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@ 
torso_test.o: torso_test.cpp catch.hpp part.hpp torso.hpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@ 
head_test.o: head_test.cpp catch.hpp part.hpp head.hpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@ 
part_repo_test.o: part_repo_test.cpp part_repo.hpp battery.hpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@ 
robot_test.o: robot_test.cpp robot.hpp battery.hpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@ 
robot_repo_test.o: robot_repo_test.cpp robot.hpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@ 
clean:
	rm -f *.o src/*.o a.out test/*.o test/*.gch src/part/*.o 
