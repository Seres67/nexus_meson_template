//
// Created by Seres67 on 16/05/2024.
//

#ifndef NEXUS_TEMPLATE_ADDON_HPP
#define NEXUS_TEMPLATE_ADDON_HPP

#include <filesystem>
#include "nexus/Nexus.h"
#include "Shared.hpp"

class Addon {
public:
    static void load(AddonAPI *aApi);

    static void unload();

    static void render();

    static void render_options();

private:
    static std::filesystem::path AddonPath;
    static std::filesystem::path SettingsPath;
    static constexpr std::string m_addon_name = "template";
};


#endif //NEXUS_TEMPLATE_ADDON_HPP
