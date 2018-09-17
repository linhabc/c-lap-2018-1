	.file	"qsort.c"
# GNU C11 (Ubuntu 5.4.0-6ubuntu1~16.04.10) version 5.4.0 20160609 (x86_64-linux-gnu)
#	compiled by GNU C version 5.4.0 20160609, GMP version 6.1.0, MPFR version 3.1.4, MPC version 1.0.3
# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
# options passed:  -imultiarch x86_64-linux-gnu qsort.c -mtune=generic
# -march=x86-64 -O2 -fverbose-asm -fstack-protector-strong -Wformat
# -Wformat-security
# options enabled:  -faggressive-loop-optimizations -falign-labels
# -fasynchronous-unwind-tables -fauto-inc-dec -fbranch-count-reg
# -fcaller-saves -fchkp-check-incomplete-type -fchkp-check-read
# -fchkp-check-write -fchkp-instrument-calls -fchkp-narrow-bounds
# -fchkp-optimize -fchkp-store-bounds -fchkp-use-static-bounds
# -fchkp-use-static-const-bounds -fchkp-use-wrappers
# -fcombine-stack-adjustments -fcommon -fcompare-elim -fcprop-registers
# -fcrossjumping -fcse-follow-jumps -fdefer-pop
# -fdelete-null-pointer-checks -fdevirtualize -fdevirtualize-speculatively
# -fdwarf2-cfi-asm -fearly-inlining -feliminate-unused-debug-types
# -fexpensive-optimizations -fforward-propagate -ffunction-cse -fgcse
# -fgcse-lm -fgnu-runtime -fgnu-unique -fguess-branch-probability
# -fhoist-adjacent-loads -fident -fif-conversion -fif-conversion2
# -findirect-inlining -finline -finline-atomics
# -finline-functions-called-once -finline-small-functions -fipa-cp
# -fipa-cp-alignment -fipa-icf -fipa-icf-functions -fipa-icf-variables
# -fipa-profile -fipa-pure-const -fipa-ra -fipa-reference -fipa-sra
# -fira-hoist-pressure -fira-share-save-slots -fira-share-spill-slots
# -fisolate-erroneous-paths-dereference -fivopts -fkeep-static-consts
# -fleading-underscore -flifetime-dse -flra-remat -flto-odr-type-merging
# -fmath-errno -fmerge-constants -fmerge-debug-strings
# -fmove-loop-invariants -fomit-frame-pointer -foptimize-sibling-calls
# -foptimize-strlen -fpartial-inlining -fpeephole -fpeephole2
# -fprefetch-loop-arrays -free -freg-struct-return -freorder-blocks
# -freorder-blocks-and-partition -freorder-functions -frerun-cse-after-loop
# -fsched-critical-path-heuristic -fsched-dep-count-heuristic
# -fsched-group-heuristic -fsched-interblock -fsched-last-insn-heuristic
# -fsched-rank-heuristic -fsched-spec -fsched-spec-insn-heuristic
# -fsched-stalled-insns-dep -fschedule-fusion -fschedule-insns2
# -fsemantic-interposition -fshow-column -fshrink-wrap -fsigned-zeros
# -fsplit-ivs-in-unroller -fsplit-wide-types -fssa-phiopt
# -fstack-protector-strong -fstdarg-opt -fstrict-aliasing -fstrict-overflow
# -fstrict-volatile-bitfields -fsync-libcalls -fthread-jumps
# -ftoplevel-reorder -ftrapping-math -ftree-bit-ccp -ftree-builtin-call-dce
# -ftree-ccp -ftree-ch -ftree-coalesce-vars -ftree-copy-prop
# -ftree-copyrename -ftree-cselim -ftree-dce -ftree-dominator-opts
# -ftree-dse -ftree-forwprop -ftree-fre -ftree-loop-if-convert
# -ftree-loop-im -ftree-loop-ivcanon -ftree-loop-optimize
# -ftree-parallelize-loops= -ftree-phiprop -ftree-pre -ftree-pta
# -ftree-reassoc -ftree-scev-cprop -ftree-sink -ftree-slsr -ftree-sra
# -ftree-switch-conversion -ftree-tail-merge -ftree-ter -ftree-vrp
# -funit-at-a-time -funwind-tables -fverbose-asm -fzero-initialized-in-bss
# -m128bit-long-double -m64 -m80387 -malign-stringops
# -mavx256-split-unaligned-load -mavx256-split-unaligned-store
# -mfancy-math-387 -mfp-ret-in-387 -mfxsr -mglibc -mieee-fp
# -mlong-double-80 -mmmx -mno-sse4 -mpush-args -mred-zone -msse -msse2
# -mtls-direct-seg-refs -mvzeroupper

	.section	.text.unlikely,"ax",@progbits
.LCOLDB0:
	.text
