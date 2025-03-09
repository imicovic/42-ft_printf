NAME		= libftprintf.a
INCLUDE		= include
LIBFT		= libft
SRC_DIR		= src/
OBJ_DIR		= obj/
CC			= cc
CFLAGS		= -Wall -Werror -Wextra -I
RM			= rm -rf
AR			= ar rcs

SRC_FILES	=	ft_printf\
				ft_print_ptr\
				ft_print_int\
				ft_print_uint\
				ft_print_hex\
				ft_print_char\
				ft_print_str

SRC 		= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

all:		$(NAME)

$(NAME):	$(OBJ)
			@make -C $(LIBFT)
			@cp libft/libft.a .
			@mv libft.a $(NAME)
			$(AR) $(NAME) $(OBJ)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
			@mkdir -p $(OBJ_DIR)  # Ensure obj/ exists before compiling
			$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
			@$(RM) $(OBJ_DIR)
			@make clean -C $(LIBFT)

fclean:		clean
			$(RM) $(NAME)
			$(RM) $(LIBFT)/libft.a

re:			fclean all

.PHONY:		all clean fclean re norm

