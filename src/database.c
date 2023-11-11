#include "wordle.h"

char **read_database(t_game *game, FILE *db_file)
{
	long	db_size;
	size_t	nbytes;

	fseek(db_file, 0, SEEK_END);
	db_size = ftell(db_file);
	fseek(db_file, 0, SEEK_SET);
	game->database_string = (char*)malloc(sizeof(char) * (db_size + 1));
	if (!game->database_string)
	{
		free_all(game, ERR_MALLOC);
		return (NULL);
	}
	nbytes = fread(game->database_string, 1, db_size, db_file);
	//game->database_string[nbytes] = '\0';
	//printf("db_string: %s\n", game->database_string);
	game->database_array = ft_split(game->database_string, '\n');
	if (!game->database_array)
	{
		free_all(game, ERR_MALLOC);
		return (NULL);
	}
	//printf("db_array: %s\n", game->database_array[0]);
	printf("db_size: %ld\n", db_size);

	return NULL;
}