.LHOTB0:
	.p2align 4,,15
	.globl	cmpInt
	.type	cmpInt, @function
cmpInt:
.LFB69:
	.cfi_startproc
	movl	(%rdi), %eax	# MEM[(int *)a_2(D)], MEM[(int *)a_2(D)]
	subl	(%rsi), %eax	# MEM[(int *)b_4(D)], D.3956
	ret
	.cfi_endproc
.LFE69:
	.size	cmpInt, .-cmpInt
	.section	.text.unlikely
.LCOLDE0:
	.text
.LHOTE0:
	.section	.text.unlikely
.LCOLDB1:
	.text
.LHOTB1:
	.p2align 4,,15
	.globl	swap
	.type	swap, @function
swap:
.LFB60:
	.cfi_startproc
	pushq	%r13	#
	.cfi_def_cfa_offset 16
	.cfi_offset 13, -16
	pushq	%r12	#
	.cfi_def_cfa_offset 24
	.cfi_offset 12, -24
	movq	%rdi, %r13	# a, a
	pushq	%rbp	#
	.cfi_def_cfa_offset 32
	.cfi_offset 6, -32
	pushq	%rbx	#
	.cfi_def_cfa_offset 40
	.cfi_offset 3, -40
	movq	%rdx, %rdi	# elementSize,
	movq	%rdx, %rbx	# elementSize, elementSize
	movq	%rsi, %r12	# b, b
	subq	$8, %rsp	#,
	.cfi_def_cfa_offset 48
	call	malloc	#
	movq	%rbx, %rdx	# elementSize,
	movq	%r13, %rsi	# a,
	movq	%rax, %rdi	# tmp91,
	movq	%rax, %rbp	#, tmp91
	call	memcpy	#
	movq	%rbx, %rdx	# elementSize,
	movq	%r12, %rsi	# b,
	movq	%r13, %rdi	# a,
	call	memcpy	#
	movq	%r12, %rdi	# b,
	movq	%rbx, %rdx	# elementSize,
	movq	%rbp, %rsi	# tmp91,
	call	memcpy	#
	addq	$8, %rsp	#,
	.cfi_def_cfa_offset 40
	movq	%rbp, %rdi	# tmp91,
	popq	%rbx	#
	.cfi_def_cfa_offset 32
	popq	%rbp	#
	.cfi_def_cfa_offset 24
	popq	%r12	#
	.cfi_def_cfa_offset 16
	popq	%r13	#
	.cfi_def_cfa_offset 8
	jmp	free	#
	.cfi_endproc
.LFE60:
	.size	swap, .-swap
	.section	.text.unlikely
.LCOLDE1:
	.text
.LHOTE1:
	.section	.text.unlikely
.LCOLDB2:
	.text
.LHOTB2:
	.p2align 4,,15
	.globl	partition_two_way
	.type	partition_two_way, @function
partition_two_way:
.LFB61:
	.cfi_startproc
	movl	%edx, %eax	# high, D.3982
	pushq	%r15	#
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14	#
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	imull	%ecx, %eax	# size, D.3982
	pushq	%r13	#
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12	#
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp	#
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx	#
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	movl	%esi, %r14d	# low, low
	movl	%ecx, %r12d	# size, size
	cltq
	subq	$56, %rsp	#,
	.cfi_def_cfa_offset 112
	addq	%rdi, %rax	# arr, ptr_p
	cmpl	%esi, %edx	# low, high
	movq	%rdi, 16(%rsp)	# arr, %sfp
	movl	%edx, 36(%rsp)	# high, %sfp
	movq	%r8, 40(%rsp)	# cmp, %sfp
	movq	%rax, 24(%rsp)	# ptr_p, %sfp
	jle	.L13	#,
	movslq	%ecx, %rax	# size, D.3984
	movl	%esi, %ecx	# low, D.3982
	movl	%esi, %r13d	# low, low
	imull	%r12d, %ecx	# size, D.3982
	movq	%rax, 8(%rsp)	# D.3984, %sfp
	movq	16(%rsp), %rax	# %sfp, arr
	movslq	%ecx, %rcx	# D.3982, D.3981
	leaq	(%rax,%rcx), %r15	#, ivtmp.37
	jmp	.L8	#
	.p2align 4,,10
	.p2align 3
.L7:
	addl	$1, %r14d	#, low
	addq	8(%rsp), %r15	# %sfp, ivtmp.37
	cmpl	%r14d, 36(%rsp)	# low, %sfp
	je	.L6	#,
