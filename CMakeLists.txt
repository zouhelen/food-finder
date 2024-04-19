cmake_minimum_required(VERSION 3.17)
set(CMAKE_CXX_STANDARD 17)
project(food-finder)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR "C:/Libraries/SFML-2.5.1/lib/cmake/SFML")
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

include_directories(c:/Libraries/SFML-2.5.1/include/SFML)

add_executable(food display.cpp
        button.cpp
        recipe.cpp
        dropdown.cpp
        recipeStorage.cpp)
target_link_libraries(food sfml-graphics sfml-audio)
