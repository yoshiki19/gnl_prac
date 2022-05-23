
#include "get_next_line.h"


char    *get_next_line(int fd)
{
    int newline_flag;
    int n;
    static char *save;
    char *line;
    char *buf;
    char *s;

    newline_flag = 0;
    buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
    if (!buf)
        return (NULL);
    while (newline_flag == 0 && (n = read(fd, buf, BUFFER_SIZE)) > 0)
    {
        buf[n] = '\0';
        save = ft_strjoin_fix(save, buf);
        if (ft_strchr(buf, '\n'))
        {
            newline_flag = 1;
            s = ft_substr(buf, n + 1, BUFFER_SIZE - (n + 1));
        }
    }
    line = ft_strdup(save);
    free(save);
    save = s;
    free(buf);
    return (line);
}

int main(void)
{
        char *ans;
        int fd;

        fd = open("sample.txt", O_RDONLY);
        if (fd == -1)
        {
                printf("ファイルオープンエラー\n");
                return 0;
        }
        //rc = read(fd, buff, BUFFER_SIZE)
        while (1)
        {
            ans = get_next_line(fd);
            printf("%s", ans);
            if (ans == NULL)
                break;
        }
        close(fd);
}
