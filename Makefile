# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/28 15:18:28 by kjurkows          #+#    #+#              #
#    Updated: 2026/08/22 23:21:58 by kjurkows         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror -Iinclude -g
SHELL			=	/bin/bash

NAME			=	push_swap

SRCS_DIR		=	src
OBJS_DIR		=	build
LIBS_DIR		=	lib

RED				=	\033[;31m
GREEN			=	\033[;32m
YELLOW			=	\033[;33m
BLUE			=	\033[;34m
MAGENTA			=	\033[;35m
CYAN			=	\033[;36m
RESET			=	\033[0m
POSITION		=	\033[2K\r

MAKEFLAGS		+=	--no-print-directory

all:				$(NAME)
	@echo -e "$(GREEN)$(NAME) is ready to use.$(RESET)"

clean:
	@if [ -f $(FT_PRINTF_MAKE) ]; then \
		echo -ne "$(YELLOW)Cleaning libftprintf...$(RESET) "; \
		$(MAKE) -C $(FT_PRINTF_DIR) clean > /dev/null; \
		echo -e "$(POSITION)$(RED)libftprintf cleaned successfully!$(RESET)"; \
	fi
	@echo -ne "$(YELLOW)Cleaning object files...$(RESET) "
	@rm -rf $(OBJS_DIR)
	@rm -rf $(LIBS_DIR)
	@echo -e "$(POSITION)$(RED)Cleaned object files.$(RESET)"

fclean:				clean
	@if [ -f $(FT_PRINTF_MAKE) ]; then \
		echo -ne "$(YELLOW)Fully cleaning libftprintf...$(RESET) "; \
		$(MAKE) -C $(FT_PRINTF_DIR) fclean > /dev/null; \
		echo -e "$(POSITION)$(RED)libftprintf fully cleaned successfully!$(RESET)"; \
	fi
	@echo -ne "$(YELLOW)Removing $(NAME)...$(RESET) "
	@rm -f $(NAME)
	@echo -e "$(POSITION)$(RED)Fully cleaned all generated files.$(RESET)"

re:					fclean all
	@echo -e "$(GREEN)Rebuild complete!$(RESET)"

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_DIR)/parser
	@echo -e "$(CYAN)Created objects directory.$(RESET)"

$(LIBS_DIR):
	@mkdir -p $(LIBS_DIR)
	@echo -e "$(CYAN)Created libs directory.$(RESET)"

# libftprintf
FT_PRINTF_DIR	=	libftprintf
FT_PRINTF		=	$(FT_PRINTF_DIR)/libftprintf.a
FT_PRINTF_MAKE	=	$(FT_PRINTF_DIR)/Makefile
FT_PRINTF_FLAGS	=	-I$(FT_PRINTF_DIR)/include -I$(FT_PRINTF_DIR)/libft
FT_PRINTF_LINK	=	-L$(FT_PRINTF_DIR) -lftprintf

$(FT_PRINTF):
	@echo -ne "$(BLUE)Initializing and updating libftprintf submodule...$(RESET) "
	@git submodule update --init --recursive libftprintf > /dev/null 2>&1
	@echo -e "$(POSITION)$(GREEN)libftprintf submodule is ready!$(RESET)"
	@echo -ne "$(BLUE)Compiling libftprintf...$(RESET) "
	@$(MAKE) -C $(FT_PRINTF_DIR) bonus > /dev/null
	@echo -e "$(POSITION)$(GREEN)libftprintf has been compiled successfully!$(RESET)"

libftprintf:		$(FT_PRINTF)
##

# libft
LIBFT_DIR		=	libftprintf/libft
LIBFT			=	$(LIBFT_DIR)/libft.a
LIBFT_FLAGS		=	-I$(LIBFT_DIR)
LIBFT_LINK		=	-L$(LIBFT_DIR) -lft

$(LIBFT):			$(FT_PRINTF)

libft:				$(LIBFT)
##

# module STACK
STACK_SRCS_DIR	=	$(SRCS_DIR)/stack
STACK_SRCS		=	ops/ops.c \
					ops/sa.c \
					ops/sb.c \
					ops/ss.c \
					ops/pa.c \
					ops/pb.c \
					ops/ra.c \
					ops/rb.c \
					ops/rr.c \
					ops/rra.c \
					ops/rrb.c \
					ops/rrr.c \
					s_stack/init.c \
					s_stack/free.c \
					s_stack/last.c \
					s_stack/new.c \
					s_stack/add.c \
					normalize.c
STACK_OBJS_DIR	=	$(OBJS_DIR)/stack
STACK_OBJS		=	$(STACK_SRCS:%.c=$(STACK_OBJS_DIR)/%.o)
STACK_LIB		=	$(LIBS_DIR)/stack.a

$(STACK_LIB): $(STACK_OBJS) | $(LIBS_DIR)
	@echo -ne "$(BLUE)Compiling module STACK...$(RESET) "
	@ar rcs $@ $^
	@echo -e "$(POSITION)$(GREEN)Module STACK compiled successfully!$(RESET)"

$(STACK_OBJS_DIR)/%.o: $(STACK_SRCS_DIR)/%.c | $(STACK_OBJS_DIR) $(FT_PRINTF)
	@echo -ne "$(YELLOW)Compiling $(basename $(notdir $<))...$(RESET) "
	@$(CC) $(CFLAGS) $(LIBFT_FLAGS) -c $< -o $@
	@echo -e "$(POSITION)$(GREEN)Compiled $(basename $(notdir $<)) successfully!$(RESET)"

$(STACK_OBJS_DIR): | $(OBJS_DIR)
	@mkdir -p $(STACK_OBJS_DIR)
	@mkdir -p $(STACK_OBJS_DIR)/ops
	@mkdir -p $(STACK_OBJS_DIR)/s_stack
	@echo -e "$(CYAN)Created stack objects directory.$(RESET)"

modSTACK: $(STACK_LIB)
##

# module ALGS
ALGS_SRCS_DIR	=	$(SRCS_DIR)/algorithms
ALGS_SRCS		=	complex/algorithm.c \
					complex/meta.c \
					complex/meta_helpers.c
ALGS_OBJS_DIR	=	$(OBJS_DIR)/algs
ALGS_OBJS		=	$(ALGS_SRCS:%.c=$(ALGS_OBJS_DIR)/%.o)
ALGS_LIB		=	$(LIBS_DIR)/algs.a

$(ALGS_LIB): $(ALGS_OBJS) $(STACK_LIB) | $(LIBS_DIR)
	@echo -ne "$(BLUE)Compiling module ALGS...$(RESET) "
	@ar rcs $@ $^
	@echo -e "$(POSITION)$(GREEN)Module ALGS compiled successfully!$(RESET)"

$(ALGS_OBJS_DIR)/%.o: $(ALGS_SRCS_DIR)/%.c $(STACK_LIB) | $(ALGS_OBJS_DIR)
	@echo -ne "$(YELLOW)Compiling $(basename $(notdir $<))...$(RESET) "
	@$(CC) $(CFLAGS) $(LIBFT_FLAGS) -c $< -o $@
	@echo -e "$(POSITION)$(GREEN)Compiled $(basename $(notdir $<)) successfully!$(RESET)"

$(ALGS_OBJS_DIR): | $(OBJS_DIR)
	@mkdir -p $(ALGS_OBJS_DIR)
	@mkdir -p $(ALGS_OBJS_DIR)/complex
	@echo -e "$(CYAN)Created algs objects directory.$(RESET)"

modALGS: $(ALGS_LIB)
##

SRCS			=	main.c \
					parser/parser.c

OBJS			=	$(SRCS:%.c=$(OBJS_DIR)/%.o)

$(NAME):			$(STACK_LIB) $(ALGS_LIB) $(FT_PRINTF) $(LIBFT) $(OBJS)
	@echo -ne "$(BLUE)Creating $(NAME)...$(RESET) "
	@$(CC) $(CFLAGS) $(OBJS) $(ALGS_LIB) $(STACK_LIB) $(LIBFT_LINK) $(FT_PRINTF_LINK) -o $@
	@echo -e "$(POSITION)$(GREEN)$(NAME) has been created successfully!$(RESET)"

$(OBJS_DIR)/%.o:	$(SRCS_DIR)/%.c	|	$(OBJS_DIR) $(FT_PRINTF)
	@echo -ne "$(YELLOW)Compiling $(basename $(notdir $<))...$(RESET) "
	@$(CC) $(CFLAGS) $(LIBFT_FLAGS) $(FT_PRINTF_FLAGS) -c $< -o $@
	@echo -e "$(POSITION)$(GREEN)Compiled $(basename $(notdir $<)) successfully!$(RESET)"

# testing
TEST_NAME		=	push_swap_test
TEST_OUTPUT_DIR	=	test-output
TEST_SIZE		=	500
TEST_RUNS		=	42
TEST_OBJS_DIR	=	objs_test
TEST_OBJS		=	$(SRCS:%.c=$(TEST_OBJS_DIR)/%.o)
TEST_CFLAGS		=	$(CFLAGS) -DTEST

$(TEST_OBJS_DIR):
	@mkdir -p $(TEST_OBJS_DIR)
	@echo -e "$(CYAN)Created test objects directory.$(RESET)"

$(TEST_OBJS_DIR)/%.o:	$(SRCS_DIR)/%.c	|	$(TEST_OBJS_DIR) $(FT_PRINTF)
	@echo -ne "$(YELLOW)Compiling $(basename $(notdir $<))...$(RESET) "
	@$(CC) $(TEST_CFLAGS) $(LIBFT_FLAGS) $(FT_PRINTF_FLAGS) -c $< -o $@
	@echo -e "$(POSITION)$(GREEN)Compiled $(basename $(notdir $<)) successfully!$(RESET)"

$(TEST_NAME):		clean_test $(TEST_OBJS) $(LIBFT) $(FT_PRINTF) $(STACK_LIB)
	@echo -ne "$(BLUE)Creating $(TEST_NAME)...$(RESET) "
	@$(CC) $(TEST_CFLAGS) $(TEST_OBJS) $(STACK_LIB) $(LIBFT_LINK) $(FT_PRINTF_LINK) -o $@
	@echo -e "$(POSITION)$(GREEN)$(TEST_NAME) has been created successfully!$(RESET)"

test-build:			$(TEST_NAME)

test:				$(TEST_NAME)
	@set -euo pipefail; \
	output_dir="$(TEST_OUTPUT_DIR)"; \
	size="$(TEST_SIZE)"; \
	runs="$(TEST_RUNS)"; \
	results_file="results.txt"; \
	if ! [[ "$$size" =~ ^[0-9]+$$ ]] || ((size < 2 || size > 2000000)); then \
		printf 'TEST_SIZE must be an integer between 2 and 2000000.\n' >&2; exit 1; \
	fi; \
	if ! [[ "$$runs" =~ ^[0-9]+$$ ]] || ((runs < 1)); then \
		printf 'TEST_RUNS must be a positive integer.\n' >&2; exit 1; \
	fi; \
	if [[ ! -x ./checker_linux ]]; then \
		printf 'checker_linux is required to run the benchmark.\n' >&2; exit 1; \
	fi; \
	rm -rf "$$output_dir"; \
	trap 'rm -rf "$$output_dir"' EXIT; \
	mkdir -p "$$output_dir"; \
	printf '$(CYAN)Benchmarking push_swap: size=%s, runs=%s per algorithm$(RESET)\n' "$$size" "$$runs"; \
	printf 'Push_swap benchmark results\nInput size: %s\nRuns per algorithm: %s\n\n' \
		"$$size" "$$runs" > "$$results_file"; \
	printf '%-10s %8s %10s %10s %10s\n' \
		'algorithm' 'runs' 'minimum' 'average' 'maximum' >> "$$results_file"; \
	printf '$(BLUE)Generating %s input files...$(RESET)' "$$runs"; \
	for ((run = 1; run <= runs; run++)); do \
		input_file=$$(printf '%s/input-%s-run-%02d.txt' "$$output_dir" "$$size" "$$run"); \
		negative_count=$$((size / 2)); \
		positive_count=$$((size - negative_count)); \
		{ shuf -i 1-1000000 -n "$$negative_count" | sed 's/^/-/'; \
			shuf -i 1-1000000 -n "$$positive_count"; } | shuf > "$$input_file"; \
	done; \
	printf '$(POSITION)$(GREEN)Generated %s input files.$(RESET)\n' "$$runs"; \
	for algorithm in simple medium complex adaptive; do \
		minimum=''; maximum=0; total=0; \
		for ((run = 1; run <= runs; run++)); do \
			printf '$(POSITION)$(YELLOW)Running %-8s [%d/%d]...$(RESET)' "$$algorithm" "$$run" "$$runs"; \
			prefix=$$(printf '%s/%s-%s-run-%02d' "$$output_dir" "$$algorithm" "$$size" "$$run"); \
			input_file=$$(printf '%s/input-%s-run-%02d.txt' "$$output_dir" "$$size" "$$run"); \
			stdout_file="$$prefix.stdout"; stderr_file="$$prefix.stderr"; \
			checker_stdout="$$prefix.checker.stdout"; checker_stderr="$$prefix.checker.stderr"; \
			numbers=$$(tr '\n' ' ' < "$$input_file"); \
			./$(TEST_NAME) "--$$algorithm" --bench "$$numbers" > "$$stdout_file" 2> "$$stderr_file"; \
			sed '/^\[STACK /d' "$$stdout_file" | ./checker_linux "$$numbers" > "$$checker_stdout" 2> "$$checker_stderr"; \
			grep -qx 'OK' "$$checker_stdout"; \
			ops=$$(sed -n 's/^\[bench\] total_ops:[[:space:]]*//p' "$$stderr_file"); \
			if ! [[ "$$ops" =~ ^[0-9]+$$ ]]; then \
				printf 'Could not read the instruction count for %s run %s.\n' "$$algorithm" "$$run" >&2; exit 1; \
			fi; \
			if [[ -z "$$minimum" || "$$ops" -lt "$$minimum" ]]; then minimum=$$ops; fi; \
			if ((ops > maximum)); then maximum=$$ops; fi; \
			total=$$((total + ops)); \
		done; \
		average=$$(awk -v total="$$total" -v count="$$runs" 'BEGIN { printf "%.2f", total / count }'); \
		printf '$(POSITION)$(GREEN)%-8s done: min=%s avg=%s max=%s$(RESET)\n' \
			"$$algorithm" "$$minimum" "$$average" "$$maximum"; \
		printf '%-10s %8s %10s %10s %10s\n' \
			"$$algorithm" "$$runs" "$$minimum" "$$average" "$$maximum" >> "$$results_file"; \
	done; \
	printf '$(GREEN)Benchmark results saved in %s$(RESET)\n' "$$results_file"

clean_test:
	@rm -rf $(TEST_OBJS_DIR)
	@rm -f $(TEST_NAME)
	@echo -e "$(POSITION)$(RED)$(TEST_NAME) has been deleted!$(RESET)"

##

.PHONY: all clean fclean re modSTACK libftprintf libft test test-build clean_test
