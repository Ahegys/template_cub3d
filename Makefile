#============ [FILES] ==========
NAME = render

FILES = main.c interface.c events.c pixel.c


OBJS = $(addprefix $(BUILDS)/, $(FILES:.c=.o))

DEP = $(OBJS:.o=.d)

#LIBFT = $(LIBFTDIR)libft.a

#================= [DIRS] ===================
SRCS = ./srcs
VPATH = render events
VPATH := $(SRCS) $(addprefix $(SRCS)/, $(VPATH))
HEADER = ./includes
HEADER := $(addprefix -I, $(HEADER))
#LIBFTDIR = ./libs/libft/
BUILDS = ./builds

#=================== [CONFIG_COMP] ==========
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
DEPFLAGS = -MMD -MF

#===================== [COMMANDS] ===========
DEL = rm -rf
MKDIR = mkdir -p

#=====================[MESSAGES]=============

DEL_MSG				= @printf "[\e[0;31m DEL \e[0m] "
BIN_MSG				= @printf "[\e[0;32m BIN \e[0m] "
BLD_MSG				= @printf "[\e[0;34m BLD \e[0m] "
MKD_MSG				= @printf "[\e[0;35m MKD \e[0m] "

# =================[BASIC_RULES] ============

all: $(NAME)

$(NAME): $(LIBFT) $(BUILDS) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(HEADER)  $(LIBFT) -o $(NAME) -lXext -lX11 -lmlx

clean:
	$(DEL) $(BUILDS)

fclean: clean
	$(DEL) ./render

re: fclean all

run:fclean all\
	./render
# =================[OTHER_RULES]============
$(BUILDS):
	@$(MKDIR) $@

$(BUILDS)/%.o:%.c
	$(BLD_MSG)
	@printf "Building ... %s\n" $@
	@$(CC) $(CFLAGS) -c $(HEADER) $< -o $@ $(DEPFLAGS) $(@:.o=.d)

run:re $(NAME)
	./render
	
gdb:all
	gdb --tui minishell

# ============ [Target-sepecific Directives]==========
.PHONY: all clean fclean re

# =============[Dependency Inclusion Directive] ======
-include ${DEP}