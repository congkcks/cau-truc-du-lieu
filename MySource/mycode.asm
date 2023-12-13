.Model small
.Stack 100
.Data
n db 10
ketqua db ? 
Tb1 db 'ket qua la:$'
str db ? 
.Code
Main proc
    Mov ax,@Data
    mov ds,ax    
    mov ah,1
    int 21h
    sub al,'0'
   mov bl,al
   mov cl,1
   mov al,0  
   congtiep:
   add al,cl
   inc cl
   cmp cl,bl 
   jle congtiep
   
   mov ah,2
   mov dl,al
   add dl,'0'
   int 21h
    mov ah,4ch
    int 21h    
Main endp
End