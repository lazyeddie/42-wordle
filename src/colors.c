#include "wordle.h"


int	find_hit(char *wod, char c, int i)
{
	if (wod[i] == c)
		return (1);
	return (0);
}

int	find_char(char *wod, char c, int i)
{
	int	count;

	count = 0;
	while (wod[i])
	{
		if (wod[i] == c)
			count++;
		i++;
	}
	// if (hit)
	// 	return (-1);
	// if (hit && count > 1)
	return (count);
	// return (0);
}
void	set_green(t_letters *wod, t_letters *input, char *str)
{
	int	i = 0;

	while (wod->str[i])
	{
		if (wod->str[i] == str[i])
			input->color[i] = 'G';
		i++;
	}
}

void	set_yellow(t_letters *wod, t_letters *input, char *str)
{
	int	i;
	int	j;
	int	k;
	char	c;

	j = 0;
	while (str[j])
	{
		c = str[j];
		i = 0;
		while (wod->str[i])
		{
			if (input->color[i] != 'G')
			{
				if (wod->str[i] == c && wod->occurrences[i] >= input->occurrences[i])
					input->color[j] = 'Y';
				else if (wod->str[i] == c && wod->occurrences[i] < input->occurrences[i])
				{
					if (wod->occurrences[i] > 0)
					{
						k = 0;
						while (wod->str[k])
						{
							if (wod->str[k] == c)
								wod->occurrences[k] -= 1;
						}
						input->color[j] = 'Y';
					}
				}
			}
			i++;
		}
		j++;
		// print_info(&wod, input);
	}
	
}

// count how many times current each letter str[i] is in the word and store the
// count in guess.occorrences[i]
void	count_occurrences(t_letters *letters, char *str)
{
	int		i;
	int		j;
	char	cur;
	int		count;

	i = 0;
	while (i < 5)
	{
		cur = str[i];
		j = 0;
		count = 0;
		while (j < 5)
		{
			if (str[j] == cur)
				count++;
			j++;
		}
		letters->occurrences[i] = count;
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