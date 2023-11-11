#include "wordle.h"

void	print_banner(void)
{
	char	*banner = " \
					 ____ ____ ____ ____ ____ ____ \n \
					||W |||o |||r |||d |||l |||e ||\n \
					||__|||__|||__|||__|||__|||__||\n \
					|/__\\|/__\\|/__\\|/__\\|/__\\|/__\\|\n";

	char	*txt = " \
						  +-+-+-+-+-+\n \
						  |g|u|e|s|s|\n \
						  +-+-+-+-+-+\n";

	printf(GREEN BOLD"%s\n"RESET, banner);
	printf(WHITE DIM"%s\n"RESET, txt);
}
