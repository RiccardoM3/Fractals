add_executable(fractal_app main.cpp)

find_library(libsfml-dev REQUIRED )

set(SFML_LIBS
    sfml-graphics
    sfml-system
    sfml-window
)

target_link_libraries(${PROJECT_NAME} ${SFML_LIBS})