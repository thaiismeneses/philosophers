# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/29 12:30:36 by thfranco          #+#    #+#              #
#    Updated: 2024/05/21 13:58:19 by thfranco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= philo

SRCS		:= main.c \
			tools.c \
			check_args.c\
			init.c\
			mutex.c\
			thread.c\
			write.c\
			routine.c\
			getters_and_setters.c\
			monitor.c\


OBJS		:=	$(SRCS:.c=.o)

CC			:=	cc

FLAGS		:=	-Wall -Wextra -Werror -g -pthread

#-fsanitize=address

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

hell:
	valgrind --tool=helgrind ./$(NAME) 5 800 200 200 7

.PHONY:  all clean fclean re
