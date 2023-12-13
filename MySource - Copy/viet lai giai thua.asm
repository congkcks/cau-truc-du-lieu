.model small
.stack 100h
.data
 muoi dw 10
 a db 0
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
   
   mov bx,1
   mov ax,1
   
   giaithua:
    mul bx
    inc bx
    loop giaithua  
    mov bx,0
    
    lappush:
    mov dx,0
    div muoi
    push dx
    inc bx
    cmp ax,0
    je tiep
    jmp lappush
    tiep:
    mov cl,0 
    mov cx,bx
    mov ah,9
    lea dx,tb1
    int 21h
    
    intiep:
    mov ah,2
    pop dx
    add dl,48
    int 21h
    loop intiep
    main endp
 end main
    
    
      
       
    
    
   
   
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 