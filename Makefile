cc             := g++
cflags         := -std=c++14 -Wall -fpic
cflags_lib     := $(cflags) -shared

lib_headers    := lib/*.h lib/DBObjects/*.h
lib_src        := lib/*.cpp lib/DBObjects/*.cpp
lib_inc        := -Ilib -Ilib/DBObjects -I`pg_config --includedir`
lib_target     := -o bin/libcosmos.so
lib_links      := -L`pg_config --libdir` -lpq

client_headers := client/*.h
client_src     := client/*.cpp
client_inc     := -Iclient $(lib_inc)
client_target  := -o bin/cosmos
client_links   := -Lbin -lcosmos

client: libcosmos
	mkdir -p bin
	$(cc) $(cflags) $(client_target) $(client_inc) $(client_links) $(client_src)

libcosmos:
	mkdir -p bin
	$(cc) $(cflags_lib) $(lib_target) $(lib_inc) $(lib_links) $(lib_src)

clean:
	if [ -d bin ]; then rm -rf bin; fi
