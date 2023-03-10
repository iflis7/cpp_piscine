################################################################################
#                                     CONFIG                                   #
################################################################################

NAME	= animal
NAME_T  = test
CC 		= c++
CFLAGS	= -Wall -Werror -Wextra -std=c++98
DFLAGS	= -MMD -MF $(@:.o=.d)
RM 		= rm -f
AUTHOR	= hsaadi
DATE	= $(shell date "+%d %B %T")
HASH	= 

################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

src = src/main.cpp src/Animal.cpp src/Dog.cpp src/Cat.cpp src/Brain.cpp

src_test = tests/TestAnimal.cpp 
#tests/TestDog.cpp tests/TestCat.cpp tests/TestBrain.cpp

obj = $(src:.cpp=.o)
obj_test = $(src_test:.cpp=.o)

################################################################################
#                                 Makefile rules                             #
################################################################################

all: header $(NAME)
	@echo "BOOM 💥💥💥💥💥 $(NAME) Compiled! 💯 $(DEFAULT)"

# test: $(NAME_T)
# 	@echo "BOOM 💥💥💥💥💥 $(NAME_T) Compiled! 💯 $(DEFAULT)"

$(NAME): $(obj)
	-@$(CC) $(CFLAGS) -o $(NAME) $(obj)

$(NAME_T): $(obj_test)
	-@$(CC) $(CFLAGS) -o $(NAME_T) $(obj_test)

%.o: %.cpp
	-@$(CC) $(CFLAGS) -c $< -o $@

clean: header
	-@$(RM) $(obj) $(obj_test)
	@echo "🧹🧹🧹🧹🧹🧹 $(NAME) Cleaned! 🧹🧹🧹🧹🧹🧹"

fclean: clean kabylia
	-@$(RM) $(NAME)
	

re: fclean all 

.PHONY: all clean fclean re header

