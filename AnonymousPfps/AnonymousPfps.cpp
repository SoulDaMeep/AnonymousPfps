#include "pch.h"
#include "AnonymousPfps.h"


BAKKESMOD_PLUGIN(AnonymousPfps, "Martinn's Profile Picture Remover (Steam only)", plugin_version, PLUGINTYPE_FREEPLAY)

std::shared_ptr<CVarManagerWrapper> _globalCvarManager;

void AnonymousPfps::onLoad()
{
	_globalCvarManager = cvarManager;

	if (gameWrapper->GetUniqueID().GetPlatform() != OnlinePlatform_Steam) {
		// Unload because player is not steam user 
		// which means they do not have the function hook to hook.
		cvarManager->executeCommand("sleep 500; plugin unload anonymouspfps");
		return;
	}


	// Martinn's Code.
	// Uploaded on behalf.
	// https://discord.com/channels/862068148328857700/1351238296902041670/1351275317209071717
	gameWrapper->HookEventWithCaller<ServerWrapper>(
		"Function OnlineSubsystemSteamworks.OnlineSubsystemSteamworks.ReadOnlineAvatars",
		[this](auto caller, void* params, ...)
		{
			auto ROAargs = (UOnlineSubsystem_execReadOnlineAvatars_Params*)params;
			ROAargs->Count = 0;
		}
	);
}