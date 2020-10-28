;COM binaries are loaded in a new segment starting at offset 100h
;The area between the start of the segment and the offset 100h is the PSP (Program segment prefix)
org 100h

;Data and code is in one section 
section .text

start:
   ;Set the stack as far away as possible from the code but still in the same segment 
   mov ax, cs
   mov ss, ax
   xor sp, sp

   ;All other segment registers points to CS segment
   push cs
   pop ds
   push es
   pop ds 

   ;Be sure DF is 0
   cld


   mov ah, 09h
   mov dx, strInputSentence
   int 21h

   ;Allocate space for 255 byte buffer (the max) but keep the SP aligned at WORD boundary
   sub sp, 100h
   push 00ffh               ;Push the Buffer structure for INT 21/0ah
   mov WORD [buffer], sp
   ;Get the input string 
   mov dx, sp
   mov ah, 0ah
   int 21h

   ;Reserve an array of 256 WORD
   sub sp, 200h
   mov WORD [tokens], sp

   ;Tokenize the string
   mov bx, WORD [buffer]        
   movzx ax, BYTE [bx+01h]      ;String length
   add bx, 02h                  ;String start

   push ax
   push bx
   push WORD [tokens]           ;Output array
   push 0ffh                    ;Max items in output array
   call tokenize
   mov WORD [tokens_num], ax    ;Words found

   test ax, ax
   jz .no_words

   call show_original
   call show_ascending


jmp .end

.no_words:
   mov ah, 09h 
   mov dx, strNoWords
   int 21h

.end:   
   mov ax, 4c00h
   int 21h 

strInputSentence    db "Please, type a sentence: ", 24h
buffer              dw 0   
tokens              dw 0   
tokens_num          dw 0
strOriginalOrd      db 0dh, 0ah, "Here are the words as typed: " 
strCRLF             db 0dh, 0ah, 24h
strNoWords          db 0dh, 0ah, "No words typed!", 24h  
strAscendingOrd     db "Here are the words sorted in ascending order:", 0dh, 0ah, 24h  
strDescendingOrd    db "Here are the words sorted in descending order:", 0dh, 0ah, 24h    

show_original:
   mov dx, strOriginalOrd
   mov ah, 09h
   int 21h 

   mov si, WORD [tokens]
   mov cx, WORD [tokens_num];

.orig_ord:
   mov dx, WORD [si]
   int 21h 
   mov dx, strCRLF
   int 21h
   add si, 02h 
loop .orig_ord

    ret 


show_ascending:
   mov dx, strAscendingOrd
   mov ah, 09h
   int 21h 

   push strcmp
   push WORD [tokens]
   push WORD [tokens_num]
   call bubble_sort

   mov si, WORD [tokens]
   mov cx, WORD [tokens_num];

.asc_ord:
   mov dx, WORD [si]
   int 21h 
   mov dx, strCRLF
   int 21h
   add si, 02h 
loop .asc_ord

   ret 


show_descending:
   mov dx, strDescendingOrd
   mov ah, 09h
   int 21h 

   push stricmp
   push WORD [tokens]
   push WORD [tokens_num]
   call bubble_sort

   mov si, WORD [tokens]
   mov cx, WORD [tokens_num];

.asc_ord:
   mov dx, WORD [si]
   int 21h 
   mov dx, strCRLF
   int 21h
   add si, 02h 
loop .asc_ord

   ret 

;Number of char   
;Sentence
;Array of pointers
;Array items
tokenize:
    push bp
    mov bp, sp

    sub sp, 02h

    push di
    push es
    push cx
    push si
    push bx
    push dx 

    mov dx, WORD [bp+0ah]
    mov cx, WORD [bp+04h]
    mov di, WORD [bp+06h]
    mov si, WORD [bp+08h]
    xor bx, bx

    mov BYTE [bp-02h], 00h  ;Status, 0 = Looking for a word start, 1 = Looking for word end

    ;DX = Character left to parse
    ;CX = Entries available in output array 
    ;DI = Ptr to Output array current entry
    ;SI = Ptr to current char in input string 
    ;BX = Words found

