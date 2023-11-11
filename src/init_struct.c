#include "wordle.h"

void	init_struct(t_game *game)
{
	game->dictionary = NULL;
	game->dictionary_size = 0;
	game->word_count = 0;
}
