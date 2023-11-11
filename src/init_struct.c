#include "wordle.h"

void	init_struct(t_game *game)
{
  int	i;
 
	game->dictionary = NULL;
	game->dictionary_size = 0;
	game->word_count = 0;
  	i = MAX;
	while (i >= 0)
		game->prev_guesses[--i] = NULL;
}
