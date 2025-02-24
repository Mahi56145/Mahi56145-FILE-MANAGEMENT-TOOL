# filepath: file-management-tool/CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(FileManagementTool)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(FileManagementTool src/main.cpp src/file_manager.cpp)

target_link_libraries(FileManagementTool ws2_32)