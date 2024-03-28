CC = clang

SRCS_RAW =	main.c\
			parsing.c\
			render.c\
			input_parsing.c\
			parsing_utils.c\
			map_closed_check.c\
			path.c\
			events.c\
			color.c\
			map.c\
			free.c\
			raycaster.c

OBJS_DIR = objs/

SRCS_DIR = srcs/

SRCS = $(SRCS_RAW)


FLAGS = -Wall -Wextra -Werror -g
NAME = cub3D
MLX = MacroLibX/libmlx.so
LIBFT = libft/libft.a

all: 
	@$(MAKE) --no-print-directory -j $(NAME)

OBJS = $(addprefix $(OBJS_DIR), $(SRCS_RAW:.c=.o))
		
all: $(NAME) libft

LIBMLX_DIR = MacroLibX

$(MLX):
	make --no-print-directory -C MacroLibX -j

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(NAME): $(MLX) $(LIBFT) $(OBJS) 
	@echo "Linking $(NAME)..."
	$(CC) ${FLAGS} $(OBJS) -L MacroLibX -lm -lmlx -lSDL2 -Wl,-rpath,$(LIBMLX_DIR) -L libft -lft -o $@

$(LIBFT):
	make --quiet -C ./libft

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c | $(OBJS_DIR)
	$(CC) -g $(FLAGS) -c $< -o $@ -I libft -I MacroLibX/includes

clean:
	rm -rf $(OBJS_DIR)
	make -C ./libft fclean
	make -C ./MacroLibX/ fclean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean all re fclean libft
