
#include "get_next_line.h"

void	*ft_memcpy(void *str1,  void *str2, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*str;

	dest = (unsigned char *)str1;
	str = (unsigned char *)str2;
	if (dest == NULL && str == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		*(dest + i) = *(str + i);
		i++;
	}
	return (dest);
}

size_t	ft_strlen( char *str)
{
	size_t	count;

	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}


size_t	ft_strlcat(char *dst,  char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	k;

	if (src != '\0' && dstsize == 0)
		return (ft_strlen(src));
	k = ft_strlen(dst) + ft_strlen(src);
	i = 0;
	j = ft_strlen(dst);
	if (dstsize < j + 1)
		return (ft_strlen(src) + dstsize);
	else
	{
		while (j < dstsize - 1 && src[i] != '\0')
		{
			dst[j] = src[i];
			i++;
			j++;
		}
		dst[j] = '\0';
	}
	return (k);
}

size_t	ft_strlcpy(char *dst,  char *src, size_t maxlen)
{
	size_t	srclen;

	srclen = ft_strlen(src);
	if (srclen + 1 < maxlen)
		ft_memcpy(dst, src, srclen + 1);
	else if (maxlen != 0)
	{
		ft_memcpy(dst, src, maxlen - 1);
		dst[maxlen - 1] = '\0';
	}
	return (srclen);
}

char	*ft_strdup( char *s)
{
	size_t	size;
	char	*str;

	if (!s)
		size = 0;
	else
		size = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str == 0)
		return (NULL);
	// if (!s)
	// {
	// 	*str = '\0';
	// 	return(str);
	// }
	ft_memcpy((void *)str, ( void *)s, size + 1);
	return (str);
}

//here
int	ft_strchr( char *s, int c)
{
	char	*str;
    int     i;

    i = 0;
	str = (char *)s;
	if (c == 0)
	{
		while (*str != '\0')
			str++;
		return (0);
	}
	else
	{
		while (str[i] != '\0')
		{
			if (str[i] == (char)c)
                return (i);
            i++;
		}
	}
	return (0);
}
//here

//here
char    *ft_cut(char *s2)
{
    int n;
    int i;
    char *str2;

    i = 0;
    n = ft_strchr(s2, '\n');
	str2 = malloc(sizeof(char) * (n + 1));
    while (i < n)
    {
        str2[i] = (char)s2[i];
        i++;
    }
	str2[i] = '\n';
	str2[i + 1] = '\0';
    return (str2);
}
//here

char	*ft_strjoin_fix(char *s1, char *s2)
{
	char	*str1;
	char	*str2;
	char	*mem;

	if (!s1 && !s2)
		return (0);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	str1 = (char *)s1;
	str2 = (char *)s2;
	//here
    if (ft_strchr(str2, '\n'))
    {
        str2 = ft_cut(str2);
    }
	//here
    mem = (char *)malloc((ft_strlen(str1) + ft_strlen(str2) + 1) * sizeof(char));
	if (!mem)
		return (0);
	ft_strlcpy(mem, str1, ft_strlen(str1) + 1);
	ft_strlcat(mem, str2, ft_strlen(str1) + ft_strlen(str2) + 1);
	return (mem);
}

char	*ft_substr(char *s, int start, int len)
{
	int	size;
	int	i;
	char	*str;
	char	*mem;

	size = len;
	str = (char *)s;
	if (!s)
		return (0);
	if (len == 0 || (size_t)start >= ft_strlen(str))
		return (ft_strdup(""));
	if (ft_strlen(&str[start]) < (size_t)len)
		size = ft_strlen(str) - start;
	i = 0;
	mem = (char *)malloc(sizeof(char) * (size + 1));
	if (!mem)
		return (0);
	while (i < size)
	{
		mem[i] = str[start + i];
		i++;
	}
	mem[i] = '\0';
	return (mem);
}
