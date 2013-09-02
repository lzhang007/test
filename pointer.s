	.file	"pointer.c"
	.section	.rodata.str1.4,"aMS",@progbits,1
	.align 4
.LC0:
	.string	"ptr1 = %p,*ptr1 = %d,&ptr1 = %p\n"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC1:
	.string	"ptr2 = %p,ptr1 + 4 = %p\n"
.LC2:
	.string	"ptr3 - ptr1 = %d\n"
.LC3:
	.string	"*ptr3 + *ptr1 = %d\n"
	.text
.globl main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	pushl	%ebx
	subl	$76, %esp
	movl	$0, 56(%esp)
	movl	$100, 40(%esp)
	movl	$200, 44(%esp)
	movl	$300, 48(%esp)
	movl	$400, 52(%esp)
	leal	40(%esp), %eax
	movl	%eax, 60(%esp)
	leal	60(%esp), %edx
	movl	%edx, 16(%esp)
	movl	$100, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$.LC0, 4(%esp)
	movl	$1, (%esp)
	call	__printf_chk
	movl	60(%esp), %ebx
	addl	$16, %ebx
	movl	%ebx, 12(%esp)
	leal	48(%esp), %eax
	movl	%eax, 8(%esp)
	movl	$.LC1, 4(%esp)
	movl	$1, (%esp)
	call	__printf_chk
	movl	%ebx, %eax
	subl	60(%esp), %eax
	sarl	$2, %eax
	movl	%eax, 8(%esp)
	movl	$.LC2, 4(%esp)
	movl	$1, (%esp)
	call	__printf_chk
	movl	(%ebx), %eax
	movl	60(%esp), %edx
	addl	(%edx), %eax
	movl	%eax, 8(%esp)
	movl	$.LC3, 4(%esp)
	movl	$1, (%esp)
	call	__printf_chk
	movl	$0, %eax
	addl	$76, %esp
	popl	%ebx
	movl	%ebp, %esp
	popl	%ebp
	ret
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.4.3-4ubuntu5) 4.4.3"
	.section	.note.GNU-stack,"",@progbits
