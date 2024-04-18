NAME		:= philo

SRCS		:= main.c \
				checkers.c \
				utils.c \

OBJS		:=	$(SRCS:.c=.o)

CC			:=	cc

FLAGS		:=	-Wall -Wextra -Werror -g -fsanitize=address

RM			:=	rm -rf

AR			:=	ar rcs

all:	$(NAME)

$(NAME): $(OBJS)
		@echo "Compilation of $(NAME)!!!"
		@$(CC) $(FLAGS) $(SRCS) -o $(NAME)
		@echo "$(NAME) created!!✔️"
	
clean:
		@echo "Deleting $(NAME) objs!! ✔️"
		@$(RM) $(OBJS)

fclean:	clean
		@echo "Deleting $(NAME)!!✔️"
		@$(RM) $(NAME)

re:	fclean all 

.PHONY:  all clean fclean re 