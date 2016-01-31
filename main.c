/*
 * Copyright (C) 2016  173210 <root.3.173210@live.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <pspkernel.h>
#include <pspsdk.h>

#define STROF(str) #str
#define STROF_MACRO(str) STROF(str)

#define NAME "PBOOT.PBP Writer"

#define MAJOR_VER 0
#define MINOR_VER 0

PSP_MODULE_INFO(NAME, PSP_MODULE_USER, 0, 0);

int main()
{
	SceUID f, cb;
	int r;

	pspDebugScreenInit();

	pspDebugScreenPuts(
		NAME " " STROF_MACRO(MAJOR_VER) "." STROF_MACRO(MINOR_VER) "\n"
		"Copyright (C) 2016 173210 <root.3.173210@live.com>\n"
		"This program comes with ABSOLUTELY NO WARRANTY.\n"
		"This is free software, and you are welcome to redistribute it\n"
		"under certain conditions; see COPYING for details.\n"
		"\n"
		"Opening PBOOT.PBP");
	f = sceIoOpen("ms0:/PSP/GAME/ULES01003/PBOOT.PBP/",
		PSP_O_WRONLY | PSP_O_CREAT | PSP_O_TRUNC, 0777);
	pspDebugScreenPrintf(" -> 0x%08X\n", f);
	if (f >= 0) {
		pspDebugScreenPuts("Closing PBOOT.PBP");
		r = sceIoClose(f);
		pspDebugScreenPrintf(" -> 0x%08X\n", r);
	}

	cb = sceKernelCreateCallback("cb", (void *)sceKernelExitGame, NULL);
	if (cb >= 0)
		sceKernelRegisterExitCallback(cb);

	sceKernelSleepThreadCB();
	while (1);
}
