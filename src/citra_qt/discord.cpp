// Copyright 2018 Citra Emulator Project
// Licensed under GPLv2+
// Refer to the license.txt file included.

#include "citra_qt/discord.h"
#include "citra_qt/ui_settings.h"
#include "common/common_types.h"
#include "core/core.h"

#ifdef USE_DISCORD_PRESENCE
#include <ctime>
#include <discord_rpc.h>
#endif

namespace DiscordRPC {

s64 StartTime;

void Init() {
    if (!UISettings::values.enable_discord_presence)
        return;

    StartTime = time(NULL);
    DiscordEventHandlers handlers = {};

    // The number is the client ID for Citra, it's used for images and the
    // application name
    Discord_Initialize("460746959536390145", &handlers, 1, nullptr);
}

void Shutdown() {
    if (!UISettings::values.enable_discord_presence)
        return;
    Discord_ClearPresence();
    Discord_Shutdown();
}

void Update() {
    if (UISettings::values.enable_discord_presence) {
        std::string title;
        Core::System::GetInstance().GetAppLoader().ReadTitle(title);
        DiscordRichPresence presence = {};
        presence.largeImageKey = "citra_logo";
        presence.largeImageText = "Citra is an emulator for the Nintendo 3DS";
        presence.state = title.empty() ? "Not in-game" : title.c_str();
        presence.details = "Playing Game:";
        presence.startTimestamp = StartTime;
        Discord_UpdatePresence(&presence);
    } else {
        Discord_ClearPresence();
    }
}

} // namespace DiscordRPC
