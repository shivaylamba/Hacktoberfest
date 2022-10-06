#include<stdio.h>
#include<windows.h>
int main(VOID)
{
    /* code */
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory(& si,sizeof(si));
    si.cb=sizeof(si);
    ZeroMemory(& pi,sizeof(pi));
    if(!CreateProcess(NULL,
    "E:\\Shikhar\\cpp\\Arm.exe",
    NULL,
    NULL,
    FALSE,
    0,
    NULL,
    NULL,
    &si,
    &pi))
    {
        fprintf(stderr,"Creation Failed");
        return -1;
    }
    WaitForSingleObject(pi.hProcess,INFINITE);
    printf("\n Child Process Completed:");
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
}
