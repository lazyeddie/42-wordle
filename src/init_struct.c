#include "wordle.h"

void	init_letters(t_letters *letters)
{
	int	i;

	i = 0;
	letters->str = NULL;
	while (i < 5)
	{
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
		game->prev_guesses[i--].str = NULL;
	init_letters(&game->wod);
	init_letters(&game->input);
	i = 0;
	while (i < 26)
	{
		game->alphabet[i] = 0;
		i++;
	}
}
