  .model small
.stack 100h
.data
     s1   db   'nhap xau: $'
     s2   db   10, 13, 'so chan: $'
     s3   db   10, 13, 'xau chu hoa: $'
     s4   db   10, 13, 'xau chu thuong: $'
     s5   db   10, 13, 'so: $'
     s    db   100 dup('$')
     st   db   100 dup(0)
     sh   db   100 dup('$') 
     so   db   100 dup(?)
     t    dw   0
     t1   dw   0 
     s7 db 10,13,'so luong so chan la: $' 
     s8 db 10,13,'cac so chan :$'
.code
     main proc
          mov ax, @data
          mov ds, ax
          
          mov ah, 9
          lea dx, s1
          int 21h
          mov bx, 0
          mov si,0 
          mov cl,2
          mov ch,0 
          mov bl,0
          mov di,0
nhaptiep:          
          mov ah, 1
          int 21h
          cmp al, 48
          je   sosanh 
          mov s[bx], al
          sub al,48
          mov st[bx],al
          inc bx
          jmp nhaptiep 
          
          

sosanh:
            
             mov ah,0
             mov al,st[si]
             div cl
             cmp ah,0
             je sochan
             inc si
             cmp si,bx
             jge tiep
             
sochan:
      inc ch 
      inc si
      cmp si,bx
      jl sosanh 
tiep:
    mov ah,9
    lea dx,s8
    int 21h
    
    lea dx,s7
    int 21h
    mov ah,2
    mov dl,ch
    add dl,48
    int 21h
     
    mov ah, 4ch
    int 21h
          
         main endp
  end main 