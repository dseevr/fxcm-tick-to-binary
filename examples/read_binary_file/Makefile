OUTPUT=read_binary_file
OPTIMIZATIONS=-O2 -fno-exceptions
JEMALLOC=-ljemalloc -L/usr/local/Cellar/jemalloc/3.6.0/lib -I/usr/local/Cellar/jemalloc/3.6.0/include
CFLAGS=-std=c++1y -pedantic -stdlib=libc++ -Bstatic
WARNINGS=-Weverything
WARNINGS_DISABLED=-Wno-padded -Wno-c++98-compat -Wno-c++98-compat-pedantic

all:
	clang++ $(OPTIMIZATIONS) $(CFLAGS) $(JEMALLOC) $(WARNINGS) $(WARNINGS_DISABLED) \
	*.cpp \
	-o $(OUTPUT) && strip $(OUTPUT)

clean:
	rm *.o $(OUTPUT)
