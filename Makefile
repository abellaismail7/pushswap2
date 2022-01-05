CC 		= gcc
CCFLAGS = -Wall -Werror -Wextra -g
INCLUDE = -I./inc

FILES 	= pushswap instra2 swap swipedown swipeup sort stack strutils utils
S_DIR	= src
B_DIR	= build
OBJ		= $(addprefix $(B_DIR)/, 	$(FILES:=.o))
EXE		= pushswap

all: $(EXE)

$(EXE): $(OBJ)
	$(CC) $(CCFLAGS) $^ -o $@

$(B_DIR)/%.o: $(S_DIR)/%.c
	mkdir -p $(@D)
	$(CC) $(CCFLAGS) $(INCLUDE) -o $@ -c $<

clean:
	rm -f $(OBJ)
	rm -rf $(B_DIR)

fclean: clean
	rm -f $(LIB)

.PHONY: all clean fclean
