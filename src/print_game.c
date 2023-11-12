#include "wordle.h"

int	print_game(t_game *game)
{
	char	*input;
	int		guess = MAX;
	int		i = 0;

	while (1)
	{
		input = "";
		print_underscores(guess);
		while (ft_strlen(input) != 5 || !ft_isalpha(input)) //|| !find_word_in_dict(game, input))
		{
			input = readline("Enter 5 letter word:\t");
			if (!ft_strlen(input))
				free_all(game, NULL, MAX);
		}
		guess--;
		print_prev_guesses(game, game->prev_guesses, input);
		count_occurrences(&game->prev_guesses[i]);
		print_guess(game, &game->prev_guesses[i]);
		if (!strncmp(input, game->wod.str, 5))
			return (0);
		free(input);
		if (!guess)
			return (1);
		i++;
	}
	return (0);
}

void	print_underscores(int guess)
{
	while (guess--)
		printf(WHITE BOLD"\t\t\t\t\t\t _  _  _  _  _ \n\n"RESET);
}

void	print_prev_guesses(t_game *game, t_guess *prev_guesses, char *curr_guess)
{
	int			i;

	i = 0;
	while (prev_guesses && prev_guesses[i].str)
	{
		print_guess(game, &prev_guesses[i]);
		i++;
	}
	prev_guesses[i].str = strdup(curr_guess);
	if (!prev_guesses[i].str)
		free_all(game, ERR_MALLOC, i);
}

void	print_guess(t_game *game, t_guess *guess)
{
	int		i;
	char	*bg_color;

	i = 0;
	printf("\t\t\t\t\t\t");
	while (guess->str && guess->str[i])
	{
		bg_color = RESET;
		if (find_hit(game->wod.str, guess->str[i], i))
		//if (guess->color[i] == 1)
			bg_color = BG_GREEN;
		else if (find_char(game->wod.str, guess->str[i], i) > 0)
			bg_color = BG_YELLOW;
		printf(WHITE BOLD "%s %c "RESET, bg_color, toupper(guess->str[i]));
		i++;
	}
	printf("\n");
	i = 0;
	printf("wod-occur: ");
	while (i < 5)
		printf("%d ", game->wod.occurrences[i++]);
	printf("\n");
	i = 0;
	printf("cur-occur: ");
	while (i < 5)
		printf("%d ", guess->occurrences[i++]);
	printf("\n");
	i = 0;
	printf("color: ");
	while (i < 5)
		printf("%d ", guess->color[i++]);
	printf("\n");
	// rl_on_new_line();
	// rl_replace_line("hallihallo", 8);
	// rl_redisplay();
}

void	print_fail(char *word)
{
	printf("----------\nYou lost! :(\nThe word of the day was %s\nBetter luck next time!\n", word);
}

void	print_success()
{
	printf("----------\nCongrats! :)\nYou guessed the word right!\nThank you for playing!\n");
}
