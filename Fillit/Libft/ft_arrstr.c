int *ft_arrstr(char *str, char c, int i, int j)
{
    int arr[i][j];

    while (*str != '\0')
    {
        if (*str >= '0' && *str <= '9' && *(str + 1) == c)
            arr[i][j] = *str++ - '0';
        else if (*str >= '0' && *str <= '9')
            arr[i][j] = (*str - '0') * 10 + *(str++ + 1);

    }
}