.model small
.stack 100h
.data 
  tb1 db 'nhap cac so:$'
  tb2 db 10,13,'tong cac so la:$'
  s db 100,0,100 dup('$')
  tong db 0
  muoi db 10
  .code
  main proc
    mov ax,@data
    mov ds,ax
    
    mov ah,9
    lea dx,tb1
    int 21h
    lea dx,s
    
    mov ah,0ah
    int 21h
    
    
    mov cx,0
    lea si,s+2
    mov cl,[s+1]
    
    mov ax,0
    lap1:
    mov bx,0
    mov bl,[si]
    sub bl,48
    add al,bl
    inc si
    loop lap1 
    mov cx,0
    
    lappush:
    mov dx,0 
    mov ah,0
    div muoi
    cmp al,0
    je tiep
    add ah,30h
    mov dl,ah 
    push dx
    inc cx
    jmp lappush
    tiep: 
    add ah,48
    mov dl,ah
    push dx
    inc cx
    mov ah,9
    lea dx,tb2
    int 21h
    
    hienthi:
    mov ah,2
    pop dx
    int 21h
    loop hienthi
    
    
    mov ah,4ch
    int 21h
    main endp
  end main
  
    
     
    
     
    
    
      
  
  
  
   
   