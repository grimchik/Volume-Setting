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
getVolume proc
					mov eax, 0
					mov ebx, 0
					push ebx
					push eax
					call waveOutGetVolume
					mov ebx,eax
					ret
getVolume endp
END
