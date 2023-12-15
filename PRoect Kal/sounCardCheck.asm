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
PUBLIC check
check PROC
    call waveOutGetNumDevs
    ret
check ENDP
END