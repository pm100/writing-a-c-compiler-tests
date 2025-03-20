  bits 64
  default rel
  segment .text
    global even_arguments
even_arguments:
    push    rbp
    mov     rbp, rsp
    ; validate arguments, from 1 to 8
    cmp    edi,1
    jne     .Lfail_even_arguments
    cmp     esi,2
    jne     .Lfail_even_arguments
    cmp    edx,3
    jne     .Lfail_even_arguments
    cmp    ecx,4
    jne     .Lfail_even_arguments
    cmp      r8d,5
    jne     .Lfail_even_arguments
    cmp    r9d,6
    jne     .Lfail_even_arguments
    cmp    dword[16+rbp],7
    jne     .Lfail_even_arguments
    cmp     dword[24+ rbp],8
    jne     .Lfail_even_arguments
    ;# calculate rsp   16; should be 0
    mov     rsp,  rax
    mov    rdx,0
    mov      rcx,16
    div      rcx
    ;# compare result (in rdx) to 0
    cmp      rdx,0
    jne     .Lfail_even_arguments
    ;# all checks passed; return 1
    mov      eax,1
    pop     rbp
    ret
    ;# failure case; exit w/ code -1
.Lfail_even_arguments:
    ;# exit w/ code -1
    mov     edi,-1
    ;call    exit@PLT
    pop     rbp
    ret
    global odd_arguments
odd_arguments:
    push    rbp
    mov     rbp,rsp
    ;# validate arguments, from 1 to 7
    cmp    edi,1
    jne     .Lfail_odd_arguments
    cmp      esi,2
    jne     .Lfail_odd_arguments
    cmp      edx,3
    jne     .Lfail_odd_arguments
    cmp     ecx,4
    jne     .Lfail_odd_arguments
    cmp      r8d,5
    jne     .Lfail_odd_arguments
    cmp      r9d,6
    jne     .Lfail_odd_arguments
    cmp    dword [16+ rbp],7
    jne     .Lfail_odd_arguments
    ;# calculate rsp   16; should be 0
    mov      rax,rsp
    mov    rdx,0
    mov    rcx,16
    div      rcx
    ;# compare result (in rdx) to 0
    cmp     rdx,0
    jne     .Lfail_odd_arguments
    ;# all checks passed; return 1
    mov      eax,1
    pop     rbp
    ret
    ;# failure case; exit w/ code -1
.Lfail_odd_arguments:
    ;# exit w/ code -1
    mov     edi,-1
;/call    exit@PLT
    pop     rbp
    ret
;	.section	".note.GNU-stack","",@progbits
