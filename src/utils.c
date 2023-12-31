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

/* void	print_info(t_letters *wod, t_letters *input)
{
	int	i;

	i = 0;
	printf("wod: %s\n", wod->str);
	printf("wod-occur: ");
	//while (i < 5)
	//	printf("%d ", wod->occurrences[i++]);
	printf("\n");
	i = 0;
	printf("cur-occur: ");
	while (i < 5)
	//	printf("%d ", input->occurrences[i++]);
	printf("\n");
	i = 0;
	printf("color: ");
	while (i < 5)
		printf("%d ", input->color[i++]);
	printf("\n");
} */

t_letters	copy_letters(t_game *game, t_letters *input)
{
	t_letters copy;

	init_letters(&copy);
	copy.str = strdup(input->str);
	if (!copy.str)
		free_all(game, ERR_MALLOC, MAX);
	return (copy);
}