.L8:
	movl	%r12d, %ebp	# size, D.3982
	movq	24(%rsp), %rsi	# %sfp,
	movq	%r15, %rdi	# ivtmp.37,
	imull	%r13d, %ebp	# low, D.3982
	movq	40(%rsp), %rax	# %sfp, cmp
	movslq	%ebp, %rbx	# D.3982, D.3981
	addq	16(%rsp), %rbx	# %sfp, ptr_firsthing
	call	*%rax	# cmp
	testl	%eax, %eax	# D.3982
	movq	%rbx, %rsi	# ptr_firsthing, D.3983
	jns	.L7	#,
	movq	8(%rsp), %rdx	# %sfp,
	movq	%r15, %rdi	# ivtmp.37,
	addl	$1, %r13d	#, low
	addl	$1, %r14d	#, low
	leal	(%r12,%rbp), %ebx	#, D.3982
	call	swap	#
	addq	8(%rsp), %r15	# %sfp, ivtmp.37
	cmpl	%r14d, 36(%rsp)	# low, %sfp
	movslq	%ebx, %rbx	# D.3982, D.3981
	movq	16(%rsp), %rax	# %sfp, arr
	leaq	(%rax,%rbx), %rsi	#, D.3983
	jne	.L8	#,
.L6:
	movq	8(%rsp), %rdx	# %sfp,
	movq	24(%rsp), %rdi	# %sfp,
	call	swap	#
	addq	$56, %rsp	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	movl	%r13d, %eax	# low,
	popq	%rbx	#
	.cfi_def_cfa_offset 48
	popq	%rbp	#
	.cfi_def_cfa_offset 40
	popq	%r12	#
	.cfi_def_cfa_offset 32
	popq	%r13	#
	.cfi_def_cfa_offset 24
	popq	%r14	#
	.cfi_def_cfa_offset 16
	popq	%r15	#
	.cfi_def_cfa_offset 8
	ret
.L13:
	.cfi_restore_state
	movslq	%r12d, %rax	# size, D.3984
	movl	%r14d, %r13d	# low, low
	imull	%esi, %r12d	# low, D.3982
	movq	%rdi, %rsi	# arr, D.3983
	movq	%rax, 8(%rsp)	# D.3984, %sfp
	movslq	%r12d, %rbx	# D.3982, D.3981
	addq	%rbx, %rsi	# D.3981, D.3983
	jmp	.L6	#
	.cfi_endproc
.LFE61:
	.size	partition_two_way, .-partition_two_way
	.section	.text.unlikely
.LCOLDE2:
	.text
.LHOTE2:
	.section	.text.unlikely
.LCOLDB3:
	.text
.LHOTB3:
	.p2align 4,,15
	.globl	quick_sort_two_way
	.type	quick_sort_two_way, @function
quick_sort_two_way:
.LFB62:
	.cfi_startproc
	cmpl	%edx, %esi	# high, low
	jge	.L22	#,
	pushq	%r15	#
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14	#
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	movq	%rdi, %r15	# arr, arr
	pushq	%r13	#
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12	#
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	movl	%ecx, %r14d	# size, size
	pushq	%rbp	#
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx	#
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	movl	%edx, %r12d	# high, high
	movl	%esi, %ebx	# low, low
	movq	%r8, %r13	# cmp, cmp
	subq	$8, %rsp	#,
	.cfi_def_cfa_offset 64
	.p2align 4,,10
	.p2align 3
.L18:
	movl	%ebx, %esi	# low,
	movq	%r13, %r8	# cmp,
	movl	%r14d, %ecx	# size,
	movl	%r12d, %edx	# high,
	movq	%r15, %rdi	# arr,
	call	partition_two_way	#
	movl	%eax, %ebp	#, p
	movl	%ebx, %esi	# low,
	leal	-1(%rax), %edx	#, D.3988
	leal	1(%rbp), %ebx	#, low
	movq	%r13, %r8	# cmp,
	movl	%r14d, %ecx	# size,
	movq	%r15, %rdi	# arr,
	call	quick_sort_two_way	#
	cmpl	%r12d, %ebx	# high, low
	jl	.L18	#,
	addq	$8, %rsp	#,
	.cfi_def_cfa_offset 56
	popq	%rbx	#
	.cfi_restore 3
	.cfi_def_cfa_offset 48
	popq	%rbp	#
	.cfi_restore 6
	.cfi_def_cfa_offset 40
	popq	%r12	#
	.cfi_restore 12
	.cfi_def_cfa_offset 32
	popq	%r13	#
	.cfi_restore 13
	.cfi_def_cfa_offset 24
	popq	%r14	#
	.cfi_restore 14
	.cfi_def_cfa_offset 16
	popq	%r15	#
	.cfi_restore 15
	.cfi_def_cfa_offset 8
.L22:
	rep ret
	.cfi_endproc
.LFE62:
	.size	quick_sort_two_way, .-quick_sort_two_way
	.section	.text.unlikely
.LCOLDE3:
	.text
.LHOTE3:
	.section	.text.unlikely
.LCOLDB4:
	.text
.LHOTB4:
	.p2align 4,,15
	.globl	partition_three_way
	.type	partition_three_way, @function
