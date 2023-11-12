#include "wordle.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

int	ft_isalpha(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] < 'A' || str[i] > 'z' || (str[i] > 'Z' && str[i] < 'a'))
			return (0);
		i++;
	}
	return (1);
}

char	*to_lower(t_game *game, char *str)
{
	int		i;
	int		len;
	char	*new;

	len = ft_strlen(str);
	new = malloc(sizeof(char) * len + 1);
	if (!new)
		free_all(game, ERR_MALLOC, 0);
	i = 0;
	while (str && str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			new[i] = str[i] + 32;
		i++;
	}
	return (new);
}

char	*to_upper(t_game *game, char *str)
{
	int		i;
	int		len;
	char	*new;

	len = ft_strlen(str);
	new = malloc(sizeof(char) * len + 1);
	if (!new)
		free_all(game, ERR_MALLOC, 0);
	i = 0;
	while (str && str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			new[i] = str[i] - 32;
		i++;
	}
	return (new);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (*(src + i) && size && i < size - 1)
	{
		*(dst + i) = *(src + i);
		i++;
	}
	if (size)
		*(dst + i) = '\0';
	return (ft_strlen((char *)src));
}

int	find_hit(char *wod, char c, int i)
{
	if (wod[i] == c)
		return (1);
	return (0);
}

int	find_char(char *wod, char c, int i)
{
	int	count;

	count = 0;
	while (wod[i])
	{
		if (wod[i] == c)
			count++;
		i++;
	}
	// if (hit)
	// 	return (-1);
	// if (hit && count > 1)
	return (count);
	// return (0);
}
void	set_green(t_guess *guess, t_guess *wod)
{
	// go through guess and when current letter matches wod, set
	// guess.color[i] = 'G'
	(void)guess;
	(void)wod;
}

void	set_yellow(t_guess *guess, t_guess *wod)
{
	// go through guess and when current color guess.color[i] != 'G'
	// then set 'Y' or 'D' for default...
	// use guess.occurrences and wod.occurrences to determine...
	(void)guess;
	(void)wod;
}

// count how many times current each letter str[i] is in the word and store the
// count in guess.occorrences[i]
void	count_occurrences(t_guess *guess)
{
	int	i;
	int	j;
	char	cur;
	int	count;

	i = 0;
	while (i < 5)
	{
		cur = guess->str[i];
		j = 0;
		count = 0;
		while (j < 5)
		{
			if (guess->str[j] == cur)
				count++;
			j++;
		}
		guess->occurrences[i] = count;
		i++;
	}
}
