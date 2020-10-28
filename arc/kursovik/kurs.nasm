.model large;	

.stack 100h;	

.data;

i dw 0h

m dw 0h

j dw 0h

String db "Enter a line: $"	

Stg db 100h dup(0h);	 Ìàññèâ äëÿ ñòðîêè

mas dw 100h dup(0h)	

.code;

.386

Start:	

  mov ax, @data;	

  mov ds, ax;

  mov ah, 00h;	 Î÷èñòêà ýêðàíà

  mov al, 2h;	

  int 10h

  mov ah, 09h

  Lea dx, String

  int 21h	

  mov ah, 1h;	 Ô-ÿ ââîäà ñèìâîëà

  mov si, 0h

  mov di,0h

Input:	 ;Ââîä ìàññèâà

  int 21h

  mov Stg[si], al;	 Ïîìåùåíèå ñèìâîëà â ìàññèâ

  inc si

  cmp al, 32;	 Ïðîâåðêà íà ïðîáåë

  jne Skip1

  cmp i,0

  je Input

  mov dx,i

  mov  mas[di],dx

  mov i,0

  mov dx,0

  add di,2

  jmp Input

Skip1:

  inc i	

  cmp al, 13

  jne Input

  dec i

  dec si

  mov dx,i

  mov mas[di],dx

  mov Stg[si], 0h;	 Óäàëåíèå Enter'à

  mov i,0h

  mov di,0

  mov si,di

  mov bx,0h

  mov ax,0h

  mov cx,ax

  mov dx,0h

Sort1:

    cmp mas[bx],0 

    je End_Sort1

    mov cx,bx

    mov si,bx

    add si,2

Sort2:

    cmp mas[si],0

    je End_Sort2

    mov dx,word ptr mas[si]

    mov bp,cx

    cmp word ptr ds:[mas+bp],dx

    jb Then1 

    mov cx,si

Then1:	

    add si,2

    jmp Sort2

End_sort2:

    mov dx,mas[bx]

    push bx

    mov bx,cx

    sub dx,mas[bx]

    pop bx

    mov m,dx

    mov si,0

Sort3:

    cmp si,cx

    je End_Sort3

    mov dx,mas[si]

    add dx,j

    inc dx

    mov j,dx

    add si,2

    jmp Sort3

End_Sort3:

    push si

    mov si,cx

Sort4:

    cmp di,mas[si]

    jae End_sort4

    mov bp,ax

    push bx

    mov bx,j

    mov dl,ds:[stg+bp+di]

    mov dh,stg[bx+di]

    mov ds:[stg+bp+di],dh

    mov stg[bx+di],dl

    pop bx

    inc di

    jmp sort4

End_sort4:

    pop si

    mov bp,cx

    push j

    mov dx,j

    add dx,ds:[mas+bp]

    inc dx

    mov j,dx

    mov si,j

Sort5:			; v konec stroki

    cmp stg[si],0

    je end_sort5

    inc si

    jmp Sort5

end_sort5:

    dec si

    push di

    mov di,si

    add di,m

Sort6:  		; copy to end of stg



    cmp si,j

    jbe end_sort6

    mov dx,0

    mov dl,stg[si]

    mov stg[di],dl

    dec di

    dec si

    jmp sort6

end_sort6:

    mov stg[di],32

    pop di

    pop j

Sort7:			; 2 word copy

    cmp di,mas[bx]

    jae End_sort7

    mov bp,j

    push bx

    mov bx,ax

    mov dl,stg[bx+di]

    mov ds:[stg+bp+di],dl

    pop bx

    inc di

    jmp Sort7

End_Sort7:

    mov si,j

    mov di,si

    sub di,m

    dec di

    mov stg[di],32

    inc di

Sort8:			; sdvig v seredine

    cmp stg[di],0

    je end_sort8

    mov dx,0

    mov dl,stg[si]

    mov stg[di],dl

    inc di

    inc si	

    jmp sort8

end_sort8:



    mov j,0

    mov dx,mas[bx]

    mov bp,cx

    mov di,ds:[mas+bp]

    mov ds:[mas+bp],dx

    mov mas[bx],di

    mov di,0

    add ax,mas[bx]

    inc ax

    add bx,2

    jmp Sort1

End_sort1:

    mov ah, 02h; Ô-ÿ óñòàíîâêè ïîçèöèè êóðñîðà:

    mov bh, 0h;	 ¹ Ñòðàíèöû	

    mov dh, 2h; ¹ ñòðîêè

    mov dl, 0h; ¹ ñòîëáöà

    int 10h

    mov bx, 0h

    mov si, 0h

    mov ah, 2h;	 Ô-ÿ âûâîäà ñèìâîëà

Output:	 ;Âûâîä ìàññèâà

    mov dl,stg[si]

    cmp dl,0

    je Exit

    inc si

    int 21h

    jmp Output



Exit:

    mov ah,04Ch

    mov al,1h

    int 21h 

End Start