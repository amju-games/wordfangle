all:wordfangle_tests_exe

clean:
	rm wordfangle_tests *.o ../*.o ../macosx/*.o 

run:
	cp wordfangle_tests ../../assets/; cd ../../assets/; ./wordfangle_tests; cd -
# NB run tests from assets/ dir, so we can load assets within the tests


CC=clang++

WARNINGS=-Wall -Wno-deprecated-declarations

INCLUDES=\
  -I.. \
  -I../thirdparty/googletest/include \
  -I../macosx

CFLAGS=-c $(WARNINGS) $(INCLUDES) -std=c++11   -DMACOSX

LDFLAGS=../thirdparty/googletest/make/gtest.a -framework OpenGL -framework GLUT 

SOURCES=test_main.cpp \
board_tests.cpp \
../board.cpp \
../log.cpp \
../tile.cpp

OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=wordfangle_tests

wordfangle_tests_exe: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