partition_three_way:
.LFB63:
	.cfi_startproc
	pushq	%r15	#
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	movl	%edx, %eax	# high, D.3993
	pushq	%r14	#
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13	#
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12	#
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	subl	%esi, %eax	# low, D.3993
	pushq	%rbp	#
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx	#
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	movl	%esi, %ebp	# low, low
	movl	%edx, %r12d	# high, high
	movl	%r9d, %r15d	# size, size
	subq	$56, %rsp	#,
	.cfi_def_cfa_offset 112
	cmpl	$1, %eax	#, D.3993
	movq	%rdi, 8(%rsp)	# arr, %sfp
	movq	%rcx, 24(%rsp)	# i, %sfp
	movq	%r8, 32(%rsp)	# j, %sfp
	movq	112(%rsp), %r14	# cmp, cmp
	jle	.L35	#,
	movslq	%r9d, %rax	# size, D.3995
	movq	%rax, %rdi	# D.3995,
	movq	%rax, %rbx	# D.3995, D.3995
	movq	%rax, 16(%rsp)	# D.3995, %sfp
	call	malloc	#
	movl	%r12d, %esi	# high, D.3993
	movq	%rbx, %rdx	# D.3995,
	movq	%rax, %rdi	# ptr_pivot,
	imull	%r15d, %esi	# size, D.3993
	movq	%rax, %r13	#, ptr_pivot
	movslq	%esi, %rsi	# D.3993, D.3994
	addq	8(%rsp), %rsi	# %sfp, ptr_high
	call	memcpy	#
	cmpl	%ebp, %r12d	# low, high
	movl	%ebp, 40(%rsp)	# low, %sfp
	jge	.L31	#,
	jmp	.L27	#
	.p2align 4,,10
	.p2align 3
.L28:
	movq	%r13, %rsi	# ptr_pivot,
	movq	%rbx, %rdi	# ptr_mid,
	call	*%r14	# cmp
	testl	%eax, %eax	# D.3993
	jne	.L30	#,
	addl	$1, %ebp	#, low
.L29:
	cmpl	%r12d, %ebp	# high, low
	jg	.L27	#,
.L31:
	movl	%r15d, %ebx	# size, D.3993
	movq	%r13, %rsi	# ptr_pivot,
	imull	%ebp, %ebx	# low, D.3993
	movslq	%ebx, %rbx	# D.3993, D.3994
	addq	8(%rsp), %rbx	# %sfp, ptr_mid
	movq	%rbx, %rdi	# ptr_mid,
	call	*%r14	# cmp
	testl	%eax, %eax	# D.3993
	jns	.L28	#,
	movl	40(%rsp), %eax	# %sfp, low
	movq	16(%rsp), %rdx	# %sfp,
	addl	$1, %ebp	#, low
	movq	%rbx, %rsi	# ptr_mid,
	movl	%eax, %edi	# low, D.3993
	leal	1(%rax), %ecx	#, low
	imull	%r15d, %edi	# size, D.3993
	movl	%ecx, 40(%rsp)	# low, %sfp
	movslq	%edi, %rdi	# D.3993, D.3994
	addq	8(%rsp), %rdi	# %sfp, ptr_low
	call	swap	#
	cmpl	%r12d, %ebp	# high, low
	jle	.L31	#,
.L27:
	movl	40(%rsp), %eax	# %sfp, tmp147
	movq	24(%rsp), %rdx	# %sfp, i
	subl	$1, %eax	#, tmp147
	movl	%eax, (%rdx)	# tmp147, *i_24(D)
	movq	32(%rsp), %rax	# %sfp, j
	movl	%ebp, (%rax)	# low, *j_26(D)
	addq	$56, %rsp	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	popq	%rbx	#
	.cfi_def_cfa_offset 48
	popq	%rbp	#
	.cfi_def_cfa_offset 40
	popq	%r12	#
	.cfi_def_cfa_offset 32
	popq	%r13	#
	.cfi_def_cfa_offset 24
	popq	%r14	#
	.cfi_def_cfa_offset 16
	popq	%r15	#
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L30:
	.cfi_restore_state
	movq	%r13, %rsi	# ptr_pivot,
	movq	%rbx, %rdi	# ptr_mid,
	call	*%r14	# cmp
	testl	%eax, %eax	# D.3993
	jle	.L29	#,
	leal	-1(%r12), %eax	#, high
	movq	16(%rsp), %rdx	# %sfp,
	movq	%rbx, %rdi	# ptr_mid,
	imull	%r15d, %r12d	# size, D.3993
	movl	%eax, 44(%rsp)	# high, %sfp
	movslq	%r12d, %rsi	# D.3993, D.3994
	addq	8(%rsp), %rsi	# %sfp, ptr_high
	call	swap	#
	movl	44(%rsp), %r12d	# %sfp, high
	jmp	.L29	#
	.p2align 4,,10
	.p2align 3
