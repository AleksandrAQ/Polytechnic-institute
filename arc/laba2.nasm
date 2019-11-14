org 0x100

;call one
call two

ret

;odnorazryadni chisla
one:
mov cx,5
mov bx,0
for:
 mov ax,48
 add ax,[A+bx]
 mov dl,al
 mov ah,2
 int 21h
 add bx,2
loop for
ret

;dvuznachnie
two:
mov ax,Num
mov cx,10

Repeat:
	xor	dx,dx          ; Обнуляем DX (для деления)
	div	cx             ; Делим DX:AX на CX (10),
                                       ; Получаем в AX частное, в DX остаток
	xchg	ax,dx          ; Меняем их местами (нас интересует остаток)
	add	al,'0'         ; Получаем в AL символ десятичной цифры
	stosb                  ; И записываем ее в строку
	xchg	ax,dx          ; Восстанавливаем AX (частное)
	or	ax,ax          ; Сравниваем AX с 0
	jne	Repeat         ; Если не ноль, то повторяем

; Теперь осталось вывести строку на экран
	mov	ah,9
	lea	dx,[di+1]      ; Заносим в DX адрес начала строки
	int	21h            ; Выводим ее на экран

	int	20h            ; Выходим из программы

Num db 123
A dw 1,2,3,4,5
B dw 12,13,14,15