// Copyright 2018 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#define SDL_MAIN_HANDLED
#include <SDL.h>

int main(int argc, char* argv[]) {
#ifdef _WIN32
    auto msg = "\"citra.exe\" has been renamed to \"citra-cmd.exe\". Please update your shortcuts, "
               "and delete \"citra.exe\" after renaming";
#else
    auto msg = "\"citra\" has been renamed to \"citra-cmd\". Please update your shortcuts, and "
               "delete \"citra\" after renaming";
#endif
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Citra - ERROR", msg, nullptr);
    return 0;
}
