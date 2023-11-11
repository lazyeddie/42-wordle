# executable
NAME		= wordle

# compiler
CC			= cc
CFLAGS		= -Werror -Wextra -Wall -g
DEPFLAGS	= -MP -MMD

# # libft
# LIB_DIR		=	lib/ft_printf/
# LIB_NAME	=	libftprintf.a
# LIB			=	$(LIB_DIR)$(LIB_NAME)

# include
INC			=	-I./inc

# readline
RL			=	-lreadline

# source files
SRC			= 	main.c \
				utils.c \
				banner.c
SRCDIR		=	src/

# object files
OBJ			= $(SRC:%.c=%.o)
OBJDIR		= obj/
OBJPATH		= $(addprefix $(OBJDIR), $(OBJ))

# dependency files
DEP			= $(patsubst %.c, %.d, $(SRC))
DEPDIR		= dep/
DEPPATH 	= $(addprefix $(DEPDIR), $(DEP))

# colors
RED 		='\033[31m'
GREEN		='\033[32m'
YELLOW		='\033[33m'
BLUE		='\033[34m'
PINK		='\033[35m'
CYAN		='\033[36m'
WHITE		='\033[37m'
GRAY		='\033[237m'

BG_BLACK	='\033[40m'
BG_RED		='\033[41m'
BG_GREEN	='\033[42m'
BG_YELLOW	='\033[43m'
BG_BLUE		='\033[44m'
BG_PINK		='\033[45m'
BG_CYAN		='\033[46m'
BG_WHITE	='\033[47m'

BOLD		='\033[1m'
DIM			='\033[2m'
CURSIVE		='\033[3m'
UNDERLINE	='\033[4m'
RESET		='\033[0m'

# rules
all: $(NAME)

# $(LIB):
# 	@echo $(GRAY)"Making libftprintf..."$(RESET)
# 	@make -sC $(LIB_DIR)

$(NAME): $(OBJDIR) $(OBJPATH) $(DEPDIR)
	@$(CC) $(CFLAGS) $(INC) -o $(NAME) $(OBJPATH) $(RL)
	@echo $(BG_GREEN) $(DIM)"wordle ready" $(RESET)

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) $(CFLAGS) $(DEPFLAGS) $(INC) -c -o $@ $<

$(OBJDIR): 
	@mkdir -p $(OBJDIR)

$(DEPDIR):
	@mkdir -p $@
	@mv $(OBJDIR)*.d $@

-include $(DEPPATH)

clean:
	@rm -rf $(OBJDIR) $(DEPDIR)
	@echo $(GRAY) $(CURSIVE) "====> All object files removed successfully!" $(RESET)
	@echo $(YELLOW)"clean" $(RESET)

fclean: clean
	@rm -rf $(NAME)
	@echo $(GRAY) $(CURSIVE) "====> All object files, libraries  and executables removed successfully!" $(RESET)
	@echo $(BG_YELLOW) $(DIM)"All clean" $(RESET)

re: fclean all

.PHONY:	all clean fclean re