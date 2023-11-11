#ifndef WORDLE_H
# define WORDLE_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>

# include "defines.h"

// banner.c
void	print_banner(void);

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

#endif