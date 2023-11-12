#include "wordle.h"

/// print banner
// get word of the day from word list
// print six empty rows (5 underscores) and prompt
// get input from user
	// has to be strictly 5 chars long
	// has to be an existing word (check word list)
// to_lower input
// compare each char from input with word
	// if char matches, but wrong position --> yellow
	// if char matches and correct position --> green
	// handle multiple occurences
	// if char not in word --> no color / grey
// to_upper input
// print out input with colors and 6-n underscore rows (n = number of guesses) + prompt
// if all chars match --> SUCCESS
	// print "Congratulations you found the word <str> in <n> guesses"
// if n=6 --> FAIL
int	main(void)
{
	// char	*word = "brave";
	FILE	*db_file;
	t_game	game;

	init_struct(&game);
	print_banner();
	db_file = fopen("words.txt", "r");
	if (!db_file)
		return (free_all(&game,ERR_FD, MAX));
	read_dictionary(&game, db_file);
	get_wod(&game);
	printf("target_word: %s\n", game.wod.str);
	if (print_game(&game, &game.input))
		print_fail(game.wod.str);
	print_success();
	free_all(&game, NULL, MAX);
	return (0);
}
