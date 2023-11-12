#include "wordle.h"

void	init_letters(t_letters *letters)
{
	int	i;

	i = 0;
	letters->str = NULL;
	while (i < 5)
	{
		letters->occurrences[i] = 0;
		letters->color[i] = 0;
		i++;
	}
}

void	init_struct(t_game *game)
{
  int	i;

	game->dictionary = NULL;
	game->dictionary_size = 0;
	game->word_count = 0;
  	i = MAX;
	while (i >= 0)
		game->prev_guesses[i--] = NULL;
	init_letters(&game->wod);
	init_letters(&game->input);
}
