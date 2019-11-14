%include "io.inc"

section .text
global CMAIN
CMAIN:
    ;write your code here
    and [rcx+8*rbx],dl
    ret