// dllmain.cpp : Defines the entry point for the DLL application.
#include <Windows.h>
#include <iostream>

#include "sdk/minecraft/minecraft.h"
#include "sdk/minecraft/classes/classes.h"

void thread_entry(HMODULE module) {
	FILE* output_buffer = nullptr;

	AllocConsole();
    freopen_s(&output_buffer, "CONOUT$", "w", stdout);

    jvm::load();
    classes::load();

	while (!GetAsyncKeyState(VK_DELETE)) {
		c_minecraft minecraft = c_minecraft::get_minecraft();
		c_entity local_player = c_minecraft::getLocalPlayer();

		std::cout << "local player: " << local_player.cached_object << std::endl;
        /*if (GetAsyncKeyState('W') && local_player.cached_object) {
			local_player.set_sprinting(true);
            std::cout << "sprint true" << std::endl;
		}*/


		Sleep(1000);
	}


    if (output_buffer) {
        fclose(output_buffer);
    }
    FreeConsole();
	FreeLibraryAndExitThread(module, 0ul);
};


BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH: {
		HANDLE thread_handle = CreateThread(nullptr, 0ull, reinterpret_cast<LPTHREAD_START_ROUTINE>(thread_entry), hModule, 0ul, nullptr);
        if (thread_handle && thread_handle != INVALID_HANDLE_VALUE) {
			CloseHandle(thread_handle);
        }
        break;
    }

    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

