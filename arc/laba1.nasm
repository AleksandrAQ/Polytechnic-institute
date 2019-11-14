org 0x100

add ax,bx
add ax,bx
add bx,ax

mov cx,5
mov bx,0

for:
mov ax,[A+bx]
mov [B+bx],ax
add bx,2
loop for

xor si,si
mov cx,5
mov si,[E]
mov di,[X]
rep movsw

A dw 1,2,3,4,5
B dw

E dw 6,7,8,9
