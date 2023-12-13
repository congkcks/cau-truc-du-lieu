.model small
.stack 100h
.data
  tb1 db 'nhap xau vao: $'
  tb2 db 10,13,'do dai cua chuoi vua nhap la :$'
  s db 100 dup('$')
  muoi db 10
  
.code
  main proc
    mov ax,@data
    mov ds,ax
    
    mov ah,9
    lea dx,tb1
    int 21h
    mov bx,0
    
    nhaptiep:
    mov ah,1
    int 21h
    cmp al,13
    je enter
    mov s[bx],al
    inc bx
    jmp  nhaptiep
    
    enter:
    mov ax,bx
    mov bx,0
    lap2:
    mov ah,0
    div muoi
    cmp ah,0
    je tiep
    push ax
    inc bx
    jmp lap2
    tiep:
    mov cx,bx
    mov ah,9
    lea dx,tb2
    int 21h 
    mov dx,0
    lap3:
    mov ah,2
    pop dx
    mov dl,dh
    add dl,48
    int 21h
    loop lap3
    
    
    mov ah,4ch
    int 21h
    
    main endp
  end main