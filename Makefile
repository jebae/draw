NAME = libdraw.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = srcs/*.c

INCLUDES = -I ./includes\
	-I ../libft/includes\
	-I ../gmath/includes\

OBJS = plot_line.o\
	plot_polygon_line.o\
	polygon_scanline_fill.o\
	polygon_scanline_fill_utils.o\
	render.o\
	projection_vertices.o\
	marker.o\
	z_buffer.o\

LIBS = ../libft/libft.a\
	   ../gmath/libgmath.a\

all : $(NAME)

$(NAME) : $(LIBS) $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(OBJS) : $(SRCS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRCS)

$(LIBS) :
	$(MAKE) -C ../libft all
	$(MAKE) -C ../gmath all

clean :
	$(MAKE) -C ../libft clean
	$(MAKE) -C ../gmath clean
	rm -rf $(OBJS)

fclean : clean
	$(MAKE) -C ../libft fclean
	$(MAKE) -C ../gmath fclean
	rm -rf $(NAME)

re : fclean all
