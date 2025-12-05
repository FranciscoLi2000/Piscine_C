#include "c_piscine.h"

void	ft_putstr(char *str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i] != '\0')
		i++;
	write(1, str, i);
}
