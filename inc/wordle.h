#ifndef WORDLE_H
# define WORDLE_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>

# include "defines.h"

typedef struct s_game
{
	char	*database_string;
	char	**database_array;
}			t_game;

// banner.c
void	print_banner(void);

// init_struct.c
void	init_struct(t_game *game);

// free_all.c
int		free_all(t_game *game, char *err_msg);

// read_database.c
char	**read_database(int fd);

// word.c
char	*get_wod(char **db);
int		find_word_in_dict(char *input);

// print_game.c
int		print_game(t_game *game);
void	print_underscores(int guess);
void	print_prev_guesses(char *prev_guesses[], char *curr_guess);
void	print_guess(char *str);
void	print_fail(char *word);

// utils.c
int		ft_strlen(char *str);
int		ft_isalpha(char *str);
char	*to_lower(char *str);
char	*to_upper(char *str);

#endif
