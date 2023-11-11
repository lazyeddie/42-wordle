// TODO Tom
#include "wordle.h"

void	init_struct(t_game *game)
{
	int	i;

	game->dictionary_array = NULL;
	game->dictionary_string = NULL;
	i = MAX;
	while (i >= 0)
		game->prev_guesses[--i] = NULL;
}
