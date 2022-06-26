cmake_minimum_required(VERSION 3.16.3)
project(Game)

file(GLOB SRC_FILES "*.cpp")

set(INC_FILES_DIR "../include/")

#set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML 2.5 COMPONENTS graphics audio system window REQUIRED)

include_directories(
	${INC_FILES_DIR}
)

add_executable(build ${SRC_FILES})

target_link_libraries(build sfml-graphics sfml-audio sfml-system sfml-window)
