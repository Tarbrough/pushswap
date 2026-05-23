*This project has been created as part
of the 42 curriculum by jbauch*

# push_swap

This repository contains the 42 `push_swap` project by `jbauch`.

## Description

`push_swap` is a sorting program that computes a minimal sequence of stack operations to sort a list of integers. The program uses two stacks, `a` and `b`, and writes the required operations to standard output.

The implementation uses the following project files:

* `MAKEFILE` – root build script for `push_swap`
* `push_swap.h` – common header and function declarations
* `src/main.c` – program entry point
* `src/parse.c` – argument parsing and validation
* `src/stack_*` / operation files – stack utilities and stack operations
* `src/small_sorting.c` – sorting strategy for 2–5 values
* `src/radix.c` – radix sort for larger inputs
* `libft/` – library containing reusable helper functions

## Build

From the repository root, run:

```sh
make
```

This builds the `push_swap` executable and also builds `libft/libft.a` as a dependency.

Available targets:

* `make` – build `push_swap`
* `make clean` – remove object files and clean `libft`
* `make fclean` – remove `push_swap` and `libft/libft.a`
* `make re` – rebuild from scratch

## Usage

Run the program with a list of integers as arguments:

```sh
./push_swap 3 2 5 1 4
```

The program prints a valid sequence of operations such as:

* `sa`, `sb`, `ss`
* `pa`, `pb`
* `ra`, `rb`, `rr`
* `rra`, `rrb`, `rrr`

## Functions

| Function | Use |
| --- | --- |
| `parse_args` | Parse and validate command-line arguments into stack `a` |
| `print_error` | Print `Error` for invalid input |
| `stack_new` | Allocate a new stack node with a value |
| `stack_bottom` | Return the bottom node of a stack |
| `stack_push_top` | Push a node onto the top of a stack |
| `stack_push_bottom` | Push a node onto the bottom of a stack |
| `stack_pop_top` | Remove and return the top node of a stack |
| `stack_size` | Return the number of nodes in a stack |
| `free_stack` | Free all nodes in a stack |
| `sa` | Swap the top two elements of stack `a` |
| `sb` | Swap the top two elements of stack `b` |
| `ss` | Swap the top two elements of both stacks |
| `pa` | Push the top element from `b` to `a` |
| `pb` | Push the top element from `a` to `b` |
| `ra` | Rotate stack `a` upward (top to bottom) |
| `rb` | Rotate stack `b` upward (top to bottom) |
| `rr` | Rotate both stacks upward |
| `rra` | Reverse rotate stack `a` (bottom to top) |
| `rrb` | Reverse rotate stack `b` (bottom to top) |
| `rrr` | Reverse rotate both stacks |
| `assign_indexes` | Assign sorted ranks to stack values for radix sorting |
| `sort_small` | Sort small stacks of up to 5 values |
| `radix_sort` | Sort larger inputs using binary radix sort |

## Notes

* The project uses a linked stack implementation (`t_stack`) defined in `push_swap.h`
* Input validation includes duplicate detection and integer range checks
* `libft/` provides helper functions required by the project

## Author

`jbauch` – 42 Wolfsburg student

## Resources

Ai was used to generate lists of test-cases as well as to help formatting the readme.
No Ai was used for code generation purposes.
