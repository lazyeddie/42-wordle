#include "wordle.h"

int	print_game(t_game *game, t_letters *input)
{
	int			guess = MAX;
	int			i = 0;

	while (1)
	{
		input->str = "";
		print_underscores(guess);
		while (ft_strlen(input->str) != 5 || !ft_isalpha(input->str) || !find_word_in_dict(game, input->str))
		{
			input->str = readline("Enter 5 letter word:\t");
			if (!input->str)
				return (free_all(game, NULL, MAX));
		}
		guess--;
		printf("%s", CLEAR_TERM);
		print_banner();
		print_prev_guesses(game, game->prev_guesses, input);
		print_guess(game, input);
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
		printf(WHITE BOLD"\t\t\t\t\t\t _  _  _  _  _ \n"RESET);
}

void	print_prev_guesses(t_game *game, t_letters prev_guesses[], t_letters *input)
{
	int			i;

	i = 0;
	while (prev_guesses[i].str)
	{
		print_guess(game, &prev_guesses[i]);
		i++;
	}
	prev_guesses[i] = copy_letters(game, input);
	if (!prev_guesses[i].str)
		free_all(game, ERR_MALLOC, i);
}

void	print_guess(t_game *game, t_letters *letters)
{
	int		i;
	char	*bg_color;

	i = 0;
	printf("\t\t\t\t\t\t");
	reset_colors(letters);
	reset_alphabet(game, letters);
	set_green(game, &game->wod, letters);
	set_yellow(game, &game->wod, letters);
	while (letters->str && letters->str[i])
	{
		bg_color = RESET;
		if (letters->color[i] == 'G')
			bg_color = BG_GREEN;
		else if (letters->color[i] == 'Y')
			bg_color = BG_YELLOW;
		printf(WHITE BOLD "%s %c "RESET, bg_color, toupper(letters->str[i]));
		i++;
	}
	printf("\n");
	// rl_on_new_line();
	// rl_replace_line("hallihallo", 8);
	// rl_redisplay();
}

void	print_fail(t_game *game, char *word)
{
	printf("----------\nYou lost! :(\nThe word of the day was %s\nBetter luck next time!\n", to_upper(game, word));
}

void	print_success()
{
	printf("----------\nCongrats! :)\nYou guessed the word!\nThank you for playing!\n");
}
