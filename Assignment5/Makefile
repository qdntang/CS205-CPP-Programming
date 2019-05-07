CC=gcc
CXX=g++
CFLAGS=-Wall -g
CXXFLAGS=-Wall -g -std=c++11

OBJ=utf8.o UTF8string.o testUTF8string.o

# link
main: $(OBJ)
	$(CXX) -o $@ $^ $(CXXFLAGS)

# compile only, C source
%.o: %.c %.h
	$(CC) -c -o $@ $< $(CFLAGS)

# compile only, C++ source
%.o: %.cpp %.hpp %.c %.h
	$(CXX) -c -o $@ $< $(CXXFLAGS)

clean:
	$(RM) $(OBJ)

run:
	./main
