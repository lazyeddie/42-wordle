#ifndef WORDLE_H
# define WORDLE_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>
# include <string.h>

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
char	**read_database(t_game *game, FILE *db_file);

// word.c
char	*get_wod(char **db);
int		find_word_in_dict(char *input);

// print_game.c
int		print_game(void);
void	print_underscores(int guess);
void	print_prev_guesses(char **prev_guesses, char *curr_guess);
void	print_guess(char *str);
void	print_fail(char *word);

// utils.c
int		ft_strlen(char *str);
int		ft_isalpha(char *str);
char	*to_lower(char *str);
char	*to_upper(char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

// ft_split.c
char	**ft_split(char const *s, char c);


#endif
