global _ft_strlen
section .text

_ft_strlen:
	push rdi
	mov rax, 0

loop:
	cmp byte [rdi], 0
	jz return
	inc rax
	inc rdi
	jmp loop

return:
	pop rdi
	ret
	