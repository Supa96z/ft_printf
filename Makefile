NAME = libftprintf.a

SOURCES = ft_printf.c\
		  ft_put1.c\
		  ft_put2.c\
		 
OBJECTS = $(SOURCES:.c=.o)
FLAGS = -Wall -Wextra -Werror
CC = gcc $(FLAGS)

$(NAME): $(SOURCES) $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)

all: $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)
