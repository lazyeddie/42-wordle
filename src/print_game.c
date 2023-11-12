#include "wordle.h"

int	print_game(t_game *game, t_letters *input)
{
	int			guess = MAX;
	int			i = 0;

	while (1)
	{
		input->str = "";
		print_underscores(guess);
		while (ft_strlen(input->str) != 5 || !ft_isalpha(input->str)) //|| !find_word_in_dict(game, input))
		{
			input->str = readline("Enter 5 letter word:\t");
			if (!ft_strlen(input->str))
				free_all(game, NULL, MAX);
		}
		guess--;
		print_prev_guesses(game, game->prev_guesses, input->str);
		count_occurrences(input, input->str);
		print_guess(game, input, input->str);
		if (!strncmp(input->str, game->wod.str, 5))
			return (0);
		free(input->str);
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

void	print_prev_guesses(t_game *game, char *prev_guesses[], char *curr_guess)
{
	int			i;

	i = 0;
	while (prev_guesses && prev_guesses[i])
	{
		count_occurrences(&game->input, prev_guesses[i]);
		print_guess(game, &game->input, prev_guesses[i]);
		i++;
	}
	prev_guesses[i] = strdup(curr_guess);
	if (!prev_guesses[i])
		free_all(game, ERR_MALLOC, i);
}

void	print_guess(t_game *game, t_letters *input, char *str)
{
	int		i;
	char	*bg_color;

	i = 0;
	printf("\t\t\t\t\t\t");
	reset_colors(&game->input);
	set_green(&game->wod, input, str);
	set_yellow(&game->wod, input, str);
	while (str && str[i])
	{
		bg_color = RESET;
		if (game->input.color[i] == 'G')
			bg_color = BG_GREEN;
		else if (game->input.color[i] == 'Y')
			bg_color = BG_YELLOW;
		printf(WHITE BOLD "%s %c "RESET, bg_color, toupper(str[i]));
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
		printf("%d ", game->input.occurrences[i++]);
	printf("\n");
	i = 0;
	printf("color: ");
	while (i < 5)
		printf("%d ", game->input.color[i++]);
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
