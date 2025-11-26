NAME	= violence

CC		= c++

CFLAGS	= -Wall -Wextra -Werror -std=c++11

SRCS	= main.cpp Weapon.cpp HumanA.cpp HumanB.cpp

OBJS	= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
