NAME = libdraw.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = srcs/*.c

INCLUDES = -I ./includes\
	-I ./libft/includes

OBJS = line.o\
	polygon_scanline_fill.o\
	polygon_scanline_fill_utils.o\

LIBS = libft/libft.a

all : $(NAME)

$(NAME) : $(LIBS) $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(OBJS) :
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRCS)

$(LIBS) :
	$(MAKE) -C libft all

clean :
	$(MAKE) -C libft clean
	rm -rf $(OBJS)

fclean : clean
	$(MAKE) -C libft fclean
	rm -rf $(NAME)

re : fclean all
