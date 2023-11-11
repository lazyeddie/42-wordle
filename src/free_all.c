#include "wordle.h"

int	free_all(t_game *game, char *err_msg, int i)
{
	if (game->dictionary)
		game->dictionary_array = free_arr(game->dictionary_array, MAX);
	if (game->prev_guesses[0])
		free_arr(game->prev_guesses, i);
	if (err_msg)
		ft_error(err_msg);
	return (1);
}

void	*free_ptr(void *ptr)
{
	if (ptr)
		free(ptr);
	ptr = NULL;
	return (ptr);
}

void	*free_arr(char **arr, int i)
{
	if (arr)
	{
		while (--i >= 0)
			free_ptr(arr[i]);
		arr = free_ptr(arr);
	}
	return (arr);
}

int	ft_error(char *msg)
{
	while (*msg)
		write(2, msg++, 1);
	exit (1);
}
