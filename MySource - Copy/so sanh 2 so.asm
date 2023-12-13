.model small
.stack 100h
.data
ms1 db 10, 13, 'Nhap so 1 $' 
ms2 db 10, 13, 'Nhap so 2 $'    
ms3 db 10, 13, 'So 1 lon hon so 2$'
ms4 db 10, 13, 'So 2 lon hon so 1$'
.code
    main proc
        
        mov ax, @data
        mov ds, ax
        
        mov ah, 9
        lea dx, ms1
        int 21h
        
        ; Nhap va bl la so 1
        mov ah, 1
        int 21h 
        mov bl, al 
        
        
        mov ah, 9
        lea dx, ms2
        int 21h
        
        mov ah, 1
        int 21h  
        
        ; So sanh 2 so bl voi al
        cmp bl, al              
        jl nhohon
        
        mov ah, 9
        lea dx, ms3
        int 21h
        
        nhohon:
            
            Mov ah, 9
            lea dx, ms4
            int 21h
            mov ah, 4ch
            int 21h
        ; Truong hop ms1 < ms2 thi se chay dung
        ; Truong hop ms1 > ms2 thi se chay ra ca 2 dap an ms3, ms4
        
    main endp
    
    end main
