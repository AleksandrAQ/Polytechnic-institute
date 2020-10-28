org 0x100

start:
;передача через стек
	push 8
	push 4
	push A
	call bigrol1
	add sp,6
;передача через регистры
	mov dx, 8
	mov cx, 4
	mov bx, A
	call bigrol2
;передача через общую область памяти
	mov word [cnt], 8
	mov word [len], 4
	mov word [adr], A
	call bigrol3

	mov ax,4c00h;закончить программу
	int 21h

;циклический сдвиг влево многобайтового числа на заданное количество бит
bigrol1:
	push bp
	mov bp,sp
	push bx	
	mov dx,[bp+8]
l3:	mov cx,[bp+6]
	mov bx,[bp+4]
	clc
l1:	rcl byte [bx],1
	inc bx
	rcl byte [bx],1
	inc bx
	rcl byte [bx],1
	inc bx
	rcl byte [bx],1
	inc bx
	adc [bx],1
	jnb l2
	mov bx,[bp+4]
	or byte [bx],1
l2:	dec dx
	jnz l3
	pop bx
	pop bp
	ret
;циклический сдвиг влево многобайтового числа на заданное количество бит
;передача параматров через регистры
bigrol2:
l13:	clc;
	push bx
	push cx
l11:	rcl byte [bx],1
	inc bx	
	loop l11
	pop cx          ;восстановить регистры
	pop bx
	jnc l12
	or byte [bx],1	
l12:	dec dx		
	jnz l13		
	ret

;циклический сдвиг влево многобайтового числа на заданное количество бит
;передача параматров через общую область памяти
bigrol3:
	mov dx,[cnt]	
l23:	mov cx,[len]	
	mov bx,[adr]	
	clc		
l21:	rcl byte [bx],1	
	inc bx		
	loop l21		
	jnc l22		
	mov bx,[adr]	
	or byte [bx],1	
l22:	dec dx		
	jnz l23		
	ret


A	db 1,2,3,4
;общая область памяти
adr	dw 0
len	dw 0
cnt	dw 0