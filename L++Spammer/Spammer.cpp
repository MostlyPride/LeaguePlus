#include "PluginSDK.h"
#include "Spammer.h"

PluginSetup("Spammer");

#pragma region Events

// Making all these integers.

int Kill;
int Kill2 = 1;
int Assist;
int Assist2 = 1;

void MenuItem()
{
    Menu = GPluginSDK->AddMenu("L++Spammer");
    Preferences = Menu->AddMenu("Preferences");
	EnableV = Preferences->CheckBox("Kill Chat Spam", false);
	EnableA = Preferences->CheckBox("Assist Chat Spam", false);
	Key = Preferences->AddKey("GG Key", 97);
	Key2 = Preferences->AddKey("MiddleFinger Key", 98);
	Key3 = Preferences->AddKey("L++ Key", 99);
	Key4 = Preferences->AddKey("KYS Key", 100);
}

/* This is the basic assist function, works the same as the kill one. 
All we are doing is basically checking to see if the menu option is on
then seeing if game chat is open.
If the chat is closed, and menu is on. Then it will do w/e i want it to.
In this case, we assisgn Hero as the Entity player.
Then we get your players assists and store them as a int into the Assist
Once that is done, We compare your champion assists, to "Assist2". 
Since I assigned assist2 to = 1.
The code there means that if your champion assists are equal to, or great then 1. Do the function in the brackets.
Which is, run the function Say, and then add 1 to the assist2 integer. So now it = 2.
By doing that, our champions assists are 1 still and not greater then or equal to 2. So it won't spam the function over and over.
But once we get another assist or kill it will run it. 
*/


void Say()
{
	GGame->Say("/all L++! www.leagueplusplus.net");   // This is what is said on kill or assist.
}

void assistfunction()
{
	if (EnableA->Enabled() && !GGame->IsChatOpen())
	{
		auto Hero = GEntityList->Player();
		int Assist = Hero->GetAssists();

		if (Assist >= Assist2)
		{
			Say();
			Assist2++;
		}
	}

}

void killfunction()
{
	if (EnableV->Enabled() && !GGame->IsChatOpen())
	{
		auto Hero = GEntityList->Player();
		int Kill = Hero->GetKills();

		if (Kill >= Kill2)
		{
			Say();
			Kill2++;
		}
	}

}



void buttonfunction4()
{
	if (GetAsyncKeyState(Key4->GetInteger()))
	{
		GGame->Say("/all ___//__//");//6
		GGame->Say("/all __/____/");//7
		GGame->Say("/all _/____/");//8
		GGame->Say("/all ______\__________,,_");// 1
		GGame->Say("/all ____/_`-|||||||________-]-----KYS");//2
		GGame->Say("/all ___/=o___________/");//3
		GGame->Say("/all ___),-_(_(__)_/");//4
		GGame->Say("/all ____//(\)_),-");//5
	}

}

void buttonfunction3()
{
	if (GetAsyncKeyState(Key3->GetInteger()))
	{
		GGame->Say("/all _GG___________GG__GG_______GG");//6
		GGame->Say("/all _GGGGGGGGGGG");//7
		GGame->Say("/all _www.leagueplusplus.net_______");//8
		GGame->Say("/all _GGGGG___________");// 1
		GGame->Say("/all _GG__GG___________GG_______GG");//2
		GGame->Say("/all _GG__GG___________GG_______GG");//3
		GGame->Say("/all _GG__GG_______GGGGGG_GGGGGGGG");//4
		GGame->Say("/all _GG__GGGGGGG____GG_______GG");//5
	}

}

void buttonfunction2()
{
	if (GetAsyncKeyState(Key2->GetInteger()))
	{
		GGame->Say("/all ........('(...´...´.... ¯~/'...')");//6
		GGame->Say("/all .........\.................'...../");//7
		GGame->Say("/all ..........''...\.......... _.·´");//8
		GGame->Say("/all ....................../´¯/)");// 1
		GGame->Say("/all ....................,/¯../");//2
		GGame->Say("/all .................../..../");//3
		GGame->Say("/all ............./´¯/'...'/´¯¯`·¸");//4
		GGame->Say("/all ........../'/.../..../......./¨¯\ ");//5
	}

}




// holy fuck getting asci art to work in league is a bitch.
void buttonfunction()
{
	if (GetAsyncKeyState(Key->GetInteger()))
	{
		GGame->Say("/all __GG_________GG_GG________GG");//6
		GGame->Say("/all ___GG________GG__GG_______GG");//7
		GGame->Say("/all _____GGGGGGG_______GGGGGG");//8
		GGame->Say("/all ______GGGGGG________GGGGGG");// 1
		GGame->Say("/all ____GG_______GG___GG_______GG");//2
		GGame->Say("/all __GG____________GG");//3
		GGame->Say("/all _GG____________GG");//4
		GGame->Say("/all _GG_______GGGG_GG_____GGGG");//5
	}

}


// This is a plugin event, basically when this event occurs in game to do the functions inside the brackets.
PLUGIN_EVENT(void) OnGameUpdate()
{
	assistfunction();
	killfunction();
	buttonfunction();
	buttonfunction2();
	buttonfunction3();
	buttonfunction4();
}


// This is what loads when the plugin is selected in the core menu.
PLUGIN_API void OnLoad(IPluginSDK* PluginSDK)
{
    PluginSDKSetup(PluginSDK);
    MenuItem();
	GEventManager->AddEventHandler(kEventOnGameUpdate, OnGameUpdate);
}

//This is what unloads when the plugin gets deselected.
PLUGIN_API void OnUnload()
{
	GEventManager->RemoveEventHandler(kEventOnGameUpdate, OnGameUpdate);
    Menu->Remove();
}