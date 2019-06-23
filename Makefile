# utils
KRED=\033[0;31m
KGRN=\033[0;32m
KYEL=\033[0;33m
KNRM=\033[0m
COUNTER = 0

define compile_obj
	printf "$(KGRN)[draw]$(KNRM) compile $(1)\n"
	$(CC) $(CFLAGS) $(INCLUDES) -c $(1) -o $(2)
	$(eval COUNTER=$(shell echo $$(($(COUNTER) + 1))))
endef

# compiler
CC = gcc

# lib name
NAME = libdraw.a

# path
SRCDIR = srcs

OBJDIR = objs

INCDIR = includes

LIBFT_PATH = ../libft

GMATH_PATH = ../gmath

# compiler options
CFLAGS = -Wall -Wextra -Werror

INCLUDES = -I ./$(INCDIR)\
	-I $(LIBFT_PATH)/includes\
	-I $(GMATH_PATH)/includes\

# srcs
SRC_LINE = plot_line.c\

SRC_POLYGON = plot_polygon_line.c\
	polygon_scanline_fill.c\
	polygon_scanline_fill_utils.c\

SRC_RENDER = render.c\
	marker.c\
	z_buffer.c\

SRC_COLOR = fractal_palette.c\
	palette.c\
	pick_color.c\

SRC_UTILS = projection_vertices.c\

# objs
OBJS = $(addprefix $(OBJDIR)/, $(SRC_LINE:.c=.o))
OBJS += $(addprefix $(OBJDIR)/, $(SRC_POLYGON:.c=.o))
OBJS += $(addprefix $(OBJDIR)/, $(SRC_RENDER:.c=.o))
OBJS += $(addprefix $(OBJDIR)/, $(SRC_COLOR:.c=.o))
OBJS += $(addprefix $(OBJDIR)/, $(SRC_UTILS:.c=.o))

# compile objs
HEADERS = $(INCDIR)/draw.h\
	$(LIBFT_PATH)/includes/libft.h\
	$(LIBFT_PATH)/includes/get_next_line.h\
	$(GMATH_PATH)/includes/gmath.h\

$(OBJDIR)/%.o : $(SRCDIR)/line/%.c $(HEADERS)
	@$(call compile_obj,$<,$@)
$(OBJDIR)/%.o : $(SRCDIR)/polygon/%.c $(HEADERS)
	@$(call compile_obj,$<,$@)
$(OBJDIR)/%.o : $(SRCDIR)/render/%.c $(HEADERS)
	@$(call compile_obj,$<,$@)
$(OBJDIR)/%.o : $(SRCDIR)/color/%.c $(HEADERS)
	@$(call compile_obj,$<,$@)
$(OBJDIR)/%.o : $(SRCDIR)/utils/%.c $(HEADERS)
	@$(call compile_obj,$<,$@)

# build
all : $(NAME)

$(NAME) : pre_build $(OBJDIR) $(OBJS) post_build
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

pre_build :
	@printf "$(KGRN)[draw] $(KYEL)build $(NAME)\n$(KNRM)"

post_build :
	@printf "$(KGRN)[draw] $(KYEL)$(COUNTER) files compiled\n$(KNRM)"

$(OBJDIR) :
	@mkdir -p $(OBJDIR)

# commands
clean :
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

.PHONY : all pre_build post_build clean fclean re
