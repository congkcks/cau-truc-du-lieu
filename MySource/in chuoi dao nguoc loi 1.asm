 .model small
 .stack 100h
 .data
 s1 db 'nhap xau:$'
 s2 db 10,13,'xau sau khi dao nguoc:$'
 s3 db 100 dup('$')
 s4 db 100 dup('$')
 
 
 
 .code
 main proc
    mov ax,@data
    mov ds,ax
    
    mov ah,9
    lea dx,s1
    int 21h
    mov bx,0
    nhaptiep:
    mov ah,1
    int 21h
    cmp al,13
    je enter
    mov s3[bx],al
    inc bx
    jmp nhaptiep 
    enter:
    mov si,0
    mov di,0 
    mov cx,bx
    mov bx,0
    
    mov ah,9
    lea dx,s2
    int 21h
    
    
    lap1:
    mov al,s3[bx]
    push ax
    inc si
    cmp si,bx 
    jle lap1
    
    mov cx,bx
    lap2:
    pop dx
    mov ah,2 
    int 21h
    loop lap2
    
     
    
      
    
    
    mov ah,4ch
    int 21h
    
  main endp
 end main