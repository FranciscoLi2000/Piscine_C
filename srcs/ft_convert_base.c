#include "c_piscine.h"

static int	check_base(char *str_base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

static int	num_len(long n, char *base_str)
{
	int	base_len;
	int	digits;

	base_len = check_base(base_str);
	if (base_len <= 1)
		return (0);
	if (n == 0)
		return (1);
	if (n < 0)
		n = -n;
	digits = 0;
	while (n > 0)
	{
		n = n / base_len;
		digits++;
	}
	return (digits);
}

static char	*ft_itoa_base(int nbr, char *base_to)
{
	long	n;
	int			is_neg;
	int			base_len;
	int			digits;
	char		*res;
	int			i;

	base_len = check_base(base_to);
	if (base_len <= 1)
		return (NULL);
	n = (long)nbr;
	is_neg = 0;
	if (n < 0)
		is_neg = 1;
	if (is_neg)
		n = -n;
	digits = num_len(n, base_to);
	if (digits <= 0)
		return (NULL);
	if (is_neg)
		digits += 1;
	res = (char *)malloc((digits + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[digits] = '\0';
	i = digits - 1;
	if (n == 0)
		res[i--] = base_to[0];
	while (n > 0)
	{
		res[i--] = base_to[n % base_len];
		n /= base_len;
	}
	if (is_neg)
		res[0] = '-';
	return (res);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	value;

	if (!check_base(base_from) || !check_base(base_to))
		return (NULL);
	value = ft_atoi_base(nbr, base_from);
	return (ft_itoa_base(value, base_to));
}
