cc             := g++
cflags         := -std=c++14 -Wall -fPIC
cflags_lib     := $(cflags) -shared

lib_headers    := src/lib/*.h src/lib/DBObjects/*.h
lib_src        := src/lib/*.cpp src/lib/DBObjects/*.cpp
lib_inc        := -Isrc/lib -Isrc/lib/DBObjects -I`pg_config --includedir`
lib_target     := -o lib/libcosmos.so
lib_links      := -L`pg_config --libdir` -lpq

client_headers := src/client/*.h
client_src     := src/client/*.cpp
client_inc     := -Isrc/client $(lib_inc)
client_target  := -o bin/cosmos
client_links   := -Llib -lcosmos

test_src       := src/test/unit/*.cpp
test_inc       := $(lib_inc)
test_target    := -o test/bin/run
test_links     := -L/Users/mpm/source/libcosmos/lib -lcosmos

client: libcosmos
	mkdir -p bin
	$(cc) $(cflags) $(client_target) $(client_inc) $(client_links) $(client_src)

libcosmos:
	mkdir -p lib
	$(cc) $(cflags_lib) $(lib_target) $(lib_inc) $(lib_links) $(lib_src)

test: libcosmos
	mkdir -p test/bin
	$(cc) $(cflags) $(test_target) $(test_inc) $(test_links) $(test_src)
	test/bin/run

clean:
	if [ -d bin ]; then rm -rf bin; fi
	if [ -d lib ]; then rm -rf lib; fi
	if [ -d test ]; then rm -rf test; fi
