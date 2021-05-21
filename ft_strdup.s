global _ft_strdup
extern _ft_strlen
extern _malloc
extern _ft_strcpy
section .text

_ft_strdup:
	call _ft_strlen
	push rdi
	add rax, 1
	mov rdi, rax
	call _malloc
	cmp rax, 0
	je error
	pop rdi
	mov rsi, rdi
	mov rdi, rax
	call _ft_strcpy
	ret

error:
	mov rax, 0
	ret
