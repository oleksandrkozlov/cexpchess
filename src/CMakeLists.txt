add_library(cexpchesslib STATIC Game.cpp)
target_link_libraries(cexpchesslib PRIVATE fmt::fmt)

add_executable(cexpchess Main.cpp)
target_link_libraries(cexpchess PRIVATE cexpchesslib)
target_include_directories(cexpchesslib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(cexpchess PRIVATE docopt spdlog::spdlog)
install(TARGETS cexpchess DESTINATION ${CMAKE_INSTALL_BINDIR})
