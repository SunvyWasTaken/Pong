project(Pong)

file(GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/sources/*.cpp")

add_library(${PROJECT_NAME} MODULE ${MY_SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/sources")

target_link_libraries(${PROJECT_NAME} PUBLIC
        Sunset::Runtime
)

set(SUNSET_GAME_TARGET ${PROJECT_NAME} CACHE STRING "Game module loaded by the editor")
