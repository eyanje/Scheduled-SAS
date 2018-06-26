#pragma comment(linker, "/SUBSYSTEM:WINDOWS")

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <process.h>
#include <string>
#include <Windows.h>

int WINAPI WinMain(HINSTANCE inst, HINSTANCE prev, LPSTR cmd, int show)
{
    std::time_t time = std::time(0);
    std::tm* now = std::localtime(&time);
    int mday = now->tm_mday;
    std::string sysInArg = "-SYSIN \"K:\\Data2\\Projects\\MVP\\Joe\\dev\\mondayupdate\\regular Monday - not first Monday of each month.sas\"";
    if (mday <= 7)
        sysInArg = "-SYSIN \"K:\\Data2\\Projects\\MVP\\Joe\\dev\\mondayupdate\\first Monday of each Month.sas\"";
    execl("\"D:\\Program Files\\SASHome\\SASFoundation\\9.4\\sas.exe\"",
          "-icon",
          "-noterminal",
          "-nosplash",
          "-noxwait",
          "-CONFIG \"K:\\Program Files\\SASHome\\SASFoundation\\9.4\\nls\\en\\sasv9.cfg\"",
          sysInArg,
          "-LOG K:\\Data2\\Projects\\MVP\\Joe\\saslog\\monday.log",
          "-PRINT K:\\Data2\\Projects\\MVP\\Joe\\sasout\\monday.txt");
    return 0;
}