.model small
.stack 100h

.data
    n db 10
    sum dw 0

.code
main proc
    mov ax, @data
    mov ds, ax

    mov cl, n  ; Luu giá tr? c?a n vào thanh ghi cl
    mov ax, 0  ; Kh?i t?o giá tr? ban d?u c?a sum b?ng 0

    loop_start:
        add ax, cx  ; C?ng giá tr? c?a cl vào sum
        dec cl      ; Gi?m giá tr? c?a cl di 1
        cmp cl, 0   ; So sánh giá tr? c?a cl v?i 0
        jnz loop_start  ; N?u cl khác 0, quay l?i vòng l?p

    mov sum, ax  ; Luu giá tr? cu?i cùng c?a sum vào sum

    ; In ra màn hình t?ng t? 1 d?n n
    mov ax, sum
    mov bx, 10   ; S? co s? d? chuy?n d?i sang h? th?p phân
    call print_decimal

    mov ah, 4ch
    int 21h

main endp

print_decimal proc
    push ax
    push bx
    push cx
    push dx

    mov cx, 0     ; Kh?i t?o d?m s? ch? s? là 0

    check_zero:
        cmp ax, 0  ; Ki?m tra n?u ax b?ng 0
        jne nonzero  ; N?u không b?ng 0, nh?y t?i nonzero

        mov dl, '0' ; In ch? s? 0 ra màn hình
        mov ah, 02h
        int 21h

        jmp end_check  ; Nh?y t?i k?t thúc ki?m tra

    nonzero:
        mov bx, 10   ; S? co s? d? chuy?n d?i sang h? th?p phân
        div bx       ; Chia ax cho bx, k?t qu? ? trong al, du ? trong ah

        add dl, '0'  ; Chuy?n d?i giá tr? s? thành ký t? ASCII
        mov ah, 02h
        int 21h

        inc cx       ; Tang d?m s? ch? s? lên 1

        cmp ax, 0    ; Ki?m tra n?u ax b?ng 0
        jne nonzero  ; N?u không b?ng 0, quay l?i vòng l?p

    end_check:
        mov ah, 02h
        mov dl, 0Ah  ; In xu?ng dòng
        int 21h

    pop dx
    pop cx
    pop bx
    pop ax
    ret
print_decimal endp

end main