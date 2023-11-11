#include "wordle.h"

int	print_game(t_game *game)
{
	char	*input;
	int		guess = MAX;

	while (1)
	{
		input = "";
		print_underscores(guess);
		while (ft_strlen(input) != 5 || !ft_isalpha(input) || !find_word_in_dict(game, input))
		{
			input = readline("Enter 5 letter word:\t");
			if (!ft_strlen(input))
				free_all(game, NULL, MAX);
		}
		guess--;
		print_prev_guesses(game, game->prev_guesses, input);
		print_guess(input);
		free(input);
		if (!guess)
			return (1);
	}
	return (0);
}

void	print_underscores(int guess)
{
	while (guess--)
		printf(WHITE BOLD"\t\t\t\t\t\t _  _  _  _  _ \n\n"RESET);
}

void	print_prev_guesses(t_game *game, char **prev_guesses, char *curr_guess)
{
	int			i;

	i = 0;
	while (prev_guesses && prev_guesses[i])
	{
		print_guess(prev_guesses[i]);
		i++;
	}
	prev_guesses[i] = strdup(curr_guess);
	if (!prev_guesses[i])
		free_all(game, ERR_MALLOC, i);
}

void	print_guess(char *str)
{
	int		i;
	char	*wod = "apart";
	char	*bg_color;

	i = 0;
	printf("\t\t\t\t\t\t");
	while (str && str[i])
	{
		bg_color = RESET;
		if (find_hit(wod, str[i], i))
			bg_color = BG_GREEN;
		else if (find_char(wod, str[i], i) > 0)
			bg_color = BG_YELLOW;
		printf(WHITE BOLD "%s %c "RESET, bg_color, toupper(str[i]));
		i++;
	}
	printf("\n");
}

void	print_fail(char *word)
{
	printf("----------\nYou lost! :(\nThe word of the day was %s\nBetter luck next time!\n", word);
}
