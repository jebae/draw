NAME = libdraw.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = srcs/*.c

INCLUDES = -I ./includes\
	-I ../libft/includes\
	-I ../gmath/includes\
	-I ../mlx\

OBJS = plot_line.o\
	plot_polygon_line.o\
	polygon_scanline_fill.o\
	polygon_scanline_fill_utils.o\
	display.o\
	projection_vertices.o\
	marker.o\
	z_buffer.o\

LIBS = ../libft/libft.a\
	   ../gmath/libgmath.a\
	   ../mlx/libmlx.a\

all : $(NAME)

$(NAME) : $(LIBS) $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(OBJS) :
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRCS)

$(LIBS) :
	$(MAKE) -C ../libft all
	$(MAKE) -C ../gmath all
	$(MAKE) -C ../mlx all

clean :
	$(MAKE) -C ../libft clean
	$(MAKE) -C ../gmath clean
	rm -rf $(OBJS)

fclean : clean
	$(MAKE) -C ../libft fclean
	$(MAKE) -C ../gmath fclean
	rm -rf $(NAME)

re : fclean all
