# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/28 15:18:28 by kjurkows          #+#    #+#              #
#    Updated: 2026/08/11 20:52:44 by ppalamio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	cc
SHELL		=	/bin/bash
CFLAGS		=	-Wall -Wextra -Werror -Iincludes

NAME		=	push_swap
TEST_NAME	=	push_swap_test
TEST_OUTPUT_DIR	=	test-output
TEST_SIZE		=	500
TEST_RUNS		=	42

SRCS_DIR	=	src
OBJS_DIR	=	objs
TEST_OBJS_DIR	=	objs_test

LIBFT_DIR	=	libftprintf/libft
LIBFT		=	$(LIBFT_DIR)/libft.a
LIBFT_FLAGS	=	-I$(LIBFT_DIR)
LIBFT_LINK	=	-L$(LIBFT_DIR) -lft

FT_PRINTF_DIR	=	libftprintf
FT_PRINTF		=	$(FT_PRINTF_DIR)/libftprintf.a
FT_PRINTF_MAKE	=	$(FT_PRINTF_DIR)/Makefile
FT_PRINTF_FLAGS	=	-I$(FT_PRINTF_DIR)/includes
FT_PRINTF_LINK	=	-L$(FT_PRINTF_DIR) -lftprintf

SRCS		= main.c \
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
				rrr.c \
				disorder.c \
				bench.c \
				bench_count_a.c \
				bench_count_b.c \
				bench_count_c.c \
				simple.c \
				medium.c \
				complex.c \
				parse.c \
				print_stack.c \
				normalize.c
				
OBJS		=	$(SRCS:%.c=$(OBJS_DIR)/%.o)
TEST_OBJS	=	$(SRCS:%.c=$(TEST_OBJS_DIR)/%.o)
TEST_CFLAGS	=	$(CFLAGS) -DTEST

all:				libs $(OBJS) $(NAME)

libs:				submodules ftprintf

$(NAME):
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LINK) $(FT_PRINTF_LINK) -o $@

$(TEST_NAME):		$(TEST_OBJS) $(LIBFT) $(FT_PRINTF)
	$(CC) $(TEST_CFLAGS) $(TEST_OBJS) $(LIBFT_LINK) $(FT_PRINTF_LINK) -o $@

$(OBJS_DIR)/%.o:	$(SRCS_DIR)/%.c	|	$(OBJS_DIR)
	$(CC) $(CFLAGS) $(LIBFT_FLAGS) $(FT_PRINTF_FLAGS) -c $< -o $@

$(TEST_OBJS_DIR)/%.o:	$(SRCS_DIR)/%.c	|	$(TEST_OBJS_DIR)
	$(CC) $(TEST_CFLAGS) $(LIBFT_FLAGS) $(FT_PRINTF_FLAGS) -c $< -o $@

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(TEST_OBJS_DIR):
	mkdir -p $(TEST_OBJS_DIR)

$(FT_PRINTF):			$(FT_PRINTF_MAKE)
	$(MAKE) -C $(FT_PRINTF_DIR)

ftprintf:			$(FT_PRINTF)

submodules:
	git submodule update --init --recursive

clean:
	if [ -f $(LIBFT) ]; then $(MAKE) -C $(LIBFT_DIR) clean; fi
	if [ -f $(FT_PRINTF) ]; then $(MAKE) -C $(FT_PRINTF_DIR) clean; fi
	rm -rf $(OBJS_DIR)
	rm -rf $(TEST_OBJS_DIR)

fclean:				clean
	if [ -f $(LIBFT) ]; then $(MAKE) -C $(LIBFT_DIR) fclean; fi
	if [ -f $(FT_PRINTF) ]; then $(MAKE) -C $(FT_PRINTF_DIR) fclean; fi
	rm -f $(NAME)
	rm -f $(TEST_NAME)

re:					fclean all

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

.PHONY: all clean fclean re test test-build submodules libs libft libftprintf
