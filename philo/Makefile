# ============================================================
#                          PROJECT
# ============================================================

NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread

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

SRC = 	src/main.c \
		src/simulation/simulation.c \
		src/simulation/free_table.c \
		src/simulation/monitor.c \
		src/simulation/init_structs.c \
		src/simulation/init_mutexes.c \
		src/simulation/destroy_mutexes.c \
		src/simulation/threads_life_cycle.c \
		src/utils/parsing.c \
		src/utils/sync_utils.c \
		src/utils/print_utils.c \
		src/utils/time_utils.c \
		src/routine/eat.c \
		src/routine/forks.c \
		src/routine/sleep.c \
		src/routine/routine.c \
		src/routine/think.c

# ============================================================
#                        OBJECTS
# ============================================================

OBJ = $(SRC:src/%.c=$(OBJ_DIR)/%.o)

# ============================================================
#                        RULES
# ============================================================

all: $(NAME)


$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@echo "🧠 $(CYAN)$(BOLD)Compilation complete. Executable created: $(NAME)$(RESET)"

$(OBJ_DIR)/%.o: src/%.c $(HEADER)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@echo "🧹 $(CYAN)$(BOLD)Cleaned up object files$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "🧽 $(CYAN)$(BOLD)Cleaned up executable: $(NAME)$(RESET)"

re: fclean all

.PHONY: all clean fclean re