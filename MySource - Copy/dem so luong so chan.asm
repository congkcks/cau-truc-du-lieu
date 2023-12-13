.model small
.stack 100h 
.data
   
   s1 db 'nhap xau:$'
   s2 db 10,13,'xau vua nhap: $'  
   s4 db 10,13,'so luong so chan :$'
   s  db 100 dup('$') 
   s3 db 100 dup('$')
   a db 0
.code 
main proc
    mov ax,@data
    mov ds,ax
    
    mov ah,9
    lea dx,s1
    int 21h
             
    mov ch,0
    mov bx,0
    mov cl,2
    mov si,0
    mov di,0
    nhaptiep:
    mov ah,1
    int 21h
    cmp al,48
    je enter
    mov s[si],al
    sub al,48 
    mov s3[si],al
    inc si
    jmp nhaptiep
   enter:
   mov bx,si
   mov si,0
   mov ah,9
   lea dx,s2
   int 21h
   lea dx,s
   int 21h 
   sochan:
   mov ah,0 
   mov al,s3[si]
   div cl
   cmp ah,0
   je soluong 
   jmp tiep
   soluong:
   inc ch 
   tiep:
   inc si
   cmp si,bx
   jl sochan
   
   inso:
   mov ah,9
   lea dx,s4
   int 21h 
   mov ah,2
   mov dl,ch
   add dl,48
   int 21h 
   
   
  
   mov ah,4ch
   int 21h
   main endp
   
  
   
       
    
    
  