#include "wordle.h"

int read_dictionary(t_game *game, FILE *db_file)
{
	size_t	nbytes;
	char	*db_string;

	fseek(db_file, 0, SEEK_END);
	game->dictionary_size = ftell(db_file);
	fseek(db_file, 0, SEEK_SET);
	db_string = (char*)malloc(sizeof(char) * (game->dictionary_size + 1));
	if (!db_string)
	{
		free_all(game, ERR_MALLOC, 0);
		return (1);
	}
	nbytes = fread(db_string, 1, game->dictionary_size, db_file);
	db_string[nbytes] = '\0';
	game->dictionary = ft_split(db_string, '\n');
	if (!game->dictionary)
	{
		free_all(game, ERR_MALLOC, 0);
		return (1);
	}
	free(db_string);
	game->word_count = 0;
	while(game->dictionary[game->word_count])
		game->word_count++;
	// printf("Dictionary_size: %ld Bytes\n", game->dictionary_size);
	// printf("Words in Dictionary: %lu\n", game->word_count);
	return (0);
}
