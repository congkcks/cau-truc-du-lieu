.model small
.stack 100h
.data
s1 db 'nhap day so nhi phan:$'
s db 100 dup('$')
a db 2
b db 10
.code
main proc
    mov ax,@data
    mov ds,ax 
    
    mov ah,9
    lea dx,s1
    int 21h
    mov bx,0;
    nhaptiep:
    mov ah,1
    int 21h
    cmp al,13
    je enter
    sub al,48
    mov s[bx],al
    jmp nhaptiep  
    
    enter:
    mov cx,bx
    mov bx,0 
    lappush:
    mov al,s[bx]
    push ax
    inc bx
    cmp bx,cx
    jle lappush
     
    mov al,0
    mov bx,0
    mov dx,0
    mov bl,0
    mov si,0
    sothapphan:
    mov ah,0
    mul a
    pop dx
    mul dl
    add bl,al
    inc si
    cmp si,cx
    jle sothapphan  
    mov al,bl
    chiaso:
    mov ah,0
    div b
    cmp ah,0
    je inso
    push ax
    jmp chiaso
    
    inso: 
    mov ah,2
    pop dx
    mov dl,dh
    add dl,48
    int 21h
    loop inso
    
    
    mov ah,4ch
    int 21h
main endp
end main
    

    
    
    
     
    
    
    

    
    
    