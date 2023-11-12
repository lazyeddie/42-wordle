#include "wordle.h"

void	init_guess(t_guess *guess)
{
	int	i;

	i = 0;
	guess->str = NULL;
	while (i < 5)
	{
		guess->occurrences[i] = 0;
		guess->color[i] = 0;
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
		init_guess(&game->prev_guesses[i--]);

}
