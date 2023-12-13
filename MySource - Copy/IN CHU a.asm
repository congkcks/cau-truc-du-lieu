

;nhap chuoi truoc , in thong bao và in chuoi sau
.model small
.stack 100
.data
    tb1 DB 10,13, 'chuoi da nhap la: $';10 xuong dong , 13 lui dau dong* 
    str DB 100 dup('$') ;
.code
    main proc
        mov ax, @data
        mov ds,ax ;khoi tao thanh ghi ds 
          
        ;nhap chuoi ky tu
        mov ah,9 ;    10=0ah
        lea dx,tb1 ; tro den dia chi dau str
        int 21h 
        mov ah,1
        int 21h
        mov bl,al
        cmp al,97
        jge chuthuong
        mov dl,65
        jnp inkitu
chuthuong:
        mov dl,97
        inkitu:
        mov ah,2
        int 21h
        inc dl
        cmp dl,bl
       jle inkitu
        mov ah,4CH
        int 21h    
    main endp
 end 