.look_for:
    test cx, cx
    jz .end 

    test dx, dx
    jz .end 

    lodsb
    dec dx

    ;   char is 20h    Status
    ;   0               0     found start 
    ;   0               1     jump back 
    ;   1               0     jump back 
    ;   1               1     found end 

    cmp al, 20h
    sete ah
    xor ah, BYTE [bp-02h]
    jnz .look_for

    ;Change status (0->1, 1->0)
    mov ah, BYTE [bp-02h]
    not ah 
    and ah, 01h 
    mov BYTE [bp-02h], ah
    jnz .found_start

    ;Found word end

    mov BYTE [si-01h], 24h      ;24h terminate the word

jmp .look_for

.found_start:
    ;Found word start 
    lea ax, [si-01h]
    stosw                       ;Save the pointer to the word
    dec cx                      ;Less available entries
    inc bx                      ;One more word found
jmp .look_for 

.end:
    mov BYTE [si], 24h      ;24h terminate last word
    mov ax, bx

    pop dx
    pop bx
    pop si
    pop cx
    pop es
    pop di 

    add sp, 02h

    pop bp
    ret 08h


;string1
;string2
strcmp:
    push bp
    mov bp, sp

    push si
    push di 
    push bx 

    mov si, WORD [bp+06h]
    mov di, WORD [bp+04h]

.compare:
    lodsb
    mov ah, BYTE [di]
    inc di 

    ;AH = String 2 char
    ;AL = String 1 char

    ;If String1 is ended, check the other string
    cmp al, 24h
    mov bl, ah              ;Value to check as terminator
    mov bh, 0ffh            ;Return value if the other string is not ended
    jz .strend

    ;If String2 is ended, check the other string
    cmp ah, 24h
    mov bl, al              ;Value to check as terminator
    mov bh, 01h             ;Return value if the other string is not ended
    jz .strend 

    ;Compare
    sub al, ah
    jz .compare             ;If equals, repeat
jmp .end                    ;Result is computed, just end

.preend:
    xor al, al              ;Equals

.end:
    pop bx 
    pop di 
    pop si 

    pop bp
    ret 04h 

.strend:
    cmp bl, 24h             ;Other string is ended, too?
    jz .preend              ;Success!

    mov al, bh              ;Return appropriate value
jmp .end 

;Like strcmp but negated
stricmp:
    push bp
    mov bp, sp 

    push WORD [bp+06h]
    push WORD [bp+04h]
    call strcmp 
    neg al 

    pop bp
    ret 04h


;comparer
;array
;elements
bubble_sort:
    push bp
    mov bp, sp

    sub sp, 02h 

    pusha

    cmp WORD [bp+04h], 2    ;Less than 2 element -> Already ordered
    jb .end

    mov di, WORD [bp+08h]   ;Comparer

.cycle:
    mov BYTE [bp-02h], 00h  ;No swap done
    mov cx, WORD [bp+04h]   ;Elements in array
    mov si, WORD [bp+06h]   ;Array
    dec cx                  ;Elements are compared in pairs

.sort:  
    lodsw
    push ax
    lodsw
    push ax
    call di                 ;Compare current and next string

    sub si, 02h             ;Get back to next string 
    cmp al, 00h
    jg .swap                ;If current > next, swap

.continue:  
    dec cx                  ;Elements left to compare
jnz .sort

    ;If no swap, the array is sorted
    cmp BYTE [bp-02h], 00h
    jne .cycle  

jmp .end

.swap:
    ;Naive swap
    mov ax, WORD [si-02h]
    mov bx, WORD [si]
    mov WORD [si], ax
    mov WORD [si-02h], bx 

    ;At least one swap done
    mov BYTE [bp-02h], 01h

jmp .continue   

.end:   
    popa 

    add sp, 02h 

    pop bp
    ret 06h 
