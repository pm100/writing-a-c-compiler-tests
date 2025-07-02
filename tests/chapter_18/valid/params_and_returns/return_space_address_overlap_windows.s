	# validate that space allocated for return address does not overlap
	# with storage for other objects we can access from callee (this is an ABI requirement)
	# case 1: overlap w/ global variable
	.data
	.globl globvar
	.align 8
globvar:
	.zero 24
	.text
	# globvar = overlap_with_globvar()
	.globl overlap_with_globvar
overlap_with_globvar:
	# load address of globvar into RSI
	leaq	globvar(%rip),	%rsi
	# make sure return address (in RDI) and globvar's address (in RSI)
	# are at least 24 bytes apart
	subq	%rcx, %rsi
	# get absolute value of difference between addresses (in RSI)
	# (absolute value implementation from https://stackoverflow.com/a/11927940)
	movq	%rsi, %r10	# copy RSI into RCX
	negq	%rsi	# negate RSI
	## if RSI is now negative, its restore original (positive) value
	cmovl	%r10, %rsi
	# compare diference to 24
	cmpq	$24, %rsi
	jl	.Loverlap_detected
	# no overlap, so go ahead and return value
	movq	$400, (%rcx)
	movq	$500, 8(%rcx)
	movq	$600, 16(%rcx)
	movq	%rcx, %rax
	ret
.Loverlap_detected:
	# space for return value overlaps w/ globvar, so exit with error code
	movl	$1, %ecx
	call	exit

	# case 2: overlap w/ pointer passed as arg
	# x = overlap_with_pointer(&x)
	.globl	overlap_with_pointer
overlap_with_pointer:
	# copy pointer into RDX
	leaq	globvar(%rip), %r9
	# make sure return address (in RDI) and globvar's address (in RDX)
	# are at least 24 bytes apart
	subq	%rdx, %r9
	# get absolute value of difference between addresses (in RDX)
	# (absolute value implementation from https://stackoverflow.com/a/11927940)
	movq	%r9, %r10	# copy RDX into RCX
	negq	%r9			# negate RDX
	## if rdx is now negative, its restore original (positive) value
	cmovl	%r10, %r9
	# compare diference to 24
	cmpq	$24, %r9
	jl	.Loverlap_detected.0
	# no overlap, so go ahead and return value
	# set each member to twice its original value (accessed thru RSI)
	# l1
	movq	(%rdx), %r10
	imul	$2, %r10
	movq	%r10, (%rcx)
	# l2
	movq	8(%rdx), %r10
	imul	$2, %r10
	movq	%r10, 8(%rcx)
	# l3
	movq	16(%rdx), %r10
	imul	$2, %r10
	movq	%r10, 16(%rcx)
	movq	%rcx, %rax
	ret
.Loverlap_detected.0:
	# space for return value overlaps w/ space pointed to by argument, so exit with error code
	movl	$3, %ecx
	call	exit

