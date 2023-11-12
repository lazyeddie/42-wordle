#include "wordle.h"

int	main(void)
{
	FILE	*db_file;
	t_game	game;

	init_struct(&game);
	printf("%s", CLEAR_TERM);
	print_banner();
	db_file = fopen("words.txt", "r");
	if (!db_file)
		return (free_all(&game, ERR_FD, MAX));
	read_dictionary(&game, db_file);
	get_wod(&game);
	//printf("target_word: %s\n", game.wod.str);
	if (print_game(&game, &game.input))
		print_fail(&game, game.wod.str);
	else
		print_success();
	return(free_all(&game, NULL, MAX));
}
