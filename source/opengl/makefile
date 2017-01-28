all:wordfangle_glut_exe

clean:
	rm wordfangle_glut *.o ../*.o ../macosx/*.o 

run:
	cp wordfangle_glut ../../assets/; cd ../../assets/; ./wordfangle_glut; cd -
# NB run tests from assets/ dir, so we can load assets within the tests

CC=clang++

WARNINGS=-Wall -Wno-deprecated-declarations

INCLUDES=\
  -I.. \
  -I../macosx \
  -I../opengl

CFLAGS=-c $(WARNINGS) $(INCLUDES) -std=c++11   -DMACOSX

LDFLAGS=-framework OpenGL -framework GLUT 

SOURCES=glut_main.cpp \
../board.cpp \
../log.cpp \
../tile.cpp \
../word_list.cpp \
../opengl/gl_shader.cpp \
../opengl/gl_system.cpp \
../opengl/grid.cpp \
../opengl/rect.cpp

OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=wordfangle_glut

wordfangle_glut_exe: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

