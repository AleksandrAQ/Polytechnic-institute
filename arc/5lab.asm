org 100h 

mov ax, [value+2]
mov bx, [value]

	shr ax, 4 
	rcr bx, 4 
	adc ax, bx 
call sdvig1
mov [value+2], ax
mov [value], bx

push word [value+2]
push word [value]
call sdvig2
pop word [value]
pop word [value+2]

ret

sdvig1:
	shr ax, 4 
	rcr bx, 4 
	adc ax, bx 
ret

sdvig2:
	pop dx
	pop bx
	pop ax

	shr ax, 4 
	rcr bx, 4 
	adc ax, bx

	push ax
	push bx
	push dx
	ret
ret

value dd 0x12345678