.L35:
	movl	%edx, %r13d	# high, D.3993
	movl	%esi, %ebx	# low, D.3993
	imull	%r9d, %r13d	# size, D.3993
	imull	%r9d, %ebx	# size, D.3993
	movslq	%r13d, %r13	# D.3993, D.3994
	movslq	%ebx, %rbx	# D.3993, D.3994
	addq	%rdi, %r13	# arr, ptr_high
	addq	%rdi, %rbx	# arr, ptr_low
	movq	%r13, %rdi	# ptr_high,
	movq	%rbx, %rsi	# ptr_low,
	call	*%r14	# cmp
	testl	%eax, %eax	# D.3993
	js	.L36	#,
.L25:
	movq	24(%rsp), %rax	# %sfp, i
	movl	%ebp, (%rax)	# low, *i_24(D)
	movq	32(%rsp), %rax	# %sfp, j
	movl	%r12d, (%rax)	# high, *j_26(D)
	addq	$56, %rsp	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	popq	%rbx	#
	.cfi_def_cfa_offset 48
	popq	%rbp	#
	.cfi_def_cfa_offset 40
	popq	%r12	#
	.cfi_def_cfa_offset 32
	popq	%r13	#
	.cfi_def_cfa_offset 24
	popq	%r14	#
	.cfi_def_cfa_offset 16
	popq	%r15	#
	.cfi_def_cfa_offset 8
	ret
.L36:
	.cfi_restore_state
	movslq	%r15d, %rdx	# size, D.3995
	movq	%rbx, %rsi	# ptr_low,
	movq	%r13, %rdi	# ptr_high,
	call	swap	#
	jmp	.L25	#
	.cfi_endproc
.LFE63:
	.size	partition_three_way, .-partition_three_way
	.section	.text.unlikely
.LCOLDE4:
	.text
.LHOTE4:
	.section	.text.unlikely
.LCOLDB5:
	.text
.LHOTB5:
	.p2align 4,,15
	.globl	quick_sort_three_way
	.type	quick_sort_three_way, @function
quick_sort_three_way:
.LFB64:
	.cfi_startproc
	pushq	%r14	#
	.cfi_def_cfa_offset 16
	.cfi_offset 14, -16
	pushq	%r13	#
	.cfi_def_cfa_offset 24
	.cfi_offset 13, -24
	pushq	%r12	#
	.cfi_def_cfa_offset 32
	.cfi_offset 12, -32
	pushq	%rbp	#
	.cfi_def_cfa_offset 40
	.cfi_offset 6, -40
	pushq	%rbx	#
	.cfi_def_cfa_offset 48
	.cfi_offset 3, -48
	subq	$16, %rsp	#,
	.cfi_def_cfa_offset 64
	movq	%fs:40, %rax	#, tmp98
	movq	%rax, 8(%rsp)	# tmp98, D.4009
	xorl	%eax, %eax	# tmp98
	cmpl	%edx, %esi	# high, low
	jl	.L41	#,
.L37:
	movq	8(%rsp), %rax	# D.4009, tmp99
	xorq	%fs:40, %rax	#, tmp99
	jne	.L42	#,
	addq	$16, %rsp	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 48
	popq	%rbx	#
	.cfi_def_cfa_offset 40
	popq	%rbp	#
	.cfi_def_cfa_offset 32
	popq	%r12	#
	.cfi_def_cfa_offset 24
	popq	%r13	#
	.cfi_def_cfa_offset 16
	popq	%r14	#
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L41:
	.cfi_restore_state
	subq	$8, %rsp	#,
	.cfi_def_cfa_offset 72
	movl	%ecx, %r9d	# size,
	movl	%ecx, %r13d	# size, size
	pushq	%r8	# cmp
	.cfi_def_cfa_offset 80
	movq	%r8, %r14	# cmp, cmp
	movq	%rdi, %r12	# arr, arr
	movl	%edx, %ebx	# high, high
	movl	%esi, %ebp	# low, low
	leaq	20(%rsp), %r8	#,
	leaq	16(%rsp), %rcx	#, tmp100
	call	partition_three_way	#
	movl	16(%rsp), %edx	# i,
	movq	%r14, %r8	# cmp,
	movl	%r13d, %ecx	# size,
	movl	%ebp, %esi	# low,
	movq	%r12, %rdi	# arr,
	call	quick_sort_three_way	#
	movl	20(%rsp), %esi	# j,
	movl	%ebx, %edx	# high,
	movq	%r14, %r8	# cmp,
	movl	%r13d, %ecx	# size,
	movq	%r12, %rdi	# arr,
	call	quick_sort_three_way	#
	popq	%rax	#
	.cfi_def_cfa_offset 72
	popq	%rdx	#
	.cfi_def_cfa_offset 64
	jmp	.L37	#
.L42:
	call	__stack_chk_fail	#
	.cfi_endproc
