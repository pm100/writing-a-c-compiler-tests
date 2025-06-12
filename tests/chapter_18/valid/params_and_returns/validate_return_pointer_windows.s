;     .globl main
; main:
;     pushq	%rbp
;     movq	%rsp, %rbp
;     # allocate stack space for result struct
;     subq    $32, %rsp
;     movq    %rsp, %rdi # rsp points to result space
;     movq    $0, %rax # make sure RAX isn't a valid pointer to start
;     callq   return_in_mem
;     # check result, using RAX as base pointer
;     cmpq    $1, 0(%rax)
;     jne .Lfail
;     cmpq    $2, 8(%rax)
;     jne .Lfail
;     cmpq    $3, 16(%rax)
;     jne .Lfail
;     # success
;     movq    $0, %rax
;     movq    %rbp, %rsp
;     popq    %rbp
;     retq
; .Lfail:
;     # fail - raise SIGSEGV
;     movl	$11, %edi
;     callq	raise@PLT
;     movq    %rbp, %rsp
;     popq    %rbp
;     retq
; 	.section	".note.GNU-stack","",@progbits

bits 64
default rel
extern return_in_mem
extern putchar
segment .text
global main
main: 
        push rbp
        mov rbp, rsp
        sub rsp, 32

        mov rax,0
        mov rcx,rsp
        sub rsp, 32
        call return_in_mem
        add rsp ,32
        cmp QWORD [rax+0], 1
        jne .Lfail
        cmp QWORD [rax+8], 2
        jne .Lfail
        cmp QWORD [rax+16], 3
        jne .Lfail
        mov rcx, 'k'
        sub rsp ,32
      ;  call putchar
        add rsp, 32
        ; success   
        mov rax, 0
           mov rsp, rbp
        pop rbp
        ret
.Lfail:
        mov eax, 1
        mov rsp, rbp
        pop rbp
        ret