# ============================================================
#                          PROJECT
# ============================================================

Name = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror

# ============================================================
#                         COLORS
# ============================================================

RESET   = \033[0m
BOLD    = \033[1m

CYAN =  \033[38;5;111m

# ============================================================
#                        DIRECTORIES
# ============================================================

INC_DIR     = inc
OBJ_DIR     = obj

INCLUDES    = -I$(INC_DIR)
HEADER		= $(INC_DIR)/philosophers.h

# ============================================================
#                        SOURCES
# ============================================================

SRC = src/main.c

# ============================================================
#                        OBJECTS
# ============================================================

OBJ = $(SRC:src/%.c=$(OBJ_DIR)/%.o)

# ============================================================
#                        RULES
# ============================================================

All: $(Name)


$(Name): $(OBJ)
	@$(CC) $(CFLAGS) -o $(Name) $(OBJ)
	@echo "🧠 $(CYAN)$(BOLD)Compilation complete. Executable created: $(Name)$(RESET)"

$(OBJ_DIR)/%.o: src/%.c $(HEADER)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@echo "🧹 $(CYAN)$(BOLD)Cleaned up object files$(RESET)"

fclean: clean
	@rm -f $(Name)
	@echo "🧽 $(CYAN)$(BOLD)Cleaned up executable: $(Name)$(RESET)"

re: fclean All

.PHONY: All clean fclean re