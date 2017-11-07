#include "get_next_line.h"
#include <stdio.h>

int     main(int ac, char **av)
{
    int		fd;
    int		fd2;
    char	*str;
    int		res;

    res = 1;
    if (ac == 1)
    {
        while (res > 0)
        {
            res = get_next_line(0, &str);
            printf("return: %d       string: %s\n", res, str);
        }
    }
    if (ac == 2)
    {
        fd = open(av[1], O_RDONLY);
        while (res > 0)
        {
            res = get_next_line(fd, &str);
            printf("return: %d       string: %s\n", res, str);
        }
    }
    if (ac == 3)
    {
        fd = open(av[1], O_RDONLY);
        fd2 = open(av[2], O_RDONLY);
        res = get_next_line(fd, &str);
        printf("#1  return: %d       string: %s\n", res, str);
        res = get_next_line(fd2, &str);
        printf("#2  return: %d       string: %s\n", res, str);
        res = 1;
        while (res > 0)
        {
            res = get_next_line(fd, &str);
            printf("#1  return: %d       string: %s\n", res, str);
        }
        res = 1;
        while (res > 0)
        {
            res = get_next_line(fd2, &str);
            printf("#2  return: %d       string: %s\n", res, str);
        }
    }
    return (0);
}
