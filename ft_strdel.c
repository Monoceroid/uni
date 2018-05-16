#include "libft.h"
#include <stdlib.h>

void    ft_strdel(void **as)
{
    free(*as);
    *as = NULL;
}