# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/28 15:18:28 by kjurkows          #+#    #+#              #
#    Updated: 2026/08/11 16:35:05 by kjurkows         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror -Iinclude

SHELL			=	/bin/bash

NAME			=	push_swap

TEST_NAME		=	push_swap_test
TEST_OUTPUT_DIR	=	test-output
TEST_SIZE		=	500
TEST_RUNS		=	42
TEST_OBJS_DIR	=	objs_test
TEST_OBJS		=	$(SRCS:%.c=$(TEST_OBJS_DIR)/%.o)
TEST_CFLAGS		=	$(CFLAGS) -DTEST

SRCS_DIR		=	src
OBJS_DIR		=	build
LIBS_DIR		=	lib

SRCS			=	main.c \
					disorder.c \
					bench.c \
					simple.c \
					medium.c \
					complex.c \
					parse.c \
					print_stack.c

OBJS			=	$(SRCS:%.c=$(OBJS_DIR)/%.o)

# module OPS
OPS_SRCS_DIR	=	$(SRCS_DIR)/ops
OPS_SRCS		=	ops.c \
					sa.c \
					sb.c \
					ss.c \
					pa.c \
					pb.c \
					ra.c \
					rb.c \
					rr.c \
					rra.c \
					rrb.c \
					rrr.c
OPS_OBJS_DIR	=	$(OBJS_DIR)/ops
OPS_OBJS		=	$(OPS_SRCS:%.c=$(OPS_OBJS_DIR)/%.o)
OPS_LIB			=	$(LIBS_DIR)/ops.a

# libft
LIBFT_DIR	=	libft
LIBFT		=	$(LIBFT_DIR)/libft.a
LIBFT_MAKE	=	$(LIBFT_DIR)/Makefile
LIBFT_FLAGS	=	-I$(LIBFT_DIR)
LIBFT_LINK	=	-L$(LIBFT_DIR) -lft

# libftprintf
FT_PRINTF_DIR	=	libftprintf
FT_PRINTF		=	$(FT_PRINTF_DIR)/libftprintf.a
FT_PRINTF_MAKE	=	$(FT_PRINTF_DIR)/Makefile
FT_PRINTF_FLAGS	=	-I$(FT_PRINTF_DIR)/includes
FT_PRINTF_LINK	=	-L$(FT_PRINTF_DIR) -lftprintf

all:				$(NAME)

$(NAME):			$(LIBFT) $(FT_PRINTF) $(OBJS) $(OPS_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LINK) $(FT_PRINTF_LINK) -o $@

$(OBJS_DIR)/%.o:	$(SRCS_DIR)/%.c	|	$(OBJS_DIR)
	$(CC) $(CFLAGS) $(LIBFT_FLAGS) $(FT_PRINTF_FLAGS) -c $< -o $@

# module OPS
$(OPS_LIB): $(OPS_OBJS) | $(LIBS_DIR)
	ar rcs $@ $<

$(OPS_OBJS_DIR)/%.o: $(OPS_SRCS_DIR)/%.c | $(OPS_OBJS_DIR)
	$(CC) $(CFLAGS) $(LIBFT_FLAGS) -c $< -o $@

$(OPS_OBJS_DIR): | $(OPS_OBJS_DIR)
	mkdir -p $(OPS_OBJS_DIR)
##

$(TEST_OBJS_DIR)/%.o:	$(SRCS_DIR)/%.c	|	$(TEST_OBJS_DIR)
	$(CC) $(TEST_CFLAGS) $(LIBFT_FLAGS) $(FT_PRINTF_FLAGS) -c $< -o $@

# libft
$(LIBFT):
	git submodule update --init --recursive libft
	$(MAKE) -C $(LIBFT_DIR)

libft:		$(LIBFT)
##

# libftprintf
$(FT_PRINTF):
	git submodule update --init --recursive libftprintf
	$(MAKE) -C $(FT_PRINTF_DIR)

libftprintf:	$(FT_PRINTF)
##

# dirs
$(LIBS_DIR):
	mkdir -p $(LIBS_DIR)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)
##

$(TEST_NAME):		$(TEST_OBJS) $(LIBFT) $(FT_PRINTF)
	$(CC) $(TEST_CFLAGS) $(TEST_OBJS) $(LIBFT_LINK) $(FT_PRINTF_LINK) -o $@
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
	printf 'Push_swap benchmark results\nInput size: %s\nRuns per algorithm: %s\n\n' \
		"$$size" "$$runs" > "$$results_file"; \
	printf '%-10s %8s %10s %10s %10s\n' \
		'algorithm' 'runs' 'minimum' 'average' 'maximum' >> "$$results_file"; \
	for ((run = 1; run <= runs; run++)); do \
		input_file=$$(printf '%s/input-%s-run-%02d.txt' "$$output_dir" "$$size" "$$run"); \
		negative_count=$$((size / 2)); \
		positive_count=$$((size - negative_count)); \
		{ shuf -i 1-1000000 -n "$$negative_count" | sed 's/^/-/'; \
			shuf -i 1-1000000 -n "$$positive_count"; } | shuf > "$$input_file"; \
	done; \
	for algorithm in simple medium complex adaptive; do \
		minimum=''; maximum=0; total=0; \
		for ((run = 1; run <= runs; run++)); do \
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
		printf '%-10s %8s %10s %10s %10s\n' \
			"$$algorithm" "$$runs" "$$minimum" "$$average" "$$maximum" >> "$$results_file"; \
	done; \
	printf 'Benchmark results saved in %s\n' "$$results_file"

test-build:			$(TEST_NAME)
$(TEST_OBJS_DIR):
	mkdir -p $(TEST_OBJS_DIR)

lib/%: $(LIBS_DIR)/%.a

# cleaning
clean:
	if [ -f $(LIBFT_MAKE) ]; then $(MAKE) -C $(LIBFT_DIR) clean; fi
	if [ -f $(FT_PRINTF_MAKE) ]; then $(MAKE) -C $(FT_PRINTF_DIR) clean; fi
	rm -rf $(OBJS_DIR)
	rm -rf $(LIBS_DIR)
	rm -rf $(TEST_OBJS_DIR)

fclean: clean
	if [ -f $(LIBFT_MAKE) ]; then $(MAKE) -C $(LIBFT_DIR) fclean; fi
	if [ -f $(FT_PRINTF_MAKE) ]; then $(MAKE) -C $(FT_PRINTF_DIR) fclean; fi
	rm -f $(NAME)
	rm -f $(TEST_NAME)

re: fclean all
##

.PHONY: all clean fclean re test test-build libft libftprintf
