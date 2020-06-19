NAME	=	libmx.a

CFLG	=	-std=c11 -Wall -Wextra -Werror -Wpedantic -g
COMP 	= 	clang

SRCD	=	src
INCD	=	inc
OBJD	=	obj

INC		=	libmx.h
INCS	=	$(addprefix $(INCD)/, $(INC))

SRC	=		mx_printchar.c \
			mx_strlen.c \
			mx_printerr.c \
			mx_print_strarr.c \
			mx_itoa.c \
			mx_strcmp.c \
			mx_bubble_sort.c \
			mx_str_reverse.c \
			mx_strdel.c \
			mx_del_strarr.c \
			mx_get_char_index.c \
			mx_strdup.c \
			mx_strndup.c \
			mx_strcpy.c \
			mx_strncpy.c \
			mx_strcmp.c \
			mx_strnew.c \
			mx_isspace.c \
			mx_memchr.c \
			mx_count_words.c \
			mx_strtrim.c \
			mx_strsplit.c \
			mx_strjoin.c \

SRCS	=	$(addprefix $(SRCD)/, $(SRC))
OBJS	=	$(addprefix $(OBJD)/, $(SRC:%.c=%.o))

all: install clean
	
install: $(NAME)

$(NAME): $(OBJS)
	@libtool $^ -o libmx.a

$(OBJD)/%.o: $(SRCD)/%.c $(INCS)
	@$(COMP) $(CFLG) -c $< -o $@ -I$(INCD)

$(OBJS): | $(OBJD)

$(OBJD):
	@mkdir -p $@

clean:
	@rm -rf $(OBJD)

uninstall: clean
	@rm -rf $(NAME)

reinstall: uninstall install

start: 
	clang -std=c11 -Wall -Wextra -Werror -Wpedantic main.c libmx.a && ./a.out
