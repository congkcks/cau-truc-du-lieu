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
    mov cl,1 ; Luu gi� tr? c?a n v�o thanh ghi cl
    mov al, 0  ; Kh?i t?o gi� tr? ban d?u c?a sum b?ng 0

    loop_start:
        add al, cl  ; C?ng gi� tr? c?a cl v�o sum
        inc cl      ; Gi?m gi� tr? c?a cl di 1
        cmp cl, bl   ; So s�nh gi� tr? c?a cl v?i 0
        jle loop_start  ; N?u cl kh�c 0, quay l?i v�ng l?p   
        
    
    mov ah,0      
    mov bl,10                                                       
    div bl
    mov bh,ah
       
      ; Luu gi� tr? cu?i c�ng c?a sum v�o sum

    ; In ra m�n h�nh t?ng t? 1 d?n n
    
    ; Chuy?n d?i gi� tr? s? th�nh k� t? ASCII
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