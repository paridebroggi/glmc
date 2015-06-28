NAME = libglmc.a

# Compilation settings
CC = gcc
CFLAGS = -Werror -Wextra -Wall -O3

# Custom paths
DIR_SRCS = srcs/
DIR_OBJS = objs/
DIR_INCS = incs/

#------------------------------------------------------------------------------#

FILES =	glmc_model.c \
		glmc_matrix.c \
		glmc_vector.c \

#------------------------------------------------------------------------------#

# Apply custom paths
OBJS = $(addprefix $(DIR_OBJS), $(notdir $(addprefix $(DIR_SRCS), $(FILES:.c=.o))))

# Colors
GREEN = \x1b[32;01m
PURPLE = \x1b[34;01m
CYAN = \x1b[36m
RESET = \x1b[39;49;00m

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	@ printf "Linking  "
	@ ar rc $(NAME) $(OBJS)
	@ printf "$(GREEN)DONE$(RESET)\n"
	@ echo "$(CYAN)GLMC Library$ $(GREEN) COMPLETED$(RESET) >>> 🍺"

$(DIR_OBJS)%.o: $(DIR_SRCS)%.c
	@ echo "Building $(PURPLE)$< $(RESET)"
	@ mkdir -p $(DIR_OBJS)
	@ $(CC) $(CFLAGS) -I$(DIR_INCS) -c $< -o $@

clean:
	@ rm -rf $(DIR_OBJS)
	@ echo "Clean $(CYAN)$(NAME) $(GREEN)DONE$(RESET)"

fclean: clean 
	@ rm -f $(NAME)
	@ echo "Fclean $(CYAN)$(NAME) $(GREEN)DONE$(RESET)"

re: fclean all

.PHONY: all clean fclean re