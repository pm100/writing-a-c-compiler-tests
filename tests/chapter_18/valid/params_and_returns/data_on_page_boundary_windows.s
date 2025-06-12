

   segment .bss
    align 4096
    resb 4086
    global on_page_boundary
on_page_boundary:
    resb 10