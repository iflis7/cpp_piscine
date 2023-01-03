NAME = phonebook 

# CC = clang++
CC = g++
CFLAGS = -Wall -Wextra -Werror -I -std=c++98
RM = rm -f

src = main.cpp phoneBook.cpp contact.cpp 

obj = $(src:.cpp=.o)

all: $(NAME)
	@echo "BOOM 💥💥💥💥💥 $(NAME) Compiled! 💯 $(DEFAULT)"

$(NAME): $(obj)
	-@$(CC) $(CFLAGS) -o $(NAME) $(obj)

%.o: %.cpp
	-@$(CC) $(CFLAGS) -c $< -o $@

clean:
	-@$(RM) $(obj)

fclean: clean
	-@$(RM) $(NAME)

re: fclean all


#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m
 