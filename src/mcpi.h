/*
 * mcpi.h
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

#ifndef LIB_MCPI_H
#define LIB_MCPI_H

typedef struct mcpi_command_t
{
	char package[16];
	char name[32];
	char args[16][32];
	int argc;
} mcpi_command_t;

typedef struct mcpi_err_t
{
	char code;
	int pos;
	char chr;
} mcpi_err_t;

mcpi_command_t mcpi_parse_command(const char* string, mcpi_err_t* err);

#endif /* LIB_MCPI_H */
