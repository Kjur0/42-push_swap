# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/28 15:18:28 by kjurkows          #+#    #+#              #
#    Updated: 2026/08/06 19:59:22 by kjurkows         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -Iincludes

NAME		=	push_swap

SRCS_DIR	=	src
OBJS_DIR	=	objs

LIBFT_DIR	=	libft
LIBFT		=	$(LIBFT_DIR)/libft.a
LIBFT_MAKE	=	$(LIBFT_DIR)/Makefile
LIBFT_FLAGS	=	-I$(LIBFT_DIR)
LIBFT_LINK	=	-L$(LIBFT_DIR) -lft

SRCS		=	sa.c \
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
OBJS		=	$(SRCS:%.c=$(OBJS_DIR)/%.o)

all:	$(NAME):

$(NAME):			$(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LINK) -o $@

$(OBJS_DIR)/%.o:	$(SRCS_DIR)/%.c	|	$(OBJS_DIR)
	$(CC) $(CFLAGS) $(LIBFT_FLAGS) -c $< -o $@

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(LIBFT):			$(LIBFT_MAKE)
	$(MAKE) -C $(LIBFT_DIR)

$(LIBFT_MAKE):
	git submodule update --init --recursive

clean:
	if [ -f $(LIBFT) ]; then $(MAKE) -C $(LIBFT_DIR) clean; fi
	rm -rf $(OBJS_DIR)

fclean:				clean
	if [ -f $(LIBFT) ]; then $(MAKE) -C $(LIBFT_DIR) fclean; fi
	rm -f $(NAME)

re:					fclean all

libft:				$(LIBFT)

.PHONY: all clean fclean re libft
