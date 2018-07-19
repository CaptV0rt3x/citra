set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/CMakeModules)

add_executable(citra
    stub.cpp
)

if (MSVC)
    target_link_libraries(citra PRIVATE getopt)
endif()
target_link_libraries(citra PRIVATE ${PLATFORM_LIBRARIES} SDL2)

if (MSVC)
    include(CopyCitraSDLDeps)
    copy_citra_SDL_deps(citra)
endif()
