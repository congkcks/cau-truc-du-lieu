.model small
.stack 100h
.data
 s1 db 'nhap chuoi :$'
 s2 db 10,13,' chuoi thuong:$'
 s3 db 10,13,'chuoi hoa:$'
 s db 100 dup('$')
 ct db 100 dup('$')
 sh db 100 dup('$'
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
    mov s[bx],al
    inc bx
    jmp nhaptiep
  
    
    enter:
      mov cx,bx
    mov bx,0
    mov si,0
    mov di,0
    doitiep:
    cmp s[bx],97
    jge chuthuong
    cmp s[bx],65
    jge chuhoa
    jmp tiep
    chuthuong:
    mov al,s[bx]
    mov ct[si],al
    inc si
    jmp tiep
    chuhoa:
    mov al,s[bx]
    mov sh[di],al
    inc di
    tiep:
    inc bx 
    cmp bx,cx
    jle doitiep
    mov ah,9 
    lea dx,s2
    int 21h
    lea dx,ct
    int 21h 
    
    lea dx,s3
    int 21h
    lea dx,sh
    int 21h
    
    
    mov ah,4ch
    int 21h
    
main endp
 end main
     
    
    
    
     
    
    
    
 
  