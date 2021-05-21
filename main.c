/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroland <rroland@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 18:07:44 by rroland           #+#    #+#             */
/*   Updated: 2021/05/19 14:44:38 by rroland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int	main(void)
{
	printf("\nft_strlen:\n");
	printf(" - |%zu| / |%zu|\n", ft_strlen("test"), strlen("test"));
	printf(" - |%zu| / |%zu|\n", ft_strlen("\0test"), strlen("\0test"));
	printf(" - |%zu| / |%zu|\n", ft_strlen("te\0st"), strlen("te\0st"));
	printf(" - |%zu| / |%zu|\n", ft_strlen(""), strlen(""));
	printf(" - |%zu| / |%zu|\n", ft_strlen("\0\0"), strlen("\0\0"));

	printf("\nft_strcpy:\n");
	char	*src = calloc(100, 1);
	char	*dst = calloc(100, 1);
	ft_strcpy(dst, (src = ""));
	printf(" - |%s| / |%s|\n", dst, src);
	ft_strcpy(dst, (src = "totooooooooooooooooooooo"));
	printf(" - |%s| / |%s|\n", dst, src);
	ft_strcpy(dst, (src = "tesst"));
	printf(" - |%s| / |%s|\n", dst, src);

	printf("\nft_strcmp:\n");
	src = "truc";
	dst = "truc";
	printf(" - |%d| / |%d|\n", ft_strcmp(dst, src), strcmp(dst, src));
	src = "abc";
	dst = "ab";
	printf(" - |%d| / |%d|\n", ft_strcmp(dst, src), strcmp(dst, src));
	src = "ab";
	dst = "abc";
	printf(" - |%d| / |%d|\n", ft_strcmp(dst, src), strcmp(dst, src));

	printf("\nft_write:\n");
	printf(" - |%zd| / |%zd|\n", ft_write(1, " toto\nnepasprint", 6), write(1, " toto\nnepasprint", 6));
	printf(" - |%zd| / |%zd|\n", ft_write(-42, " toto\nnepasprint", 6), write(-42, " toto\nnepasprint", 6));
	printf(" - |%zd| / |%zd|\n", ft_write(1, " toto\nnepasprint", 0), write(1, " toto\nnepasprint", 0));

	char	*path = "test.txt";
	int		file1 = open(path, O_RDWR);
	int		file2 = open(path, O_RDWR);
	int		size = 6000;
	char	buf1[size];
	char	buf2[size];
	printf("\nft_read:\n");
	printf(" - |%zd|: |%.*s|\n   |%zd|: |%.*s|\n", ft_read(file1, buf1, size), size , buf1, read(file2, buf2, size), size, buf2);
	file1 = -42;
	file2 = -42;
	printf(" - |%zd| / |%zd|\n", ft_read(file1, buf1, size), read(file2, buf2, size));
	close(file1);
	close(file2);

	printf("\nft_strdup:\n");
	char	*str;
	printf(" - |%s|\n", (str = ft_strdup("abcdefghijklmnopqrstuvwxyz")));
	free(str);
}
