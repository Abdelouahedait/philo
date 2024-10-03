CC = clang
CFLAGS = -Wall -Wextra -Werror 
RM = rm -rf
THR = -fsanitize=thread -g -O1

TSAN_OPTIONS = second_deadlock_stack=1


NAME = Philo
LIB = libft/libft.a
SRC =	src/main.c src/observer.c src/routine.c src/init.c src/utils.c \
		src/thread.c  

PURPLE = \033[0;35m
CYAN = \033[0;36m

all: ${NAME}
	@printf "\n"
	@printf "$(PURPLE)╔══════╗  $(PURPLE)╔══╗   ╔══╗     $(PURPLE)╔══════╗$(CYAN)    ╔══╗       $(CYAN)        \n"
	@printf "$(PURPLE)║██████║  $(PURPLE)║██║   ║██║     $(PURPLE)║██████║$(CYAN)    ║██║       $(CYAN)    ██████   \n"
	@printf "$(PURPLE)║██   █║  $(PURPLE)║██║═══║██║     $(PURPLE) ═║██║═ $(CYAN)    ║██║       $(CYAN)   ██╔═══██╗ \n"
	@printf "$(PURPLE)║██████║  $(PURPLE)║█████████║     $(PURPLE)  ║██║  $(CYAN)    ║██║       $(CYAN)   ██║   ██║ \n"
	@printf "$(PURPLE)║██║      $(PURPLE)║██║═══║██║     $(PURPLE) ═║██║═ $(CYAN)    ║██╚═════╗ $(CYAN)   ██║   ██║ \n"
	@printf "$(PURPLE)║██║      $(PURPLE)║██║   ║██║     $(PURPLE)║██████║$(CYAN)    ║████████║ $(CYAN)    ██████╔╝\n"
	@printf "$(PURPLE)╚══╝      $(PURPLE)╚══╝   ╚══╝     $(PURPLE)╚══════╝$(CYAN)    ╚════════╝ $(CYAN)     ╚════╝ \n"


${LIB}:
	make	all -C  libft



${NAME}: ${SRC} ${LIB} 
	${CC} ${THR} ${CFLAGS} ${SRC} ${LIB}  -o ${NAME}

clean:
	make clean -C  libft
	${RM} ${NAME}

fclean: clean
	${MAKE} fclean -C  libft -s
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re