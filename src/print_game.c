#include "wordle.h"

int	print_game(void)
{
	char	*input;
	int		guess = 6;
	char 	*prev_guesses[5];

	bzero(prev_guesses, sizeof(char *));
	while (1)
	{
		input = "";
		print_underscores(guess);
		while (ft_strlen(input) != 5 || !ft_isalpha(input) || !find_word_in_dict(input))
		{
			input = readline("Enter 5 letter word:\t");
			if (!ft_strlen(input))
			{
				free(input);
				exit (0);
			}
		}
		guess--;
		// print_prev_guesses(prev_guesses, input);
		print_guess(to_upper(input));
		// printf("\t\t\t\t%s\n", word);
		free(input);
		if (!guess)
			return (1);
	}
	return (0);
}

void	print_underscores(int guess)
{
	while (guess--)
		printf(WHITE BOLD"\t\t\t\t\t\t   _ _ _ _ _\n\n"RESET);
}

void	print_prev_guesses(char **prev_guesses, char *curr_guess)
{
	int			i;
	static int	j;

	i = 0;
	while (prev_guesses[i])
	{
		print_guess(prev_guesses[i]);
		i++;
	}
	prev_guesses[j] = strdup(to_upper(curr_guess));
	j++;
}

void	print_guess(char *str)
{
	int	i;

	i = 0;
	printf("\t\t\t\t\t\t   ");
	while (str[i])
		printf(WHITE BOLD"%c "RESET, str[i++]);
	printf("\n");
}

void	print_fail(char *word)
{
	printf("----------\nYou lost! :(\nThe word of the day was %s\nBetter luck next time!\n", word);
}
