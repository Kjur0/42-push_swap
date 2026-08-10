*This project has been created as part of the 42 curriculum by **ppalamio**, **kjurkows***

<p align="center">
  <img src="https://raw.githubusercontent.com/ayogun/42-project-badges/refs/heads/main/badges/push_swapn.png" />
</p>

## Description

__`push_swap`__  that implements 3 different sorting algorithms by using a set of instruction utilized on the stack.

## Instructions

### Compilation

To compile the `push_swap`, you can use the provided Makefile. Simply run the following command in your terminal:

```bash
make
```

#### Makefile Targets

| Target   | Description                                                              |
|----------|--------------------------------------------------------------------------|
| `all`    | Compiles the `push_swap` program                                         |
| `clean`  | Removes object files                                                     |
| `fclean` | Removes object files and the `push_swap` program                         |
| `re`     | Cleans and recompiles the project                                        |
| `test`   | Compiles the `push_swap_test` program and run a test with default values |


### Testing

By default `make test` will run 42 test for every algorithm with 500 unique integers for every iteration.

Parameters can be set dynamically like this:

```bash
make test TEST_SIZE=999 TEST_RUNS=5
```

Results are saved into `results.txt` displaying min/max/avg of operations grouped by the 3 implemented algorithms.

## Resources

### AI usage 

## Algorithms

### Simple algorithm ($\textbf O(n^2)$) [$disorder\lt0.2$]

Selected algorithm: Min/Max Selection Sort

### Medium algorithm ($\textbf O(n \sqrt n)$) [$0.2\le disorder\lt0.5$]

Selected algorithm: index-based bucket sort



### Complex algorithm ($\textbf O(n \log n)$) [$disorder\ge0.5$]

Selected algorithm: 
