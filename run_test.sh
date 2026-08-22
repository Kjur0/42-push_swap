#!/bin/sh
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    run_test.sh                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/22 21:47:09 by kjurkows          #+#    #+#              #
#    Updated: 2026/08/22 22:03:07 by kjurkows         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

if [ $# -ne 1 ]; then
	echo "Usage: $0 <number_of_arguments>"
	exit 1
fi

shuf -i 0-9999 -n $1 > args

./push_swap $(cat args) | wc -l
./push_swap $(cat args) | ./checker_linux $(cat args)