.LFE64:
	.size	quick_sort_three_way, .-quick_sort_three_way
	.section	.text.unlikely
.LCOLDE5:
	.text
.LHOTE5:
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC6:
	.string	"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC7:
	.string	"No memory"
	.section	.text.unlikely
.LCOLDB8:
	.text
.LHOTB8:
	.p2align 4,,15
	.globl	randString
	.type	randString, @function
randString:
.LFB65:
	.cfi_startproc
	pushq	%r14	#
	.cfi_def_cfa_offset 16
	.cfi_offset 14, -16
	pushq	%r13	#
	.cfi_def_cfa_offset 24
	.cfi_offset 13, -24
	pushq	%r12	#
	.cfi_def_cfa_offset 32
	.cfi_offset 12, -32
	pushq	%rbp	#
	.cfi_def_cfa_offset 40
	.cfi_offset 6, -40
	movslq	%edi, %r12	# length,
	pushq	%rbx	#
	.cfi_def_cfa_offset 48
	.cfi_offset 3, -48
	xorl	%edi, %edi	#
	call	time	#
	movl	mySeed.3686(%rip), %esi	# mySeed, tmp153
	imull	%r12d, %eax	# length, D.4023
	leal	1(%rsi), %edx	#, D.4020
	leal	(%rax,%rdx), %edi	#, D.4023
	movl	%edx, mySeed.3686(%rip)	# D.4020, mySeed
	call	srand	#
	testl	%r12d, %r12d	# length
	jle	.L47	#,
	leal	1(%r12), %edi	#, D.4020
	movslq	%edi, %rdi	# D.4020, D.4021
.L44:
	call	malloc	#
	testq	%rax, %rax	# randomString
	movq	%rax, %r13	#, randomString
	je	.L45	#,
	movq	%rax, %r14	# randomString, ivtmp.51
	leal	-1(%r12), %eax	#, D.4025
	movabsq	$5675921253449092805, %rbx	#, tmp151
	leaq	1(%r13,%rax), %rbp	#, D.4029
	.p2align 4,,10
	.p2align 3
.L46:
	call	rand	#
	movslq	%eax, %rcx	# D.4020, D.4021
	addq	$1, %r14	#, ivtmp.51
	movq	%rcx, %rax	# D.4021, tmp152
	mulq	%rbx	# tmp151
	shrq	$4, %rdx	#, tmp137
	leaq	(%rdx,%rdx,2), %rax	#, tmp142
	leaq	(%rdx,%rax,4), %rax	#, tmp144
	salq	$2, %rax	#, tmp145
	subq	%rax, %rcx	# tmp145, D.4021
	movzbl	.LC6(%rcx), %eax	# *_30, *_30
	movb	%al, -1(%r14)	# *_30, MEM[base: _39, offset: 0B]
	cmpq	%rbp, %r14	# D.4029, ivtmp.51
	jne	.L46	#,
	popq	%rbx	#
	.cfi_remember_state
	.cfi_def_cfa_offset 40
	movb	$0, 0(%r13,%r12)	#, *_35
	movq	%r13, %rax	# randomString,
	popq	%rbp	#
	.cfi_def_cfa_offset 32
	popq	%r12	#
	.cfi_def_cfa_offset 24
	popq	%r13	#
	.cfi_def_cfa_offset 16
	popq	%r14	#
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L47:
	.cfi_restore_state
	movl	$2, %edi	#, D.4021
	movl	$1, %r12d	#,
	jmp	.L44	#
.L45:
	movl	$1, %edi	#,
	movl	$.LC7, %esi	#,
	xorl	%eax, %eax	#
	call	__printf_chk	#
	movl	$1, %edi	#,
	call	exit	#
	.cfi_endproc
.LFE65:
	.size	randString, .-randString
	.section	.text.unlikely
.LCOLDE8:
	.text
.LHOTE8:
	.section	.text.unlikely
.LCOLDB9:
	.text
.LHOTB9:
	.p2align 4,,15
	.globl	randPhoneNumber
	.type	randPhoneNumber, @function
randPhoneNumber:
.LFB66:
	.cfi_startproc
	pushq	%r13	#
	.cfi_def_cfa_offset 16
	.cfi_offset 13, -16
	pushq	%r12	#
	.cfi_def_cfa_offset 24
	.cfi_offset 12, -24
	pushq	%rbp	#
	.cfi_def_cfa_offset 32
	.cfi_offset 6, -32
	pushq	%rbx	#
	.cfi_def_cfa_offset 40
	.cfi_offset 3, -40
	movl	%edi, %ebx	# length, length
	xorl	%edi, %edi	#
	subq	$8, %rsp	#,
	.cfi_def_cfa_offset 48
	call	time	#
	movl	mySeed.3698(%rip), %esi	# mySeed, tmp140
	imull	%ebx, %eax	# length, D.4043
	leal	1(%rsi), %edx	#, D.4044
	leal	(%rax,%rdx), %edi	#, D.4043
	movl	%edx, mySeed.3698(%rip)	# D.4044, mySeed
	call	srand	#
	movslq	%ebx, %rdi	# length, D.4045
	call	malloc	#
	cmpl	$1, %ebx	#, length
	movq	%rax, %r12	#, phoneNumber
	movb	$48, (%rax)	#, *phoneNumber_18
	jle	.L58	#,
	leaq	1(%rax), %r13	#, ivtmp.58
	leal	-2(%rbx), %eax	#, D.4051
	movl	$1717986919, %ebx	#, tmp138
	leaq	2(%r12,%rax), %rbp	#, D.4052
	.p2align 4,,10
	.p2align 3
