#include "wordle.h"

char **read_dictionary(t_game *game, FILE *db_file)
{
	long	db_size;
	size_t	nbytes;

	fseek(db_file, 0, SEEK_END);
	db_size = ftell(db_file);
	fseek(db_file, 0, SEEK_SET);
	game->dictionary_string = (char*)malloc(sizeof(char) * (db_size + 1));
	if (!game->dictionary_string)
	{
		free_all(game, ERR_MALLOC, 0);
		return (NULL);
	}
	nbytes = fread(game->dictionary_string, 1, db_size, db_file);
	//game->dictionary_string[nbytes] = '\0';
	//printf("db_string: %s\n", game->dictionary_string);
	game->dictionary_array = ft_split(game->dictionary_string, '\n');
	if (!game->dictionary_array)
	{
		free_all(game, ERR_MALLOC, 0);
		return (NULL);
	}
	//printf("db_array: %s\n", game->dictionary_array[0]);
	printf("db_size: %ld\n", db_size);

	return NULL;
}
