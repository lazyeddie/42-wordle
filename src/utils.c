#include "wordle.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_isalpha(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 'A' || str[i] > 'z' || (str[i] > 'Z' && str[i] < 'a'))
			return (0);
		i++;
	}
	return (1);
}

char	*to_lower(char *str)
{
	int		i;
	int		len;
	char	*new;

	len = ft_strlen(str);
	new = malloc(sizeof(char) * len + 1);
	if (!new)
		exit (1);
	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			new[i] = str[i] + 32;
		i++;
	}
	return (new);
}

char	*to_upper(char *str)
{
	int		i;
	int		len;
	char	*new;

	len = ft_strlen(str);
	new = malloc(sizeof(char) * len + 1);
	if (!new)
		exit (1);
	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			new[i] = str[i] - 32;
		i++;
	}
	return (new);
}
