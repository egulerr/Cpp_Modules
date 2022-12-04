NAME = megaphone
CC = c++
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
SRCS = megaphone.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo $(B)megaphone is ready!

%.o: %.cpp
	@echo $(R)Complining [$<]
	@${CC} $(CFLAGS) -c $< -o $@ $(CFLAGS)

clean:
	@$(RM) $(OBJS)
	@echo $(R)Removed [$(OBJS)]

fclean: clean
	@$(RM) $(NAME)
	@echo $(R)Removed [$(NAME)]

re: fclean all

.PHONY: all, clean, fclean, re