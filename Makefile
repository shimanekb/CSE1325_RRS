vpath %.hpp src:$(wildcard src/view/*):$(wildcard src/controller/*):$(wildcard src/model/*):test:test/part:test/robot
vpath %.cpp src:$(wildcard src/view/*):$(wildcard src/controller/*):$(wildcard src/model/*):lib:test:test/part:test/robot
vpath %.o objs 

LIB_DIR := lib
OBJ_DIR := objs
INC = -Itest -Isrc -L/usr/lib -lfltk -lXext -lX11 -lm

ROBOT_ORDER_OBJS := robot_order.o robot_order_controller.o robot_order_view.o robot_order_repo.o
ROBOT_OBJS := robot.o robot_repo.o robot_controller.o robot_view.o battery_validation_strategy.o robot_validation_strategy.o robot_validation_strategy_repo.o generic_validation_strategy.o  robot_creation_window.o
PART_OBJS := part_controller.o part.o part_view.o rrs_io.o battery.o arm.o locomotor.o torso.o head.o part_repo.o part_creation_window.o
RRS_OBJS := rrs_window.o rrs_manager.o rrs_main_window.o rrs_manager_view.o
OBJS := $(RRS_OBJS) $(ROBOT_OBJS) $(PART_OBJS) $(ROBOT_ORDER_OBJS) tinyxml2.o

ROBOT_ORDER_TEST_OBJS := robot_order_repo.o robot_order_repo_test.o
ROBOT_TEST_OBJS := robot.o robot_test.o robot_repo.o robot_repo_test.o battery_validation_strategy_test.o robot_validation_strategy_repo.o battery_validation_strategy.o robot_validation_strategy_repo_test.o generic_validation_strategy.o
TESTOBJS := $(ROBOT_TEST_OBJS) part.o battery.o battery_test.o torso.o torso_test.o head.o head_test.o part_repo_test.o part_repo.o 
CXXFLAGS =-std=c++11 -w

all: $(OBJ_DIR) executable
debug: CXXFLAGS += -g
rebuild: clean $(OBJ_DIR) executable

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

executable: main.cpp $(OBJS)
	$(CXX) $(CXXFLAGS) $(INC) $^
$(OBJ_DIR)/rrs_manager.o: rrs_manager.cpp part_controller.hpp robot_controller.hpp rrs_manager_view.hpp robot_order_controller.hpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@ 
$(OBJ_DIR)/rrs_manager_view.o: rrs_manager_view.cpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@ 
$(OBJ_DIR)/rrs_main_window.o: rrs_main_window.cpp part_creation_window.hpp rrs_window.hpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@ 
$(OBJ_DIR)/rrs_window.o: rrs_window.cpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@ 
$(OBJ_DIR)/part_controller.o: part_controller.cpp battery.hpp part_view.hpp rrs_io.hpp arm.hpp locomotor.hpp torso.hpp head.hpp part_repo.hpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@ 
$(OBJ_DIR)/part.o: part.cpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@ 
$(OBJ_DIR)/part_view.o: part_view.cpp part.hpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@ 
$(OBJ_DIR)/rrs_io.o: rrs_io.cpp part.hpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@ 
$(OBJ_DIR)/battery.o: battery.cpp part.hpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@ 
$(OBJ_DIR)/arm.o: arm.cpp part.hpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@ 
$(OBJ_DIR)/locomotor.o: locomotor.cpp part.hpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@ 
$(OBJ_DIR)/torso.o: torso.cpp part.hpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@ 
$(OBJ_DIR)/head.o: head.cpp part.hpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@ 
$(OBJ_DIR)/part_repo.o: part_repo.cpp part.hpp rrs_error.hpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@ 
$(OBJ_DIR)/part_creation_window.o: part_creation_window.cpp part_controller.hpp rrs_window.hpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@ 
$(OBJ_DIR)/robot.o: robot.cpp part.hpp robot_validation_strategy_repo.hpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@ 
$(OBJ_DIR)/robot_repo.o: robot_repo.cpp robot.hpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@ 
$(OBJ_DIR)/robot_controller.o: robot_controller.cpp robot_view.hpp robot_repo.hpp rrs_io.hpp rrs_error.hpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@ 
$(OBJ_DIR)/robot_view.o: robot_view.cpp robot.hpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@ 
$(OBJ_DIR)/robot_creation_window.o: robot_creation_window.cpp robot.hpp robot_controller.hpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@ 
$(OBJ_DIR)/battery_validation_strategy.o: battery_validation_strategy.cpp robot_validation_strategy.hpp rrs_error.hpp battery.hpp torso.hpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@ 
$(OBJ_DIR)/robot_validation_strategy.o: robot_validation_strategy.cpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@ 
$(OBJ_DIR)/robot_validation_strategy_repo.o: robot_validation_strategy_repo.cpp part.hpp robot_validation_strategy.hpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@ 
$(OBJ_DIR)/generic_validation_strategy.o: generic_validation_strategy.cpp robot_validation_strategy.hpp rrs_error.hpp part.hpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@ 
$(OBJ_DIR)/robot_order.o: robot_order.cpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@ 
$(OBJ_DIR)/robot_order_view.o: robot_order_view.cpp robot_order.hpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@ 
$(OBJ_DIR)/robot_order_controller.o: robot_order_controller.cpp robot_repo.hpp rrs_error.hpp robot_order_view.hpp robot_order_repo.hpp rrs_io.hpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@ 
$(OBJ_DIR)/robot_order_repo.o: robot_order_repo.cpp robot_order.hpp rrs_error.hpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@ 
$(OBJ_DIR)/tinyxml2.o: tinyxml2.cpp
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
$(OBJ_DIR)/robot_test.o: robot_test.cpp catch.hpp robot.hpp battery.hpp torso.hpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@ 
$(OBJ_DIR)/robot_repo_test.o: robot_repo_test.cpp robot.hpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@ 
$(OBJ_DIR)/battery_validation_strategy_test.o: battery_validation_strategy_test.cpp battery_validation_strategy.hpp robot.hpp catch.hpp battery.hpp torso.hpp rrs_error.hpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@ 
$(OBJ_DIR)/robot_validation_strategy_repo_test.o: robot_validation_strategy_repo_test.cpp robot_validation_strategy_repo.hpp robot.hpp catch.hpp battery.hpp torso.hpp rrs_error.hpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@ 
$(OBJ_DIR)/robot_order_repo_test.o: robot_order_repo_test.cpp robot_order_repo.hpp rrs_error.hpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@ 
clean:
	rm -f $(OBJ_DIR)/*.o a.out 
