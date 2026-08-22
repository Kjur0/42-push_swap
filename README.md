*This project has been created as part of the 42 curriculum by **ppalamio**, **kjurkows***

# ![push_swap](../../../../ayogun/42-project-badges/blob/main/badges/push_swapn.png)

## Description

__`push_swap`__  is a program that implements 3 different sorting algorithms by using a set of instruction utilized on the stack.

This project is using [libft](https://github.com/Kjur0/42-libft.git) and [ftprintf](https://github.com/Kjur0/42-ft_printf.git) written by [kjurkows](https://github.com/Kjur0).

## Instructions

### Compilation

To compile `push_swap`, you can use the provided Makefile. Run the following command in your terminal:

```bash
make
```

#### Makefile Targets

| Target   | Description                                                              |
|----------|--------------------------------------------------------------------------|
| `all`    | Compiles the `push_swap` program                                         |
| `clean`  | Removes object files                                                     |
| `fclean` | Removes object files and the `push_swap` program                         |
| `re`     | Cleans and re-compiles the project                                        |
| `test`   | Compiles the `push_swap_test` program and run a test with default values |

### Usage

`push_swap` accepts 3 types of parameters:

```bash
./push_swap --{algorithm} --bench "{stack}"
```

### Mandatory arguments

#### "{stack}"

The `{stack}` is an unique list of integers separated by space. It can be declared with or without quotes.

If the stack contains a duplicate integer, `push_swap` will exit and print "Error" to `stderr`.

### Optional arguments

#### --{algorithm}
| Options    | Description                                            |
|------------|--------------------------------------------------------|
| `simple`   | sort the stack by using a simple algorithm             |
| `medium`   | sort the stack by using a medium algorithm             |
| `complex`  | sort the stack by using a complex algorithm            |
| `adaptive` | sort the stack by using a adaptive algorithm (default) |

#### --bench
Writes to `stderr` a summary of the sorting process - what algorithm was used and the total amount of operations grouped by the type of operation.

### Example usage:

```bash
./push_swap -100 45 -28 -69 200

./push_swap --complex "5 4 3 2 1"

./push_swap --bench "4 -3 -5 -6 -2"

./push_swap --simple --bench 42 21 -128
```

Optional arguments need to be defined before the stack declaration, as it will result in error. They also cannot overlap.

### Testing

By default `make test` after compiling `push_swap_test` it will run 42 test for every algorithm with 500 unique integers for every iteration.

Parameters can be set dynamically like this:

```bash
make test TEST_SIZE=999 TEST_RUNS=5
```

Results are saved into `results.txt` displaying min/max/avg of operations grouped by the 3 implemented algorithms.

`push_swap_test` prints the stack at the start and the end of the program to display if it's sorted..

## Resources

### AI usage 

## Algorithms

### Simple algorithm ($`\textbf O(n^2)`$) [$`disorder\lt0.2`$]

Selected algorithm: Min/Max Selection Sort

### Medium algorithm ($`\textbf O(n \sqrt n)`$) [$`0.2\le disorder\lt0.5`$]

Selected algorithm: index-based bucket sort

### Complex algorithm ($`\textbf O (n\log n)`$) [$`disorder\ge0.5`$]

Selected algorithm: 

## Contributions
