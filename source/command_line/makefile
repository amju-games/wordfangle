all:wordfangle_cli_exe

clean:
	rm wordfangle_cli *.o ../*.o ../macosx/*.o 

run:
	cp wordfangle_cli ../../assets/; cd ../../assets/; ./wordfangle_cli; cd -
# NB run tests from assets/ dir, so we can load assets within the tests

runhere:
	./wordfangle_cli

CC=clang++

WARNINGS=-Wall -Wno-deprecated-declarations

INCLUDES=\
  -I.. \
  -I../macosx

CFLAGS=-c $(WARNINGS) $(INCLUDES) -std=c++11   -DMACOSX

LDFLAGS=../thirdparty/googletest/make/gtest.a -framework OpenGL -framework GLUT 

SOURCES=main.cpp \
../board.cpp \
../log.cpp \
../tile.cpp \
../word_list.cpp

OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=wordfangle_cli

wordfangle_cli_exe: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

