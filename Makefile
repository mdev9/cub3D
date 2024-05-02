CC = clang

SRCS_RAW =	main.c				\
			parsing.c			\
			render.c			\
			input_parsing.c		\
			parsing_utils.c		\
			map_closed_check.c	\
			path.c				\
			events.c			\
			color.c				\
			map.c				\
			free.c				\
			raycaster.c			\
			mouse.c				\
			fps.c				\
			change_pos.c		\
			map_checks.c		\
			map_spawn_check.c	\
			init.c

SRCS_BONUS_RAW =	main_bonus.c				\
					parsing_bonus.c				\
					render_bonus.c				\
					input_parsing_bonus.c		\
					parsing_utils_bonus.c		\
					map_closed_check_bonus.c	\
					path_bonus.c				\
					events_bonus.c				\
					color_bonus.c				\
					map_bonus.c					\
					free_bonus.c				\
					raycaster_bonus.c			\
					mouse_bonus.c				\
					fps_bonus.c					\
					change_pos_bonus.c			\
					map_checks_bonus.c			\
					map_spawn_check_bonus.c		\
					minimap_bonus.c				\
					door_bonus.c				\
					animations_bonus.c			\
					init_bonus.c

OBJS_DIR = objs/

OBJS_BONUS_DIR = objs_bonus/

SRCS_DIR = srcs/

SRCS_BONUS_DIR = srcs_bonus/

SRCS = $(SRCS_RAW)

SRCS_BONUS = $(SRCS_BONUS_RAW)

FLAGS = -Wall -Wextra -Werror -g
NAME = cub3D
NAME_BONUS = cub3D_bonus
MLX = MacroLibX/libmlx.so
LIBFT = libft/libft.a

all: 
	@$(MAKE) --no-print-directory -j $(NAME)

OBJS = $(addprefix $(OBJS_DIR), $(SRCS_RAW:.c=.o))

OBJS_BONUS = $(addprefix $(OBJS_BONUS_DIR), $(SRCS_BONUS_RAW:.c=.o))
		
all: $(NAME) libft

LIBMLX_DIR = MacroLibX

$(MLX):
	make --no-print-directory -C MacroLibX -j

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_BONUS_DIR):
	mkdir -p $(OBJS_BONUS_DIR)

$(NAME): $(MLX) $(LIBFT) $(OBJS) 
	@echo "Linking $(NAME)..."
	$(CC) ${FLAGS} $(OBJS) -L MacroLibX -lm -lmlx -lSDL2 -Wl,-rpath,$(LIBMLX_DIR) -L libft -lft -o $@

$(NAME_BONUS): $(MLX) $(LIBFT) $(OBJS_BONUS) 
	@echo "Linking $(NAME_BONUS)..."
	$(CC) ${FLAGS} $(OBJS_BONUS) -L MacroLibX -lm -lmlx -lSDL2 -Wl,-rpath,$(LIBMLX_DIR) -L libft -lft -o $@

$(LIBFT):
	make --quiet -C ./libft

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c | $(OBJS_DIR)
	$(CC) -g $(FLAGS) -c $< -o $@ -I libft -I MacroLibX/includes

$(OBJS_BONUS_DIR)%.o : $(SRCS_BONUS_DIR)%.c | $(OBJS_BONUS_DIR)
	$(CC) -g $(FLAGS) -c $< -o $@ -I libft -I MacroLibX/includes

bonus: $(NAME_BONUS) libft

clean:
	rm -rf $(OBJS_DIR)
	rm -rf $(OBJS_BONUS_DIR)
	make -C ./libft fclean
	make -C ./MacroLibX/ fclean

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)

re: fclean all

.PHONY: clean all re fclean libft
