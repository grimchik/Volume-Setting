.386p
.model flat, stdcall, C  
;includelib C:\masm32\lib\winmm.lib

include \masm32\include\msvcrt.inc
include \masm32\include\winmm.inc
include \masm32\include\user32.inc
include \masm32\include\kernel32.inc
include resources.inc
printf PROTO C, :VARARG
.CODE
setVolume proc
						mov eax, 1
						mov ebx, 0
						push ebx
						push eax
						call waveOutSetVolume
						mov eax, eax
						mov ebx, eax
						ret
setVolume endp
END