.Model small
.stack 100h
.data 
s1 db 'n=$'
s2 db 10,13,'s=$'   
a db 0



.code
main proc
    mov ax,@data
    mov ds,ax  
    mov ah,9
    lea dx,s1
    int 21h
    mov bl,10
    nhaptiep:
    mov ah,1
    int 21h
    cmp al,13
    je enter
    sub al,48
    mov bh,al
    mov al,a
    mul bl
    add al,bh
    mov a,al 
    jmp nhaptiep
    
    
    enter:
    mov ah,9
    lea dx,s2
    int 21h
    mov bl,a
    mov cl,1
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    mov ah,4ch
    int 21h
    
main endp  
    
    