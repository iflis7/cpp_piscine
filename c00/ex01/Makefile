################################################################################
#                                     CONFIG                                   #
################################################################################

NAME	= phonebook
# CC 	= clang++
CC 		= g++
CFLAGS	= -Wall -Werror -Wextra -std=c++98
DFLAGS	= -MMD -MF $(@:.o=.d)
RM 		= rm -f
AUTHOR	= hsaadi
DATE	= $(shell date "+%d %B %T")
HASH	= 
NOVISU 	= 0 # 1 = no progress bar usefull when tty is not available

################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

src = main.cpp phoneBook.cpp contact.cpp 

obj = $(src:.cpp=.o)

################################################################################
#                                 Makefile rules                             #
################################################################################

all: header $(NAME)
	@echo "BOOM 💥💥💥💥💥 $(NAME) Compiled! 💯 $(DEFAULT)"

$(NAME): $(obj)
	-@$(CC) $(CFLAGS) -o $(NAME) $(obj)

%.o: %.cpp
	-@$(CC) $(CFLAGS) -c $< -o $@

clean: header
	-@$(RM) $(obj)

fclean: clean
	-@$(RM) $(NAME)

re: fclean all 

.PHONY: all clean fclean re header

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
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
	@echo "        ___  _____ ___  ___      _        "
	@echo "       /   |/ __  \|  \/  |     | |       "
	@echo "      / /| |\`' / /'| .  . | __ _| | _____ "
	@echo "     / /_| |  / /  | |\/| |/ _\` | |/ / _ \\"
	@echo "     \___  |./ /___| |  | | (_| |   <  __/"
	@echo "         |_/\_____/\_|  |_/\__,_|_|\_\___| "
	@echo
ifneq ($(HASH),)
	@printf "%b" "$(OBJ_COLOR)Name:	$(WARN_COLOR)$(NAME)@$(HASH)\n"
else
	@printf "%b" "$(OBJ_COLOR)Name:	$(WARN_COLOR)$(NAME)\n"
endif
	@printf "%b" "$(OBJ_COLOR)Author:	$(WARN_COLOR)$(AUTHOR)\n"
	@printf "%b" "$(OBJ_COLOR)Date: 	$(WARN_COLOR)$(DATE)\n\033[m"
	@printf "%b" "$(OBJ_COLOR)CC: 	$(WARN_COLOR)$(CC)\n\033[m"
	@printf "%b" "$(OBJ_COLOR)Flags: 	$(WARN_COLOR)$(CFLAGS)\n\033[m"
	@echo
