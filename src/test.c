/*
 * test.c
 * 
 * Copyright 2020-2021 Alvarito050506 <donfrutosgomez@gmail.com>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; version 3 of the License.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */

#include <stdio.h>
#include <mcpi.h>

int main(int argc, char* argv[])
{
	mcpi_err_t err;
	mcpi_command_t command;

	command = mcpi_parse_command("package.command(0,arg,arg2)", &err);
	if (err.code)
	{
		printf("\x1b[1;31mSyntax Error:\x1b[0m at position %i, unexcepted character '\x1b[1m%c\x1b[0m'.\n", err.pos, err.chr);
		return -1;
	}
	printf("%s.%s(%s, %s, %s) /* Argument count: %i */\n", command.package, command.name, command.args[0], command.args[1], command.args[2], command.argc);
	return 0;
}
