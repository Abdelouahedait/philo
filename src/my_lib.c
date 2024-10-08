#include "philo.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int ch)
{
	while (*str != (char)ch)
	{
		if (*str == '\0')
			return (0);
		str++;
	}
	return ((char *)str);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	dijit(const char *s, long int sing)
{
	long int	i;
	long int	j;
	long int	k;

	i = 0;
	j = 0;
	while (ft_isdigit(s[i]) == 1)
	{
		k = j;
		j = (10 * j) + s[i] - '0';
		if (j < k)
		{
			if (sing == -1)
				return (0);
			return (-1);
		}
		i++;
	}
	return (j);
}

int	ft_atoi(const char *str)
{
	long int	j;
	long int	sing;

	sing = 1;
	j = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
	{
		sing *= -1;
		str++;
	}
	else if (*str == '+')
		str++;
	j = dijit(str, sing);
	return (j * sing);
}