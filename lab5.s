	.file	"lab5.c"
.globl x
	.data
	.align 8
	.type	x, @object
	.size	x, 8
x:
	.quad	100
.globl y
	.align 8
	.type	y, @object
	.size	y, 8
y:
	.quad	200
	.comm	sum,8,8
	.text
.globl main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	$-30, -8(%rbp)
	movq	$50, -16(%rbp)
	movq	x(%rip), %rax
	leaq	-16(%rbp), %rcx
	movq	-8(%rbp), %rdx
	movl	$y, %esi
	movq	%rax, %rdi
	call	add
	movq	%rax, sum(%rip)
	movq	-16(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
.globl add
	.type	add, @function
add:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%rdx, -40(%rbp)
	movq	%rcx, -48(%rbp)
	movq	-32(%rbp), %rax
	movq	(%rax), %rax
	movl	%eax, %edx
	movq	-24(%rbp), %rax
	addl	%eax, %edx
	movq	-40(%rbp), %rax
	subl	%eax, %edx
	movq	-48(%rbp), %rax
	movq	(%rax), %rax
	movl	%edx, %ecx
	subl	%eax, %ecx
	movl	%ecx, %eax
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	cltq
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	add, .-add
	.ident	"GCC: (GNU) 4.4.7 20120313 (Red Hat 4.4.7-18)"
	.section	.note.GNU-stack,"",@progbits
