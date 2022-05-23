#ifndef GNL_H
# define GNL_H

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void	*ft_memcpy(void *str1,  void *str2, size_t n);
size_t	ft_strlen( char *str);
size_t	ft_strlcat(char *dst,  char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst,  char *src, size_t maxlen);
char	*ft_strdup( char *s);
int	ft_strchr( char *s, int c);
char    *ft_cut(char  *s2);
char	*ft_strjoin_fix(char  *s1, char  *s2);
char	*ft_substr(char  *s, int start, int len);
char    *get_next_line(int fd);
//int ft_gnl_core(char *line, char *save, char *buf);

#endif 