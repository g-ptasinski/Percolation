cmake_minimum_required(VERSION 3.16)

# THIS HAS TO COME BEFORE THE PROJECT LINE
set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")
# THIS HAS TO COME BEFORE THE PROJECT LINE

project(CMakeSFMLProject LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_executable(Percolation src/main.cpp src/percolation.cpp src/percolation_stats.cpp src/union_find.cpp)
target_link_libraries(Percolation  PRIVATE sfml-graphics)
target_compile_features(Percolation  PRIVATE cxx_std_17)

if(WIN32)
    add_custom_command(
        TARGET Percolation 
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<BOOL:${ARCH_64BITS}>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:Percolation>
        VERBATIM)
endif()

install(TARGETS Percolation )
