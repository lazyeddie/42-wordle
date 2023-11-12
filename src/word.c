#include "wordle.h"

void	get_wod(t_game *game)
{
	int	index;

	srand(time(NULL));
	index = rand() % game->word_count;
	game->wod.str = game->dictionary[index];
	printf("WOD: %s\n", game->wod.str);
	count_occurrences(&game->wod);
}

int	find_word_in_dict(t_game *game, char *input)
{
	size_t	index;
	size_t	min;
	size_t	max;
	int		comparison;

	index = 0;
	min = 0;
	max = game->word_count - 1;
 	if (strncmp(input, game->dictionary[min], 5) < 0
		|| strncmp(input, game->dictionary[max], 5) > 0)
		return (0);
	while (min <= max)
	{
		index = min + ((max - min) / 2);
		comparison = strncmp(input, game->dictionary[index], 5);
		//printf("min: %lu, max: %lu, index: %lu, comparison: %d\n", min, max, index, comparison);
		if (comparison == 0)
			return (1);
		else if (comparison < 0)
			max = index - 1;
		else
			min = index + 1;
	}
	return (0);
}
