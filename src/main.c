#include "wordle.h"

// get word of the day from word list
// print six empty rows (5 underscores) and prompt
// get input from user
	// has to be strictly 5 chars long
	// has to be an existing word (check dictonary)
// to_lower input
// compare each char from input with word
	// if char matches, but wrong position --> yellow
	// if char matches and correct position --> green
	// if char not in word --> no color / grey
// to_upper input
// print out input with colors and 6-n underscore rows (n = number of guesses) + prompt
// if all chars match --> SUCCESS
	// print "Congratulations you found the word <str> in <n> guesses"
// if n=6 --> FAIL
int	main(void)
{
	char	*word = "HELLO";
	char	*word2 = "world";

	printf("%s\n", to_lower(word));
	printf("%s\n", to_upper(word2));
	return (0);
}
