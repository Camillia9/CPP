NAME = RPN
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD -MP
SRCS = main.cpp RPN.cpp utils.cpp
OBJDIR := obj
OBJS = $(SRCS:%.cpp=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

-include $(DEP)

clean:
		rm -rf $(DEP) $(OBJDIR)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re