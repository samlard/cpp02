#---------------------------------------------------------#

CC              =       c++

CFLAGS  =       -Wall -Wextra -Werror -std=c++98 


#---------------------------------------------------------#

SRC_DIR =       src

SRC             =  $(shell find $(SRC_DIR) -type f -name "*.cpp")

OBJ_DIR =       obj

OBJ             =       $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

INC_DIR =	include
#---------------------------------------------------------#

NAME    =	fixed

all:            $(NAME)

$(NAME): $(OBJ) $(LIB)
	$(CC) $(CFLAGS) $(OBJ) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
#---------------------------------------------------------#

clean:
	rm -rf $(OBJ_DIR)

fclean:         clean
	rm -rf $(NAME) *dSYM

re: fclean all

.PHONY: all fclean clean re
#---------------------------------------------------------#