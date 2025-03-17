#pragma once

#include "GuiBase.h"
#include "bakkesmod/plugin/bakkesmodplugin.h"
#include "bakkesmod/plugin/pluginwindow.h"
#include "bakkesmod/plugin/PluginSettingsWindow.h"
#include "version.h"

constexpr auto plugin_version = "1.0.0";

struct UOnlineSubsystem_execReadOnlineAvatars_Params
{
	void* Data;
	int32_t Count;
};

class AnonymousPfps : public BakkesMod::Plugin::BakkesModPlugin
{
public:
	void onLoad() override;
};
