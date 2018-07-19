set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/CMakeModules)

add_executable(citra-cmd
    citra.cpp
    citra.rc
    config.cpp
    config.h
    default_ini.h
    emu_window/emu_window_sdl2.cpp
    emu_window/emu_window_sdl2.h
    resource.h
)

create_target_directory_groups(citra-cmd)

target_link_libraries(citra-cmd PRIVATE common core input_common network)
target_link_libraries(citra-cmd PRIVATE inih glad)
if (MSVC)
    target_link_libraries(citra-cmd PRIVATE getopt)
endif()
target_link_libraries(citra-cmd PRIVATE ${PLATFORM_LIBRARIES} SDL2 Threads::Threads)

if(UNIX AND NOT APPLE)
    install(TARGETS citra-cmd RUNTIME DESTINATION "${CMAKE_INSTALL_PREFIX}/bin")
endif()

if (MSVC)
    include(CopyCitraSDLDeps)
    copy_citra_SDL_deps(citra-cmd)
endif()
