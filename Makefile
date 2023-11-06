NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)
LIBFT = libft/libft.a
MLXFLAGS = -L ./mlx/ -lmlx -framework OpenGL -framework AppKit -lz #-g -fsanitize=address
RM = rm -f

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJECTS)
	make -C libft
	$(CC) $(OBJECTS) $(LIBFT) $(MLXFLAGS) $(CFLAGS) -o $(NAME)

%o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean: 
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)
	$(RM) *.out
	make fclean -C libft/

re: fclean all

.PHONY: all clean fclean re