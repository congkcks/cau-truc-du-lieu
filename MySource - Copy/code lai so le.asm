.model small
.stack 100h
.data
  s1 db 'nhap xau vao:$'
  s4 db 10,13,'cac so vua nhap:$'
  s2 db 10,13,'tong cac so le:$'  
  s db 100 dup('$')
  s3 db 100 dup('$')
  a db 2
  b db 10
.code
main proc
    mov ax,@data
    mov ds,ax
    
    mov ah,9
    lea dx,s1
    int 21h
    
    mov bx,0
    intiep:
     mov ah,1
     int 21h
     cmp al,48
     je enter
     mov s[bx],al
     sub al,48
     mov s3[bx],al
     inc bx
     jmp intiep
     
     enter:
     
     mov cx,bx 
     mov ah,9
     lea dx,s4
     int 21h
     lea dx,s
     int 21h
     mov bx,0
     mov bl,0
     mov al,0
     mov si,0
     
     sole:
     mov ah,0
     mov al,s3[si]
     div a
     cmp ah,1
     jne tiep
     add bl,s3[si]
     tiep:
     inc si
     cmp si,cx
     jle sole
     mov si,0
     
     mov al,bl
     
     lappush:
     
        mov ah,0
        div b
        cmp ah,0
        je inso
        push ax
        inc si
        jmp lappush
        
     inso:
     mov cx,si
     mov ah,9
     lea dx,s2
     int 21h
     
     intong:
      mov ah,2
      pop dx
      mov dl,dh
      add dl,48
      int 21h
      loop intong
     
         
         
  
      mov ah,04ch
      int 21h
 main endp
end main
     
        
     
     
     
     
     
       