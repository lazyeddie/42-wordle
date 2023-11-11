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

	print_banner();
	if (print_game())
		print_fail(to_upper(word));
	return (0);
}
