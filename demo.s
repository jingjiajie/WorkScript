	.text
	.file	"main"
	.globl	main                    # -- Begin function main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movq	%rsp, %rax
	leaq	-16(%rax), %rdi
	movq	%rdi, %rsp
	movl	$0, -16(%rax)
	callq	_Z1fi
	movq	%rsp, %rax
	leaq	-16(%rax), %rdi
	movq	%rdi, %rsp
	movl	$0, -16(%rax)
	callq	_Z1fi
	movq	%rbp, %rsp
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc
                                        # -- End function
	.globl	_Z1fi                   # -- Begin function _Z1fi
	.p2align	4, 0x90
	.type	_Z1fi,@function
_Z1fi:                                  # @_Z1fi
	.cfi_startproc
# %bb.0:                                # %branch
	pushq	%rbx
	.cfi_def_cfa_offset 16
	subq	$16, %rsp
	.cfi_def_cfa_offset 32
	.cfi_offset %rbx, -16
	movq	%rdi, (%rsp)
	movq	%rsp, %rbx
	movq	%rbx, %rdi
	callq	_Z2f1i4@ref
	movq	%rbx, %rdi
	callq	_Z2f1i4@ref
	addq	$16, %rsp
	.cfi_def_cfa_offset 16
	popq	%rbx
	.cfi_def_cfa_offset 8
	retq
.Lfunc_end1:
	.size	_Z1fi, .Lfunc_end1-_Z1fi
	.cfi_endproc
                                        # -- End function
	.globl	_Z2f1i4@ref             # -- Begin function _Z2f1i4@ref
	.p2align	4, 0x90
	.type	_Z2f1i4@ref,@function
_Z2f1i4@ref:                            # @"_Z2f1i4@ref"
	.cfi_startproc
# %bb.0:                                # %branch
	movq	(%rdi), %rax
	movl	(%rax), %eax
	retq
.Lfunc_end2:
	.size	_Z2f1i4@ref, .Lfunc_end2-_Z2f1i4@ref
	.cfi_endproc
                                        # -- End function

	.section	".note.GNU-stack","",@progbits
