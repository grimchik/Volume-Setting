

TH32CS_SNAPPROCESS      equ 00000002h

MAX_PATH			    equ 260


PROCESSENTRY32 struct
    dwSize              dword ?
    cntUsage            dword ?
    th32ProcessID       dword ?
    th32DefaultHeapID   dword ?
    th32ModuleID        dword ?
    cntThreads          dword ?
    th32ParentProcessID dword ?
    pcPriClassBase      dword ?
    dwFlags             dword ?
    szExeFile           dw MAX_PATH dup(?)
PROCESSENTRY32 ends


;Prototypes of external procedures
extern CloseHandle@4:NEAR
extern CreateToolhelp32Snapshot@8:NEAR
extern Process32FirstW@8:NEAR
extern Process32NextW@8:NEAR
extern waveOutSetVolume@8:NEAR
