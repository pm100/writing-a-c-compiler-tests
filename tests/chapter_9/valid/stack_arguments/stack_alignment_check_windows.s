    # generated from templates/stack_alignment_check.s.jinja
    #   [Register::RCX, Register::RDX, Register::R8, Register::R9];
    .text
    .globl even_arguments
even_arguments:
    pushq   %rbp
    movq    %rsp, %rbp
    # validate arguments, from 1 to 8
    cmpl    $1, %ecx
    jne     .Lfail_even_arguments
    cmpl    $2, %edx
    jne     .Lfail_even_arguments
    cmpl    $3, %r8d
    jne     .Lfail_even_arguments
    cmpl    $4, %r9d
    jne     .Lfail_even_arguments
    # 32 for the register save area
    cmpl    $5, 16+32(%rbp)
    jne     .Lfail_even_arguments
    cmpl    $6, 24+32(%rbp)
    jne     .Lfail_even_arguments
    cmpl    $7, 32+32(%rbp)
    jne     .Lfail_even_arguments
    cmpl    $8, 40+32(%rbp)
    jne     .Lfail_even_arguments
    # calculate rsp % 16; should be 0
    movq    %rsp, %rax
    movq    $0, %rdx
    movq    $16, %rcx
    div     %rcx
    # compare result (in rdx) to 0
    cmpq    $0, %rdx
    jne     .Lfail_even_arguments
    # all checks passed; return 1
    movl    $1, %eax
    popq    %rbp
    retq
    # failure case; exit w/ code -1
.Lfail_even_arguments:
    # exit w/ code -1
    movl    $-1, %ecx
    call    exit
    popq    %rbp
    retq
    .globl odd_arguments
odd_arguments:
    pushq   %rbp
    movq    %rsp, %rbp
    # validate arguments, from 1 to 7
    cmpl    $1, %ecx
    jne     .Lfail_odd_arguments
    cmpl    $2, %edx
    jne     .Lfail_odd_arguments
    cmpl    $3, %r8d
    jne     .Lfail_odd_arguments
    cmpl    $4, %r9d
    jne     .Lfail_odd_arguments
    cmpl    $5, 16+32(%rbp)
    jne     .Lfail_odd_arguments
    cmpl    $6, 24+32(%rbp)
    jne     .Lfail_odd_arguments
    cmpl    $7, 32+32(%rbp)
    jne     .Lfail_odd_arguments
    # calculate rsp % 16; should be 0
    movq    %rsp, %rax
    movq    $0, %rdx
    movq    $16, %rcx
    div     %rcx
    # compare result (in rdx) to 0
    cmpq    $0, %rdx
    jne     .Lfail_odd_arguments
    # all checks passed; return 1
    movl    $1, %eax
    popq    %rbp
    retq
    # failure case; exit w/ code -1
.Lfail_odd_arguments:
    # exit w/ code -1
    movl    $-1, %ecx
    call    exit
    popq    %rbp
    retq

