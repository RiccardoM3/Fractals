set(SOURCES
    main.cpp 
    fractal.cpp 
    fractal_renderer.cpp
)

add_executable(fractal_app ${SOURCES})

find_library(libsfml-dev REQUIRED)

set(SFML_LIBS
    sfml-graphics
    sfml-system
    sfml-window
)

target_link_libraries(${PROJECT_NAME} ${SFML_LIBS})