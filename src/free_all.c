#include "wordle.h"

int	free_all(t_game *game, char *err_msg, int i)
{
	if (game->dictionary)
		game->dictionary = free_char_arr(game->dictionary, 0);
	if (game->prev_guesses[i].str)
	{
		while (i--)
			free_ptr(game->prev_guesses[i].str);
	}
	if (err_msg)
		return(ft_error(err_msg));
	return (0);
}

void	*free_ptr(void *ptr)
{
	if (ptr)
		free(ptr);
	ptr = NULL;
	return (ptr);
}

void	*free_arr(void *arr, int i)
{
	if (arr)
	{
		while (--i >= 0)
			free(&arr[i]);
		arr = free_ptr(arr);
	}
	return (arr);
}

void	*free_char_arr(char **arr, int i)
{
	if (arr)
	{
		while (arr[i])
		{
			free_ptr(arr[i]);
			i++;
		}
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
