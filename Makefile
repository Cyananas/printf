CC = gcc

FLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRCS_DIR = srcs/

INCS_DIR = ./

SRCS = ft_printf.c\
	srcs/ft_itoa.c\
	srcs/ft_strlen.c\
	srcs/ft_itoa_u.c\
	srcs/ft_parse.c\
	srcs/ft_atoi_size.c\
	srcs/ft_flags.c\
	srcs/ft_setup_form.c\
	srcs/ft_strdup.c\
	srcs/ft_strjoinfree.c\
	srcs/ft_substr.c\
	srcs/ft_write_c.c\
	srcs/ft_write_s.c\
	srcs/ft_write_d.c\
	srcs/ft_write_u.c\
	srcs/ft_write_x.c\
	srcs/ft_write_p.c\
	srcs/ft_write_other.c\

HEADERS = printf.h

OBJECT = ${SRCS:.c=.o}

all : $(NAME)

.c.o :
	${CC} ${FLAGS} -c -I $(INCS_DIR) $< -o ${<:.c=.o}

$(NAME): $(OBJECT) $(HEADERS)
	@ar rc $(NAME) $(OBJECT)
	@ranlib $(NAME)

clean:
	@rm -rf $(OBJECT)

fclean: clean
	@rm -rf $(NAME)

re : fclean all

.PHONY: re clean fclean
