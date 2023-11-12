#ifndef WORDLE_H
# define WORDLE_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>
# include <string.h>
# include <time.h>
# include <stdint.h>

# include "defines.h"

typedef struct s_letters
{
	char	*str;
	char	color[5];
	int		occurrences[5];
	// int 	already_printed[5];
}			t_letters;

typedef struct s_game
{
	char		**dictionary;
	size_t		dictionary_size;
	size_t		word_count;
  	char		*prev_guesses[6];
	t_letters	wod;
	t_letters	input;
}				t_game;

// banner.c
void	print_banner(void);

// init_struct.c
void	init_struct(t_game *game);
void	init_letters(t_letters *letters);

// free_all.c
int		free_all(t_game *game, char *err_msg, int i);
void	*free_ptr(void *ptr);
void	*free_arr(char **arr, int i);
int		ft_error(char *msg);

// read_dictionary.c
int		read_dictionary(t_game *game, FILE *db_file);

// word.c
void	get_wod(t_game *game);
int		find_word_in_dict(t_game *game, char *input);

// print_game.c
int		print_game(t_game *game, t_letters *input);
void	print_underscores(int guess);
void	print_prev_guesses(t_game *game, char *prev_guesses[], char *curr_guess);
void	print_guess(t_game *game, t_letters *input, char *str);
void	print_fail(char *word);
void	print_success();

// colors.c
void	set_green(t_letters *wod, t_letters *input, char *str);
void	set_yellow(t_letters *wod, t_letters *input, char *str);
void	count_occurrences(t_letters *input, char *str);
void	reset_colors(t_letters *input);

// utils.c
int		ft_strlen(char *str);
int		ft_isalpha(char *str);
char	*to_lower(t_game *game, char *str);
char	*to_upper(t_game *game, char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

// ft_split.c
char	**ft_split(char const *s, char c);

#endif
