global _ft_strcpy
section .text

_ft_strcpy:
	push rsi
	xor rcx, rcx ; i = 0

loop:
	mov r8b, [rsi + rcx] ; char r8 = src[i]
	mov [rdi + rcx], r8b ; dst[i] = r8
	cmp byte [rsi + rcx], 0 ; if (src[i] == 0) return
	je return
	inc rcx ; i++
	jmp loop

return:
	pop rsi
	mov rax, rdi ; rax = dst
	ret
