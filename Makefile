# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/28 15:18:28 by kjurkows          #+#    #+#              #
#    Updated: 2026/08/07 05:27:32 by ppalamio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -Iincludes

NAME		=	push_swap
TEST_OUTPUT_DIR	=	test-output

SRCS_DIR	=	src
OBJS_DIR	=	objs

LIBFT_DIR	=	libft
LIBFT		=	$(LIBFT_DIR)/libft.a
LIBFT_MAKE	=	$(LIBFT_DIR)/Makefile
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
				parse.c
				
OBJS		=	$(SRCS:%.c=$(OBJS_DIR)/%.o)

all:	$(NAME)

$(NAME):			$(OBJS) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LINK) $(FT_PRINTF_LINK) -o $@

$(OBJS_DIR)/%.o:	$(SRCS_DIR)/%.c	|	$(OBJS_DIR)
	$(CC) $(CFLAGS) $(LIBFT_FLAGS) $(FT_PRINTF_FLAGS) -c $< -o $@

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(LIBFT):			$(LIBFT_MAKE)
	$(MAKE) -C $(LIBFT_DIR)

$(LIBFT_MAKE):
	git submodule update --init --recursive

$(FT_PRINTF):			$(FT_PRINTF_MAKE)
	$(MAKE) -C $(FT_PRINTF_DIR)

$(FT_PRINTF_MAKE):
	git submodule update --init --recursive

clean:
	if [ -f $(LIBFT) ]; then $(MAKE) -C $(LIBFT_DIR) clean; fi
	if [ -f $(FT_PRINTF) ]; then $(MAKE) -C $(FT_PRINTF_DIR) clean; fi
	rm -rf $(OBJS_DIR)

fclean:				clean
	if [ -f $(LIBFT) ]; then $(MAKE) -C $(LIBFT_DIR) fclean; fi
	if [ -f $(FT_PRINTF) ]; then $(MAKE) -C $(FT_PRINTF_DIR) fclean; fi
	rm -f $(NAME)

re:					fclean all

test: 				$(NAME)
	@mkdir -p $(TEST_OUTPUT_DIR)
	@./$(NAME) --simple --bench "3 2 1" > $(TEST_OUTPUT_DIR)/simple.stdout 2> $(TEST_OUTPUT_DIR)/simple.stderr
	@./$(NAME) --simple "3 2 1" | ./checker_linux "3 2 1" > $(TEST_OUTPUT_DIR)/simple.checker.stdout 2> $(TEST_OUTPUT_DIR)/simple.checker.stderr
	@grep -qx "OK" $(TEST_OUTPUT_DIR)/simple.checker.stdout
	@./$(NAME) --medium --bench "5 1 4 2 3" > $(TEST_OUTPUT_DIR)/medium.stdout 2> $(TEST_OUTPUT_DIR)/medium.stderr
	@./$(NAME) --medium "5 1 4 2 3" | ./checker_linux "5 1 4 2 3" > $(TEST_OUTPUT_DIR)/medium.checker.stdout 2> $(TEST_OUTPUT_DIR)/medium.checker.stderr
	@grep -qx "OK" $(TEST_OUTPUT_DIR)/medium.checker.stdout
	@./$(NAME) --complex --bench "5 4 3 2 1" > $(TEST_OUTPUT_DIR)/complex.stdout 2> $(TEST_OUTPUT_DIR)/complex.stderr
	@./$(NAME) --complex "5 4 3 2 1" | ./checker_linux "5 4 3 2 1" > $(TEST_OUTPUT_DIR)/complex.checker.stdout 2> $(TEST_OUTPUT_DIR)/complex.checker.stderr
	@grep -qx "OK" $(TEST_OUTPUT_DIR)/complex.checker.stdout
	@./$(NAME) --adaptive --bench "1 2 3 4 5" > $(TEST_OUTPUT_DIR)/adaptive.stdout 2> $(TEST_OUTPUT_DIR)/adaptive.stderr
	@./$(NAME) --adaptive "1 2 3 4 5" | ./checker_linux "1 2 3 4 5" > $(TEST_OUTPUT_DIR)/adaptive.checker.stdout 2> $(TEST_OUTPUT_DIR)/adaptive.checker.stderr
	@grep -qx "OK" $(TEST_OUTPUT_DIR)/adaptive.checker.stdout
	@./$(NAME) --adaptive --bench "$$(shuf -i 1-100 | tr '\n' ' ')" > $(TEST_OUTPUT_DIR)/adaptive-100.stdout 2> $(TEST_OUTPUT_DIR)/adaptive-100.stderr
	@numbers=$$(shuf -i 1-100 | tr '\n' ' '); ./$(NAME) --adaptive "$$numbers" | ./checker_linux "$$numbers" > $(TEST_OUTPUT_DIR)/adaptive-100.checker.stdout 2> $(TEST_OUTPUT_DIR)/adaptive-100.checker.stderr; grep -qx "OK" $(TEST_OUTPUT_DIR)/adaptive-100.checker.stdout
	@./$(NAME) --adaptive --bench "$$(shuf -i 1-500 | tr '\n' ' ')" > $(TEST_OUTPUT_DIR)/adaptive-500.stdout 2> $(TEST_OUTPUT_DIR)/adaptive-500.stderr
	@numbers=$$(shuf -i 1-500 | tr '\n' ' '); ./$(NAME) --adaptive "$$numbers" | ./checker_linux "$$numbers" > $(TEST_OUTPUT_DIR)/adaptive-500.checker.stdout 2> $(TEST_OUTPUT_DIR)/adaptive-500.checker.stderr; grep -qx "OK" $(TEST_OUTPUT_DIR)/adaptive-500.checker.stdout
	@./$(NAME) "1 1" > $(TEST_OUTPUT_DIR)/duplicate.stdout 2> $(TEST_OUTPUT_DIR)/duplicate.stderr || true
	@./$(NAME) --unknown "1 2" > $(TEST_OUTPUT_DIR)/invalid-option.stdout 2> $(TEST_OUTPUT_DIR)/invalid-option.stderr || true
	@printf 'Test output saved in %s/\n' $(TEST_OUTPUT_DIR)

libft:				$(LIBFT)

.PHONY: all clean fclean re test libft libftprintf