.L55:
	call	rand	#
	movl	%eax, %ecx	#, D.4044
	addq	$1, %r13	#, ivtmp.58
	imull	%ebx	# tmp138
	movl	%ecx, %eax	# D.4044, tmp131
	sarl	$31, %eax	#, tmp131
	sarl	$2, %edx	#, tmp130
	subl	%eax, %edx	# tmp131, tmp127
	leal	(%rdx,%rdx,4), %eax	#, tmp134
	addl	%eax, %eax	# tmp135
	subl	%eax, %ecx	# tmp135, randNum
	addl	$48, %ecx	#, tmp137
	movb	%cl, -1(%r13)	# tmp137, MEM[base: _36, offset: 0B]
	cmpq	%rbp, %r13	# D.4052, ivtmp.58
	jne	.L55	#,
.L58:
	addq	$8, %rsp	#,
	.cfi_def_cfa_offset 40
	movq	%r12, %rax	# phoneNumber,
	popq	%rbx	#
	.cfi_def_cfa_offset 32
	popq	%rbp	#
	.cfi_def_cfa_offset 24
	popq	%r12	#
	.cfi_def_cfa_offset 16
	popq	%r13	#
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE66:
	.size	randPhoneNumber, .-randPhoneNumber
	.section	.text.unlikely
.LCOLDE9:
	.text
.LHOTE9:
	.section	.text.unlikely
.LCOLDB10:
	.text
.LHOTB10:
	.p2align 4,,15
	.globl	generateRandArray
	.type	generateRandArray, @function
generateRandArray:
.LFB67:
	.cfi_startproc
	pushq	%r12	#
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	movslq	%edi, %rdi	# nmemb,
	pushq	%rbp	#
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	pushq	%rbx	#
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
	movq	%rdi, %rbp	#,
	salq	$2, %rdi	#, D.4062
	call	malloc	#
	xorl	%edi, %edi	#
	movq	%rax, %r12	#, arr
	call	time	#
	movl	%eax, %edi	# D.4063,
	call	srand	#
	testl	%ebp, %ebp	# nmemb
	jle	.L65	#,
	leal	-1(%rbp), %eax	#, D.4068
	movq	%r12, %rbx	# arr, ivtmp.65
	leaq	4(%r12,%rax,4), %rbp	#, D.4070
	.p2align 4,,10
	.p2align 3
.L62:
	call	rand	#
	addq	$4, %rbx	#, ivtmp.65
	movl	%eax, -4(%rbx)	# D.4065, MEM[base: _20, offset: 0B]
	cmpq	%rbp, %rbx	# D.4070, ivtmp.65
	jne	.L62	#,
.L65:
	movq	%r12, %rax	# arr,
	popq	%rbx	#
	.cfi_def_cfa_offset 24
	popq	%rbp	#
	.cfi_def_cfa_offset 16
	popq	%r12	#
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE67:
	.size	generateRandArray, .-generateRandArray
	.section	.text.unlikely
.LCOLDE10:
	.text
.LHOTE10:
	.section	.rodata.str1.1
.LC11:
	.string	"%d "
	.section	.text.unlikely
.LCOLDB12:
	.text
.LHOTB12:
	.p2align 4,,15
	.globl	printArray
	.type	printArray, @function
printArray:
.LFB68:
	.cfi_startproc
	testl	%esi, %esi	# n
	jle	.L76	#,
	leal	-1(%rsi), %eax	#, D.4081
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushq	%rbx	#
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	movq	%rdi, %rbx	# arr, ivtmp.72
	leaq	4(%rdi,%rax,4), %rbp	#, D.4083
	subq	$8, %rsp	#,
	.cfi_def_cfa_offset 32
	.p2align 4,,10
	.p2align 3
.L69:
	movl	(%rbx), %edx	# MEM[base: _20, offset: 0B],
	xorl	%eax, %eax	#
	movl	$.LC11, %esi	#,
	movl	$1, %edi	#,
	addq	$4, %rbx	#, ivtmp.72
	call	__printf_chk	#
	cmpq	%rbp, %rbx	# D.4083, ivtmp.72
	jne	.L69	#,
	addq	$8, %rsp	#,
	.cfi_def_cfa_offset 24
	movl	$10, %edi	#,
	popq	%rbx	#
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popq	%rbp	#
	.cfi_restore 6
	.cfi_def_cfa_offset 8
	jmp	putchar	#
