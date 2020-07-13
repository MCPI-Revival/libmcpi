#
#  Makefile
#  
#  Copyright 2020 Alvarito050506 <donfrutosgomez@gmail.com>
#  
#  This program is free software; you can redistribute it and/or modify
#  it under the terms of the GNU Lesser General Public License as published by
#  the Free Software Foundation; version 3 of the License.
#  
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#  
#  You should have received a copy of the GNU General Public License
#  along with this program; if not, write to the Free Software
#  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
#  MA 02110-1301, USA.
#  
#  

all:
	mkdir -p build
	gcc -c -fPIC ./src/mcpi.c -I./ -o ./build/mcpi.o
	gcc -shared -fPIC ./build/mcpi.o -o ./build/libmcpi.so

install:
	cp ./build/libmcpi.so /usr/lib
	cp ./mcpi.h /usr/include
	chmod 0755 /usr/lib/libmcpi.so
	ldconfig

test-global:
	gcc ./test.c -lmcpi -o ./build/test.elf

test-local:
	gcc ./src/test.c -I./src/ -L./build/ -lmcpi -Wl,-rpath=./build/ -lmcpi -o ./build/test.elf

pack:
	mkdir -p ./deb/
	mkdir -p ./deb/usr/lib/
	mkdir -p ./deb/usr/include/
	mkdir -p ./deb/DEBIAN/
	cp ./build/libmcpi.so ./deb/usr/lib/
	cp ./mcpi.h ./deb/usr/include/
	chmod 0755 ./deb/usr/lib/libmcpi.so
	echo "Package: libmcpi\nVersion: 0.1.0\nPriority: optional\nArchitecture: armhf\nMaintainer: Alvarito050506 <donfrutosgomez@gmail.com>\nHomepage: https://mcpi.tk\nDescription: A C library for interacting with and extending the Minecraft Pi Protocol.\n" > ./deb/DEBIAN/control
	dpkg-deb -b ./deb/ ./libmcpi_0.1.0-1.deb

clean:
	rm -rf ./build/
	rm -rf ./deb/
	rm -f ./libmcpi_*-*.deb
