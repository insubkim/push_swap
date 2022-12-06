int *ft_atoi_s(char **arr, int *size)
{
    int *args;
    int i;

    *size = get_arr_len(arr);
    args = (int *)malloc(sizeof(int) * *size);
    if (!args && !arr)
        print_error();
    i = 0;
    while (i < size)
    {
        args[i] = ft_atoix(arr[i]);
        i++;
    }
    return (args);
}