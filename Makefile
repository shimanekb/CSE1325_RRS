vpath %.hpp src:src/part:src/robot:test:test/part:test/robot
vpath %.cpp src:src/part:src/robot:test:test/part:test/robot
vpath %.o objs 

OBJ_DIR := objs
INC = -Isrc/part -Itest -Isrc/robot -Isrc
OBJS := part_controller.o part.o part_view.o rss_io.o battery.o arm.o locomotor.o torso.o head.o part_repo.o robot.o robot_repo.o robot_controller.o robot_view.o
TESTOBJS := part.o battery.o battery_test.o torso.o torso_test.o head.o head_test.o part_repo_test.o part_repo.o robot.o robot_test.o robot_repo.o robot_repo_test.o
CXXFLAGS =-std=c++14 -w

all: $(OBJ_DIR) executable
debug: CXXFLAGS += -g
rebuild: clean $(OBJ_DIR) executable

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

executable: main.cpp $(OBJS)
	$(CXX) $(CXXFLAGS) $(INC) $^
$(OBJ_DIR)/part_controller.o: part_controller.cpp battery.hpp part_view.hpp rss_io.hpp arm.hpp locomotor.hpp torso.hpp head.hpp part_repo.hpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@ 
$(OBJ_DIR)/part.o: part.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(OBJ_DIR)/part_view.o: part_view.cpp part.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ 
$(OBJ_DIR)/rss_io.o: rss_io.cpp part.hpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@ 
$(OBJ_DIR)/battery.o: battery.cpp part.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ 
$(OBJ_DIR)/arm.o: arm.cpp part.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ 
$(OBJ_DIR)/locomotor.o: locomotor.cpp part.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ 
$(OBJ_DIR)/torso.o: torso.cpp part.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ 
$(OBJ_DIR)/head.o: head.cpp part.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ 
$(OBJ_DIR)/part_repo.o: part_repo.cpp part.hpp rss_error.hpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@ 
$(OBJ_DIR)/robot.o: robot.cpp part.hpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@ 
$(OBJ_DIR)/robot_repo.o: robot_repo.cpp robot.hpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@ 
$(OBJ_DIR)/robot_controller.o: robot_controller.cpp robot_view.hpp robot_repo.hpp rss_io.hpp rss_error.hpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@ 
$(OBJ_DIR)/robot_view.o: robot_view.cpp robot.hpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@ 

test: main_test.cpp $(TESTOBJS)
	$(CXX) $(CXXFLAGS) $^ 
$(OBJ_DIR)/battery_test.o: battery_test.cpp catch.hpp part.hpp battery.hpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@ 
$(OBJ_DIR)/torso_test.o: torso_test.cpp catch.hpp part.hpp torso.hpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@ 
$(OBJ_DIR)/head_test.o: head_test.cpp catch.hpp part.hpp head.hpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@ 
$(OBJ_DIR)/part_repo_test.o: part_repo_test.cpp part_repo.hpp battery.hpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@ 
$(OBJ_DIR)/robot_test.o: robot_test.cpp catch.hpp robot.hpp battery.hpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@ 
$(OBJ_DIR)/robot_repo_test.o: robot_repo_test.cpp robot.hpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@ 
clean:
	rm -f $(OBJ_DIR)/*.o a.out 
