#include "wordle.h"

void	set_green(t_game *game, t_letters *wod, t_letters *input)
{
	int		i = 0;
	char	c;

	while (wod->str[i])
	{
		c = wod->str[i];
		if (wod->str[i] == input->str[i] && game->alphabet[c - 'a'] != 0)
		{
			input->color[i] = 'G';
			game->alphabet[c - 'a']--;
		}
		i++;
	}
}

void	set_yellow(t_game *game, t_letters *wod, t_letters *input)
{
	int	i;
	char	c;

	i = 0;
	while (wod->str[i])
	{
		if (input->color[i] != 'G')
		{
			c = input->str[i];
			if (game->alphabet[c - 'a'] != 0)
			{
				input->color[i] = 'Y';
				game->alphabet[c - 'a']--;
			}
		}
		i++;
	}
}


void	reset_colors(t_letters *input)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		input->color[i] = 0;
		i++;
	}
}

void	reset_alphabet(t_game *game, t_letters *letters)
{
	int	i;
	char c;
	(void)letters;
	i = 0;
	while (i < 26)
	{
		game->alphabet[i] = 0;
		i++;
	}
	i = 0;
	while (i < 5)
	{
		c = game->wod.str[i];
		game->alphabet[c - 'a']++;
		i++;
	}
}
