.model small
.stack 100h

.data
    n db 9
    sum db 0

.code
main proc
    mov ax, @data
    mov ds, ax

    mov bl, n 
    mov cl,1 ; Luu giá tr? c?a n vào thanh ghi cl
    mov al, 0  ; Kh?i t?o giá tr? ban d?u c?a sum b?ng 0

    loop_start:
        add al, cl  ; C?ng giá tr? c?a cl vào sum
        inc cl      ; Gi?m giá tr? c?a cl di 1
        cmp cl, bl   ; So sánh giá tr? c?a cl v?i 0
        jle loop_start  ; N?u cl khác 0, quay l?i vòng l?p   
        
    
    mov ah,0      
    mov bl,10                                                       
    div bl
    mov bh,ah
       
      ; Luu giá tr? cu?i cùng c?a sum vào sum

    ; In ra màn hình t?ng t? 1 d?n n
    
    ; Chuy?n d?i giá tr? s? thành ký t? ASCII
    mov ah, 02h
    mov dl,al 
    add dl,48
    int 21h 
    mov dl,bh
    add dl,48
    int 21h

    mov ah, 4ch
    int 21h
main endp
end main