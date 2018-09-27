# **************************************************************************** #
#                                                                              #
#                                                                              #
#                                                                              #
#                                                                              #
#                                                                              #
#                                                                              #
#                                                                              #
#                                                                              #
#                                                                              #
# **************************************************************************** #

NAME = libsort.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = ft_insertion_sort.c\
		ft_quicksort.c

OBJDIR = ./obj/
OBJ = $(addprefix $(OBJDIR), $(SRC:.c=.o))

all: obj $(NAME)

obj:
	@mkdir $(OBJDIR)

$(OBJDIR)%.o:%.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): libsort.h $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "Library successfully built"

clean:
	@rm -rf $(OBJDIR)

fclean:
	@rm -rf$(NAME)

re: fclean all

.PHONY: all clean fclean re
