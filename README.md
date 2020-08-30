# libmcpi

A C library for interacting with and extending the Minecraft Pi Protocol.

## Getting Started
### Prerequisites
To build and use the library, you need:
 + A C99+ compiler (gcc, clang, bcc, etc.).
 + A standard C library (libc, uClibc, etc.)
 + A GNU-compatible Makefile proccessor.

### Download
If you are using a Raspberry Pi, you can download and install the Debian package from the _[releases](https://github.com/MCPI-Devs/libmcpi/releases)_ section.

You can also install it from the Packagecloud Debian repository:
```shell
# If you didn't add the repository yet
curl -s https://packagecloud.io/install/repositories/Alvarito050506/mcpi-devs/script.deb.sh | sudo bash

# Now the actual installation
sudo apt-get install libmcpi
```

## Build
You can build, test and install the sources using `make`:
```bash
make
make test-local # For testing before install
make install
make test-global # For testing after install
```

You can also build the Debian package using `make`:
```bash
make pack
```

## Usage
To use the API, you first need to include the `mcpi.h` header:
```c
#include <mcpi.h>
```

You also need to link the library using the `-l` option:
```
gcc -lmcpi your_program.c
```

## API
### `typedef struct mcpi_command_t`
Represents a Minecraft Pi API call:
```c
typedef struct mcpi_command_t
{
	char package[16];
	char name[32];
	char args[16][32];
	int argc;
} mcpi_command_t;
```

### `typedef struct mcpi_err_t`
Represents a Minecraft Pi API syntax error:
```c
typedef struct mcpi_err_t
{
	char code;
	int pos;
	char chr;
} mcpi_err_t;
```

### `mcpi_command_t parse_command(char* string, mcpi_err_t* err)`
Returns the parsed `string` as a `mcpi_command_t`. You should check the `err` output argument for errors.

## Licensing
All the code of this project is licensed under the [GNU Lesser General Public License version 3.0](https://github.com/MCPI-Devs/libmcpi/blob/master/LICENSE) (LGPL-3.0).

All the documentation of this project is licensed under the [Creative Commons Attribution-ShareAlike 4.0 International](https://creativecommons.org/licenses/by-sa/4.0/) (CC BY-SA 4.0) license.

![CC BY-SA 4.0](https://i.creativecommons.org/l/by-sa/4.0/88x31.png)
