#ifndef WORDLE_H
# define WORDLE_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>

// utils.c
int		ft_strlen(char *str);
int		ft_isalpha(char *str);
char	*to_lower(char *str);
char	*to_upper(char *str);

#endif