cmake_minimum_required(VERSION 3.16)

project(cexpchess VERSION 0.1.0 LANGUAGES CXX)

list(PREPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

include(flags)
include(packages)
include(GNUInstallDirs)

if(CMAKE_BUILD_TYPE STREQUAL Debug)
    include(options)
    include(ccache)
    include(cmake-format)
    include(clang-format)
    include(clang-tidy)
    include(cppcheck)
    include(sanitizers)
    include(iwyu)
    include(kcov)
    enable_testing()
    add_subdirectory(tests)
endif()

add_subdirectory(src)

include(FeatureSummary)
feature_summary(WHAT ALL)
