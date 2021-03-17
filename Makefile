NAME = a.out

CC = clang++
CFLAG = -Wall -Wextra -Werror -std=c++98 -g -fsanitize=address

SRCS = main.cpp

all: $(NAME)

clean:
	@rm -f $(NAME)

$(NAME): $(SRCS)
	@$(CC) $(CFLAG) -o $(NAME) $(SRCS)
