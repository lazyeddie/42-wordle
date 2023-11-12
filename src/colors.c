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
void	set_green(t_letters *wod, t_letters *input)
{
	int	i = 0;

	while (wod->str[i])
	{
		if (wod->str[i] == input->str[i])
			input->color[i] = 'G';
		i++;
	}
}

void	set_yellow(t_letters *wod, t_letters *input)
{
	// go through guess and when current color guess.color[i] != 'G'
	// then set 'Y' or 'D' for default...
	// use guess.occurrences and wod.occurrences to determine...
	(void)input;
	(void)wod;
}

// count how many times current each letter str[i] is in the word and store the
// count in guess.occorrences[i]
void	count_occurrences(t_letters *input)
{
	int		i;
	int		j;
	char	cur;
	int		count;

	i = 0;
	while (i < 5)
	{
		cur = input->str[i];
		j = 0;
		count = 0;
		while (j < 5)
		{
			if (input->str[j] == cur)
				count++;
			j++;
		}
		input->occurrences[i] = count;
		i++;
	}
}
