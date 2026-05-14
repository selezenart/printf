*This project has been created as part of the 42 curriculum by aselezen.*

# ft_printf

A custom implementation of the standard C `printf` function, developed as part of the 42 curriculum.

---

# Description

The goal of this project is to recreate the behavior of the standard `printf` function using variadic arguments in C.

`ft_printf` parses a format string, detects conversion specifiers, retrieves the corresponding arguments using `va_list`, and prints formatted output to standard output (`stdout`).

The project focuses on:
- understanding variadic functions,
- low-level formatted output,
- recursive number conversion,
- base conversion algorithms,
- memory-safe string handling,
- modular program structure.

This implementation supports the mandatory conversion specifiers required by the 42 subject and builds as a static library (`libftprintf.a`).

---

# Features

Supported conversion specifiers:

| Specifier | Description |
|---|---|
| `%c` | Character |
| `%s` | String |
| `%p` | Pointer address |
| `%d` | Signed decimal integer |
| `%i` | Signed decimal integer |
| `%u` | Unsigned decimal integer |
| `%x` | Hexadecimal (lowercase) |
| `%X` | Hexadecimal (uppercase) |
| `%%` | Percent sign |

Additional behaviors:
- `NULL` strings are printed as `(null)`
- `NULL` pointers are printed as `(nil)`
- Recursive printing is used for decimal and hexadecimal conversions
- Returns the total number of printed characters
- Returns `-1` if a write operation fails

---

# Project Structure

| File | Description |
|---|---|
| `ft_printf.h` | Header file and function prototypes |
| `ft_printf.c` | Main parsing loop and dispatcher |
| `putdata_utils.c` | Character/string output and base-printing helpers |
| `handler.c` | Conversion handlers |
| `Makefile` | Build rules for the static library |

---

# Instructions

## Compilation

Build the static library:

```bash
make
```

This generates:
- `libftprintf.a`
- object files (`*.o`)

Useful Makefile rules:

```bash
make        # build the library
make clean  # remove object files
make fclean # remove object files and library
make re     # rebuild everything
```

---

## Usage

Include the header file:

```c
#include "ft_printf.h"
```

Example:

```c
#include "ft_printf.h"

int	main(void)
{
	int	count;

	count = ft_printf(
		"Hello %s, value=%d, hex=%x, ptr=%p\n",
		"world",
		42,
		42,
		&count
	);
	ft_printf("Printed chars: %d\n", count);
	return (0);
}
```

Compile:

```bash
cc -Wall -Wextra -Werror main.c -L. -lftprintf -o test_printf
```

Run:

```bash
./test_printf
```

---

# Function Prototype

```c
int	ft_printf(const char *format, ...);
```

### Return Value

- Returns the number of printed characters
- Returns `-1` if a write operation fails

---

# Algorithm & Technical Choices

## Parsing Algorithm

The implementation uses a linear parsing algorithm:

1. Iterate through the format string character by character
2. If a regular character is found:
   - print it directly
3. If `%` is found:
   - inspect the next character
   - dispatch execution to the correct conversion handler
4. Continue until the end of the string

This approach provides:
- O(n) time complexity relative to format length
- simple control flow
- low memory overhead

---

## Variadic Arguments

The project uses the standard variadic argument macros from `<stdarg.h>`:

```c
va_start
va_arg
va_end
```

These macros allow runtime retrieval of arguments whose number and types are unknown at compile time.

---

## Recursive Number Printing

Decimal and hexadecimal conversions are implemented recursively.

Example strategy:
- divide the number by the base,
- recursively print the higher-order digits,
- print the current digit.

Example for hexadecimal:
- base = 16
- digits are selected from:
  - `"0123456789abcdef"`
  - `"0123456789ABCDEF"`

This recursive approach:
- avoids temporary buffers,
- reduces memory usage,
- simplifies digit ordering.

---

## Data Structures

The project intentionally uses minimal data structures.

Mainly used:
- primitive integer types,
- character arrays for digit lookup,
- pointers for string traversal,
- `va_list` for variadic argument handling.

No dynamic memory allocation is required for the mandatory implementation.

---

# Limitations

This implementation only includes the mandatory 42 conversions.

The following standard `printf` features are NOT implemented:
- flags (`-`, `+`, `#`, `0`, space)
- field width
- precision
- length modifiers (`l`, `ll`, `h`, etc.)
- floating-point conversions

---

# Resources

## Documentation & References

- The Open Group printf documentation  
  https://pubs.opengroup.org/onlinepubs/9699919799/functions/printf.html

- cppreference printf documentation  
  https://en.cppreference.com/w/c/io/fprintf

- Tutorial on variadic functions
  https://youtu.be/oDC208zvsdg?si=2ce2o07s5aUiY5XT

- 42 School subject page

---

## AI Usage

AI tools were used as supplementary learning and debugging assistance during development.

Used for:
- clarifying edge-case behavior of standard `printf`,
- improving README formatting and project documentation.

AI-generated code was not copied directly into the final mandatory implementation without manual understanding, adaptation, and testing.

---

# Notes

- Output is written to file descriptor `1` (`stdout`)
- The project follows the 42 Norm requirements
- The library is compatible with standard C compilation flags:

```bash
-Wall -Wextra -Werror
```
````