#COLORS
RED = \033[1;31m
YELLOW = \033[1;33m
DEFAULT = \033[0m
COM_COLOR   = \033[0;34m
OBJ_COLOR   = \033[0;36m
OK_COLOR    = \033[0;32m
ERROR_COLOR = \033[0;31m
WARN_COLOR  = \033[0;33m
NO_COLOR    = \033[m

header:
	@printf "%b" "$(OK_COLOR)"
	@echo "        ___  _____ ___  ___       _        "
	@echo "       /   |/ __  \|  \/  |      | |       "
	@echo "      / /| |\`' / /'| .  . | __ _| | _____ "
	@echo "     / /_| |  / /  | |\/| |/ _\` | |/ / _ \\"
	@echo "     \___  |./ /___| |  | | (_| |   <  __/"
	@echo "         |_/\_____/\_|  |_/\__,_|_|\_\___| "
	@echo "                                           "

ifneq ($(HASH),)
	@printf "%b" "$(DEFAULT)Name:	$(OBJ_COLOR)$(NAME)@$(HASH)\n"
else
	@printf "%b" "$(DEFAULT)Name:	$(OBJ_COLOR)$(NAME)\n"
endif
	@printf "%b" "$(DEFAULT)Author:	$(OBJ_COLOR)$(AUTHOR)\n"
	@printf "%b" "$(DEFAULT)Date: 	$(OBJ_COLOR)$(DATE)\n\033[m"
	@printf "%b" "$(DEFAULT)CC: 	$(OBJ_COLOR)$(CC)\n\033[m"
	@printf "%b" "$(DEFAULT)Flags: 	$(OBJ_COLOR)$(CFLAGS)\n\033[m"
	@echo

summary:
	valgrind --leak-check=summary --trace-children=yes --track-fds=yes ./$(NAME)

valgrind:
	valgrind --leak-check=full  --show-leak-kinds=all --trace-children=yes --track-fds=yes ./$(NAME)

full:
	valgrind --leak-check=full ./$(NAME)

kabylia:
kabylia:
	@printf "%b" "$(WARN_COLOR)"
	@echo " ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿ "
	@echo " ⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠿⠿⠿⠿⠿⠻⠿⠿⠿⠿⠿⠿⠿⠿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠿⠛⠉⠉⠻⣿⣿⣿ "
	@echo " ⣿⡿⠿⣿⡿⠟⠛⠉⠠⠐⢀⠐⡀⠂⠄⡐⠀⢂⠐⢀⠂⡐⠠⠈⢸⠀⠈⠛⠻⣿⣿⣿⣿⣿⣿⠿⠋⠁⠀⠉⠁⠀⠀⠀⠀⠀⠀⠹⣿⣿ "
	@echo " ⣿⣷⠀⢠⠀⠂⡌⠀⢡⠐⠀⠂⢠⠈⠀⠐⠈⠀⠐⢠⠀⠐⠀⢡⢸⠀⠀⠀⠀⠘⣿⣿⣿⣿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⣿ "
	@echo " ⣿⣿⠀⢂⠈⡀⠄⡈⠄⠐⠠⢈⠀⢂⠁⠢⠑⠈⠄⣾⣞⡇⠐⠀⣾⡶⠀⠀⢰⣶⡎⠉⠉⠐⡀⠀⠀⠀⢀⣀⣀⣠⣶⣦⣤⣤⣶⣶⣶⣿ "
	@echo " ⣿⣿⣇⠀⠂⠄⡐⠀⠄⡁⠂⠄⡈⠀⢎⠂⠃⢋⠀⠙⠾⠷⠤⡥⣿⡽⠠⠤⠜⠓⠁⠀⠐⠪⡗⠌⠀⠀⠘⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿ "
	@echo " ⣿⣿⣿⣷⣬⣶⡄⠈⠄⠐⡀⢂⠠⠡⠘⣁⡝⡆⠠⢁⣤⣤⡤⠤⣿⡽⠤⠤⣀⣀⠀⠀⢠⠚⢗⢀⠀⠀⠀⠘⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿ "
	@echo " ⣿⣿⣿⣿⣿⣿⠃⡈⠐⠠⠐⠀⠄⠂⢁⠪⣑⠓⡄⣿⣻⠆⠀⡀⣿⣳⠀⠀⢸⣟⡇⢀⠬⣴⠃⠁⠀⠀⠀⠀⠈⢿⣿⣿⣿⣿⣿⣿⣿⣿ "
	@echo " ⣿⣿⣿⣿⣿⡟⠃⢀⠁⠂⠌⠐⠠⠁⠂⠢⣈⢡⣐⣈⢁⠁⠂⠄⢹⠀⠀⠀⠀⡠⠠⣈⠧⠀⠒⠀⠀⠀⠀⠀⠀⢺⣿⣿⣿⣿⣿⣿⣿⣿ "
	@echo " ⣿⣿⣿⣿⡟⠃⡐⠠⠈⠐⠠⠁⢂⠈⠄⢁⠀⡐⣆⢈⡠⡣⡨⢀⣸⠀⣀⢀⢦⡒⢌⠌⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⣿⣿ "
	@echo " ⣿⣿⣿⣿⣿⣿⣦⡀⡡⠈⠐⡀⠂⢤⣾⣶⣷⣶⣶⣿⡆⠓⠂⢁⢸⠈⠁⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⠀⠀⣸⣿⣿⣿⣿⣿⣿⣿ "
	@echo " ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣤⣃⣠⣀⣼⣿⣿⣿⣿⣿⡟⠀⡀⠃⣄⣸⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣧⣼⣿⣿⣿⣿⣿⣿⣿⣿ "
	@echo " ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣶⣿⣿⣿⣿⣷⣤⣀⠀⠀⠀⠀⠀⢠⣤⣤⣤⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿ "
	@echo " ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣦⣄⣀⣀⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿ "
	@echo " ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿ "
