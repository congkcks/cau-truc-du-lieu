.model small
.stack 100h
.data
  muoi dw 10
  tb1 db 10,13,'ket qua la:$'
.code
  main proc
    mov ax,@data
    mov ds,ax
    
    mov ah,1
    int 21h
    sub al,48
    mov cx,0
    mov cl,al
    
    mov ah,9
    lea dx,tb1
    int 21h
    mov bx,1
    mov ax,1
    
    
    
    GiaiThua:
    mul bx
    inc bx
    cmp bx,cx 
    jle GiaiThua  
    mov cx,0
    lappush:
    mov dx,0
    div muoi
    cmp ax,0
    je tiep
    add dx,48
    push dx
    inc cx
    jmp lappush
          
    tiep:
    add dx,48
    push dx
    inc cx
    inso:
    pop dx
    mov ah,2
    int 21h
    loop inso
    
    
   main endp
  end main
    
    
    
    
    
    
    
    
    
    
     
      
      
      
       