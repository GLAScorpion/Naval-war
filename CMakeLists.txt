cmake_minimum_required(VERSION  3.12)

project(naval_war)

set(src_files lib/elements/attackgrid.cpp lib/elements/boat.cpp lib/elements/corazzata.cpp lib/elements/defensegrid.cpp lib/elements/esplorazione.cpp lib/elements/person.cpp lib/elements/player.cpp lib/elements/robot.cpp lib/elements/supporto.cpp lib/elements/utilities.cpp)
set(header_files include/elements/attackgrid.h  include/elements/boat.h include/elements/boats.h include/elements/corazzata.h include/elements/defensegrid.h include/elements/esplorazione.h include/elements/grid.h include/elements/grids.h include/elements/person.h include/elements/player.h include/elements/robot.h include/elements/supporto.h include/elements/utilities.h)
set(GCC_FLAGS "-g -O2")

add_definitions(${GCC_FLAGS})

include_directories(include lib)

add_library( naval_war
    ${src_files}
    ${header_files}    
)

add_executable(battaglia_navale
    lib/game/game.cpp
)

add_executable(replay
    lib/game/replay.cpp
)

target_link_libraries(battaglia_navale naval_war)
target_link_libraries(replay naval_war)