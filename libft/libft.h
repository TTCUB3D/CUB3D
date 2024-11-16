/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 16:02:55 by tursescu          #+#    #+#             */
/*   Updated: 2024/08/31 08:44:18 by tursescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 47
# endif
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stddef.h>

int		ft_atoi(const char *str);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_printf(const char *string, ...);
int		ft_print_unsigned(unsigned int n);
int		ft_putchar_pr(char c);
int		ft_puthex_pr(unsigned long n, char *hex);
int		ft_putnbr_pr(long n);
int		ft_putptr_pr(void *ptr);
int		ft_putstr_pr(char *s);
int		ft_strlen_pr(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_bzero(void *s, size_t n);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	*ft_calloc(size_t nb, size_t size);
void	*ft_memmove(void *dest, const void *src, size_t len);
void	*ft_memcpy(void *dest, const void *src, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memset(void *s, int c, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *src);
char	*ft_strnstr(const char *big, const char *small, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(const char *s1, const char *set);
char	*ft_itoa(int n);
char	**ft_split(const char *s, char c);
char	*get_next_line(int fd);

#endif