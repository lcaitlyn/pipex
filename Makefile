NAME		=	pipex

SRCS		= 	pipex.c pipex_utils.c\
				libft/ft_bzero.c libft/ft_calloc.c libft/ft_putstr.c\
				libft/ft_split.c libft/ft_strjoin.c libft/ft_strlen.c\
				libft/ft_strnstr.c libft/ft_substr.c\

OBJ			=	$(SRCS:%.c=%.o)

FLAGS		=	-Wall -Wextra -Werror

.PHONY		:	all clean fclean re

all			:	$(NAME)

%.o			:	%.c
					@gcc $(FLAGS) -c $< -o $@

$(NAME)		:	$(OBJ)
					@gcc $(FLAGS) -o $(NAME) $(OBJ)

clean		:	
					@rm -f $(OBJ)

fclean		:	clean
					@rm -f $(NAME)

re			:	fclean all
