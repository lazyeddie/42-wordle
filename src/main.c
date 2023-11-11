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
	char	*word = "brave";
	int		fd;
	char **database;
	t_game	game;

	init_struct(&game);
	print_banner();
	fd = open("words.txt", O_RDONLY);
	if (fd < 0)
		return (free_all(&game,ERR_FD));
	database = read_database(fd);
	word = get_wod(database);
	if (print_game())
		print_fail(to_upper(word));
	// free_all(&game, NULL);...
	return (0);
}
