	.file	"lab6.c"
	.text
	.globl	bubble
	.type	bubble, @function
bubble:
.LFB12:
	.cfi_startproc
	leal	-1(%rsi), %r8d
	testl	%r8d, %r8d
	jg	.L8
	rep; ret
.L5:
	movl	(%rax), %edx
	movl	-4(%rax), %ecx
	cmpl	%ecx, %edx
	jge	.L4
	movl	%ecx, (%rax)
	movl	%edx, -4(%rax)
.L4:
	addq	$4, %rax
	cmpq	%rsi, %rax
	jne	.L5
.L6:
	subl	$1, %r8d
	je	.L1
.L8:
	testl	%r8d, %r8d
	jle	.L6
	leaq	4(%rdi), %rax
	leal	-1(%r8), %edx
	leaq	8(%rdi,%rdx,4), %rsi
	jmp	.L5
.L1:
	rep; ret
	.cfi_endproc
.LFE12:
	.size	bubble, .-bubble
	.globl	main
	.type	main, @function
main:
.LFB11:
	.cfi_startproc
	movl	$12, %esi
	movl	$a, %edi
	call	bubble
	rep; ret
	.cfi_endproc
.LFE11:
	.size	main, .-main
	.globl	a
	.data
	.align 32
	.type	a, @object
	.size	a, 48
a:
	.long	35
	.long	33
	.long	16
	.long	13089
	.long	4387
	.long	289
	.long	35
	.long	545
	.long	1059
	.long	4385
	.long	547
	.long	129
	.ident	"GCC: (GNU) 4.9.1"
	.section	.note.GNU-stack,"",@progbits