.L76:
	movl	$10, %edi	#,
	jmp	putchar	#
	.cfi_endproc
.LFE68:
	.size	printArray, .-printArray
	.section	.text.unlikely
.LCOLDE12:
	.text
.LHOTE12:
	.section	.rodata.str1.8
	.align 8
.LC13:
	.string	"----------------------------------------"
	.section	.rodata.str1.1
.LC14:
	.string	"%s :\n"
.LC15:
	.string	"length of array : n = %d\n"
.LC17:
	.string	"Run time : %lf \n"
	.section	.text.unlikely
.LCOLDB18:
	.text
.LHOTB18:
	.p2align 4,,15
	.globl	calculateRunTime
	.type	calculateRunTime, @function
calculateRunTime:
.LFB70:
	.cfi_startproc
	pushq	%r13	#
	.cfi_def_cfa_offset 16
	.cfi_offset 13, -16
	pushq	%r12	#
	.cfi_def_cfa_offset 24
	.cfi_offset 12, -24
	movq	%rsi, %r12	# testName, testName
	pushq	%rbp	#
	.cfi_def_cfa_offset 32
	.cfi_offset 6, -32
	pushq	%rbx	#
	.cfi_def_cfa_offset 40
	.cfi_offset 3, -40
	movq	%rdi, %rbx	# sort, sort
	movl	$1000000, %edi	#,
	subq	$8, %rsp	#,
	.cfi_def_cfa_offset 48
	call	generateRandArray	#
	movq	%rax, %r13	#, arr
	call	clock	#
	movl	$cmpInt, %r8d	#,
	movl	$4, %ecx	#,
	movq	%rax, %rbp	#, begin
	movl	$999999, %edx	#,
	xorl	%esi, %esi	#
	movq	%r13, %rdi	# arr,
	call	*%rbx	# sort
	call	clock	#
	movl	$.LC13, %edi	#,
	movq	%rax, %rbx	#, end
	call	puts	#
	movq	%r12, %rdx	# testName,
	movl	$.LC14, %esi	#,
	movl	$1, %edi	#,
	xorl	%eax, %eax	#
	subq	%rbp, %rbx	# begin, D.4087
	call	__printf_chk	#
	movl	$1000000, %edx	#,
	movl	$.LC15, %esi	#,
	movl	$1, %edi	#,
	xorl	%eax, %eax	#
	call	__printf_chk	#
	pxor	%xmm0, %xmm0	# D.4088
	movl	$1, %edi	#,
	movl	$.LC17, %esi	#,
	movl	$1, %eax	#,
	cvtsi2sdq	%rbx, %xmm0	# D.4087, D.4088
	divsd	.LC16(%rip), %xmm0	#, runTime
	call	__printf_chk	#
	addq	$8, %rsp	#,
	.cfi_def_cfa_offset 40
	movl	$.LC13, %edi	#,
	popq	%rbx	#
	.cfi_def_cfa_offset 32
	popq	%rbp	#
	.cfi_def_cfa_offset 24
	popq	%r12	#
	.cfi_def_cfa_offset 16
	popq	%r13	#
	.cfi_def_cfa_offset 8
	jmp	puts	#
	.cfi_endproc
.LFE70:
	.size	calculateRunTime, .-calculateRunTime
	.section	.text.unlikely
.LCOLDE18:
	.text
.LHOTE18:
	.section	.rodata.str1.1
.LC19:
	.string	"quick sort two way"
.LC20:
	.string	"quick sort three way"
	.section	.text.unlikely
.LCOLDB21:
	.section	.text.startup,"ax",@progbits
.LHOTB21:
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB71:
	.cfi_startproc
	subq	$8, %rsp	#,
	.cfi_def_cfa_offset 16
	movl	$.LC19, %esi	#,
	movl	$quick_sort_two_way, %edi	#,
	call	calculateRunTime	#
	movl	$.LC20, %esi	#,
	movl	$quick_sort_three_way, %edi	#,
	call	calculateRunTime	#
	xorl	%eax, %eax	#
	addq	$8, %rsp	#,
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE71:
	.size	main, .-main
	.section	.text.unlikely
.LCOLDE21:
	.section	.text.startup
.LHOTE21:
	.data
	.align 4
	.type	mySeed.3698, @object
	.size	mySeed.3698, 4
mySeed.3698:
	.long	25011984
	.align 4
	.type	mySeed.3686, @object
	.size	mySeed.3686, 4
mySeed.3686:
	.long	25011984
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC16:
	.long	0
	.long	1093567616
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.10) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
