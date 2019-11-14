org 0x100

mov bx,0				; в BX записывать число
loopinp:
mov ah, 10h
int 16h                 ; получаем цифру
cmp al, 30h
jb finish				; если не цифра, то конец ввода
cmp al, 39h
ja finish
mov ah, 2
mov dl, al
int 21h					; эхо цифры на экран выводим
xor ah, ah				 
sub al, 30h				; получаем цифру из символа
mov cx, ax 				; сохраняем введенную цифру перед умножением
mov ax, 10
mul bx 					; умножаем накопленные значения на 10
mov bx, ax				; сохраняем результат в наш накопитель
add bx, cx				; и плюсуем цифру
jmp loopinp				; и опять к следующей цифре

finish:

mov ax, bx
xor     cx, cx
mov     bx, 10 			; основание 10 для десятеричной и т.п.

oi2:
xor     dx,dx
div     bx
			; Делим число на основание сс. В остатке получается последняя цифра.
			; Сразу выводить её нельзя, поэтому сохраним её в стэке.
push    dx
inc     cx
			; А с частным повторяем то же самое, отделяя от него очередную
			; цифру справа, пока не останется ноль, что значит, что дальше
			; слева только нули.
test    ax, ax
jnz     oi2
			; Теперь приступим к выводу.
mov     ah, 02h
oi3:
pop     dx
			; Извлекаем очередную цифру, переводим её в символ и выводим.
add     dl, '0'
int     21h
			; Повторим ровно столько раз, сколько цифр насчитали.
loop    oi3

ret