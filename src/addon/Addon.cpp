//
// Created by Seres67 on 16/05/2024.
//

#include "addon/Addon.hpp"
#include "imgui/imgui.h"

std::filesystem::path Addon::AddonPath;
std::filesystem::path Addon::SettingsPath;

void Addon::load(AddonAPI *aApi) {
    APIDefs = aApi;
    ImGui::SetCurrentContext(static_cast<ImGuiContext *>(APIDefs->ImguiContext));
    ImGui::SetAllocatorFunctions(
            (void *(*)(size_t, void *)) APIDefs->ImguiMalloc,
            (void (*)(void *, void *)) APIDefs->ImguiFree); // on imgui 1.80+

    MumbleLink = (Mumble::Data *) APIDefs->GetResource("DL_MUMBLE_LINK");
    NexusLink = (NexusLinkData *) APIDefs->GetResource("DL_NEXUS_LINK");

//    APIDefs->RegisterWndProc(WndProc);

    APIDefs->RegisterRender(ERenderType_Render, Addon::render);
    APIDefs->RegisterRender(ERenderType_OptionsRender, Addon::render_options);

    AddonPath = APIDefs->GetAddonDirectory("keyboard_overlay");
    SettingsPath = APIDefs->GetAddonDirectory("keyboard_overlay/settings.json");
    std::filesystem::create_directory(AddonPath);
//    Settings::Load(SettingsPath);
//
//    if (!Settings::Settings["AllKeybindings"].is_null())
//        Settings::Settings["AllKeybindings"].get_to(keys);
//
//    Log::info("finished applying all settings!");
}

void Addon::unload() {
    APIDefs->DeregisterRender(Addon::render);
    APIDefs->DeregisterRender(Addon::render_options);

//    APIDefs->DeregisterWndProc(WndProc);

    MumbleLink = nullptr;
    NexusLink = nullptr;

//    json settings_json = keys;
//    Settings::Settings["AllKeybindings"] = settings_json;
//    Settings::Save(SettingsPath);
}

void Addon::render() {
    //"pseudo" code
//    if (Settings.isEnabled) {
        ImGui::PushFont(static_cast<ImFont *>(NexusLink->Font));
        if (ImGui::Begin("window title", nullptr, 0)) {
        }
        ImGui::PopFont();
        ImGui::End();
//    }
}

void Addon::render_options() {
    ImGui::Text("addon name");
    ImGui::TextDisabled("Widget");
//    if (ImGui::Checkbox("Enabled##Widget",
//                        &Settings::IsKeyboardOverlayEnabled)) {
//        Settings::Settings[IS_KEYBOARD_OVERLAY_ENABLED] =
//                Settings::IsKeyboardOverlayEnabled;
//        Settings::Save(Addon::SettingsPath);
//    }
}
