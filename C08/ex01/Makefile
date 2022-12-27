NAME = iterator
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -g -std=c++98
RM = rm -rf
SRCS =	main.cpp	\
		Span.cpp	\

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CPP) $(CPPFLAGS) -o $(NAME) $(OBJS)
	@bash -c "clear"
	@echo $(B)Iterator is ready!

%.o: %.cpp
	@echo $(R)Complining [$<]
	@${CPP} $(CPPFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)
	@echo $(R)Removed [$(OBJS)]

fclean: clean
	@$(RM) $(NAME)
	@echo $(R)Removed [$(NAME)]

re: fclean all

.PHONY: all, clean, fclean, re