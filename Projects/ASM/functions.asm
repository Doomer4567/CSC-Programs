extern atoi,fact,is_palindrome

SECTION .data
    prompt DB "Enter a potential Palindrome!: ", 10, 0
    Disprompt EQU $-prompt
    True DB "Is a Palindrome!", 10, 0
    dispTrue EQU $-True
    False DB "Is not a Palindrome!", 10, 0
    dispFalse EQU $-False
    newline db 10, 0


SECTION .bss
    num1 resb 2
    num2 resb 2
    user_input RESB 20
    length resd 1

SECTION .text

    Global addstr
    Global is_palindromeasm
    Global factstr
    Global palindrome_check

    addstr:
        push ebp
        mov ebp, esp
        push ebx



        mov eax, [ebp + 8]
        push eax
        call atoi
        add esp, 4
        mov ebx, eax

        mov eax, [ebp + 12]
        push eax
        call atoi
        add esp, 4

        add eax, ebx

        pop ebx
        pop ebp
        ret

    is_palindromeasm:
        push ebp
        mov ebp, esp
        push esi
        push edi

        mov esi, [ebp + 8]
        mov edi, esi

        find_end:
            cmp byte [edi], 0
            je check_loop_start
            inc edi
            jmp find_end

        check_loop_start:
            dec edi

        check_loop:
            cmp esi, edi
            jae true

            mov al, [esi]
            mov bl, [edi]
            cmp al, bl
            jne false

            inc esi
            dec edi
            jmp check_loop

        true:
            mov eax, 1
            jmp done

        false:
            xor eax, eax

        done:
            pop edi
            pop esi 
            pop ebp
            ret

    factstr:
        push ebp
        mov ebp, esp

        mov eax, [ebp + 8]
        push eax
        call atoi
        add esp, 4

        push eax
        call fact
        add esp, 4

        pop ebp
        ret

    palindrome_check:
        push ebp
        mov ebp, esp

        mov edx, Disprompt
        mov ecx, prompt
        mov ebx, 1
        mov eax, 4
        int 80h
        
        mov edx, 20
        mov ecx, user_input
        mov ebx, 0
        mov eax, 3
        int 80h

        mov esi, ecx
        mov edi, eax
        dec edi
        add esi, edi
        cmp byte [esi], 10
        jne skip_strip
        mov byte [esi], 0
        skip_strip:

        push ecx
        call is_palindrome
        add esp, 4

        cmp eax, 1
        jne not_True

        mov edx, dispTrue
        mov ecx, True
        mov ebx, 1
        mov eax, 4
        
        int 80h
        jmp end

    not_True:
        mov edx, dispFalse
        mov ecx, False
        mov ebx, 1
        mov eax, 4
        int 80h

    end:
        pop ebp
        ret