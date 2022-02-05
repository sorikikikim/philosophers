NAME = philo
HEADER = $(addsuffix .h, $(NAME))
CFLAGS = -Wall -Wextra -Werror
PTHREAD = -pthread
CC = gcc
RM = rm -f

SRCS =	init.c main.c thread.c utils.c utils2.c terminal_condition.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(PTHREAD) $^ -o $@

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) $(PTHREAD) -c $< -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all