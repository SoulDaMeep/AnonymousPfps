#pragma once

#include "GuiBase.h"
#include "bakkesmod/plugin/bakkesmodplugin.h"
#include "bakkesmod/plugin/pluginwindow.h"
#include "bakkesmod/plugin/PluginSettingsWindow.h"
#include "version.h"

constexpr auto plugin_version = "1.0.0";

template<typename T>
class TArray
{
public:
	T* ArrayData;
	int32_t ArrayCount;
	int32_t ArrayMax;
};
struct FUniqueNetId
{
	uint64_t Uid;
	unsigned char pad[0x0041 - 0x0008]; // pad for size.       
};
struct UOnlineSubsystem_execReadOnlineAvatars_Params
{
	TArray<struct FUniqueNetId> PlayerNetIds;
	unsigned char pad[0x0018 - 0x0010]; // pad for size.
};

class AnonymousPfps : public BakkesMod::Plugin::BakkesModPlugin
{
public:
	bool IsSteam = false;
	void onLoad() override;
	void onUnload() override;
};
