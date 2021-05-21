global _ft_strcmp
extern _ft_strlen
section .text

_ft_strcmp:
	push rcx
	push rbx
	xor rcx, rcx

loop:
	mov bl, byte [rdi + rcx]
	cmp bl, byte [rsi + rcx]
	jne return
	cmp byte [rdi + rcx], 0
	je return
	inc rcx
	jmp loop

return:
	cmp bl, byte [rsi + rcx]
	jl negative
	sub bl, byte [rsi + rcx]
	mov rax, rbx
	jmp _ret

negative:
	add bl, byte [rsi + rcx]
	mov rax, rbx
	neg rax
	jmp _ret

_ret:
	pop rbx
	pop rcx
	ret
