/*
** EPITECH PROJECT, 2019
** CPool_finalstumper_2019
** File description:
** Check if yes or no the given buffer is the first rush1
*/

static int is_bottom(char *buff, int tmp);

static int is_middle(char *buff, int tmp);

int is_fourth(char *buff)
{
    int tmp = 0;

    if (*(buff + 1) == '\0')
        return (0);
    ++buff;
    for (int i = 0; *buff != '\n'; buff++) {
        if (*buff == 'C' && *(buff + 1) != '\n')
            return (0);
        if (*buff == 'B' && *(buff + 1) != 'B' && *(buff + 1) != 'C')
            return (0);
        if (!(*buff == 'B' || *buff == 'C'))
            return (0);
        tmp++;
    }
    if (*(buff + 1) == '\0')
        return (1);
    return (is_middle(++buff, tmp) || is_bottom(++buff, tmp));
}

static int is_bottom(char *buff, int tmp)
{
    int new_tmp = 0;
    if (*(buff + 1) == '\0')
        return (0);
    for (int i = 0; *buff != '\n'; buff++) {
        if (*buff == 'A' && *(buff + 1) != 'B' && *(buff + 1) != 'C')
            return (0);
        if (*buff == 'B' && *(buff + 1) != 'B' && *(buff + 1) != 'C')
            return (0);
        if (*buff == 'C' && *(buff + 1) != '\n')
            return (0);
        if (!(*buff == 'C' || *buff == 'B' || *buff == 'A'))
            return (0);
        new_tmp++;
    }
    if (new_tmp != tmp + 1)
        return (0);
    if (*(buff + 1) == '\0')
        return (1);
    return (0);
}

static int is_middle(char *buff, int tmp)
{
    int new_tmp = 0;
    if (*(buff + 1) == '\0')
        return (0);
    for (int i = 0; *buff != '\n'; buff++) {
        if (*buff == 'B' && *(buff + 1) != ' ' && *(buff + 1) != '\n'
            && *(buff + 1) != 'B')
            return (0);
        if (*buff == ' ' && *(buff + 1) != ' ' && *(buff + 1) != 'B')
            return (0);
        if (!(*buff == 'B' || *buff == ' '))
            return (0);
        new_tmp++;
    }
    if (*(buff + 1) == '\0')
        return (0);
    if (new_tmp != tmp + 1)
        return (0);
    return (is_bottom(++buff, tmp) || is_middle(buff, tmp));
}
