cmake_minimum_required(VERSION  2.8)
set(CMAKE_CXX_STANDARD)

project(naval_war)

set(src_files lib/attackgrid.cpp lib/boat.cpp lib/corazzata.cpp lib/defensegrid.cpp lib/esplorazione.cpp lib/person.cpp lib/player.cpp lib/robot.cpp lib/supporto.cpp lib/utilities.cpp)
set(header_files include/attackgrid.h  include/boat.h include/boats.h include/corazzata.h include/defensegrid.h include/esplorazione.h include/grid.h include/grids.h include/person.h include/player.h include/robot.h include/supporto.h include/utilities.h)
set(GCC_FLAGS "-g -O2")

add_definitions(${GCC_FLAGS})

include_directories(include lib)

add_library( naval_war
    ${src_files}
    ${header_files}    
)

add_executable(battaglia_navale
    src/game.cpp
)

add_executable(replay
    src/replay.cpp
)

target_link_libraries(battaglia_navale naval_war)
target_link_libraries(replay naval_war)