CC = clang
CFLAGS = -Wall -Wextra -Werror 
RM = rm -rf
THR = -fsanitize=thread -g -O1

TSAN_OPTIONS = second_deadlock_stack=1


NAME = philo
LIB = libft/libft.a
SRC =	src/my_lib.c src/main.c src/observer.c src/routine.c src/init.c src/utils.c \
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




${NAME}: ${SRC} 
	${CC} ${THR} ${CFLAGS} ${SRC} -o ${NAME}

clean:
	${RM} ${NAME}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re