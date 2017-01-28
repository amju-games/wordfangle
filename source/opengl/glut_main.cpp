// -----------------------------------------------------------------------------
// Wordfangle
// J Colman 2017
// -----------------------------------------------------------------------------

#include <iostream>
#include <cmath>
#include <stdio.h>
#ifdef MACOSX
#include <unistd.h>
#endif

#include "colour.h"
#include "gl_includes.h"
#include "gl_shader.h"
#include "gl_system.h"
#include "grid.h"
#include "rect.h"

static int WIN_X = 320;
static int WIN_Y = 480;

rect mouse_rect;
bool drag = false;
grid g(5, 5);

void draw()
{
  glUseProgram(0); // back to fixed function

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0, 320, 480, 0, -1, 1);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  glColor4f(1,1,1,1);
  //  glActiveTexture(GL_TEXTURE0);
  //  glBindTexture(GL_TEXTURE_2D, m_tex[1]);
  //  glEnable(GL_TEXTURE_2D);

  g.draw();
  mouse_rect.draw();
}


void display()
{
  //time_this_block("Rendering");

  GL_CHECK(glClearColor(.0, .9, .1, 1));
  GL_CHECK(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
  GL_CHECK(glEnable(GL_DEPTH_TEST));

  draw();
 
  glutSwapBuffers();

#ifdef MACOSX
  usleep(10000); // to stop my mac melting :(
#endif

  glutPostRedisplay();

}

void mouse_button(int button, int state, int x, int y)
{
  drag = (state == GLUT_DOWN);
  if (state == GLUT_DOWN)
  {
    g.set_mouse_anchor(x, y);
  }
}

void mouse_move(int x, int y)
{
  if (drag)
  {
    mouse_rect.x = x; //(float)x / 320.0f * 2.0f - 1.0f;
    mouse_rect.y = 480 - y; //(float)y / 480.0f * 2.0f - 1.0f;

    g.set_mouse(x, y);
  }
}

void key(unsigned char c, int x, int y)
{
}

int main(int argc, char** argv)
{
  glutInit(&argc, argv);

  // https://pleiades.ucsc.edu/hyades/OpenGL_on_OS_X
  glutInitDisplayMode(
      //GLUT_3_2_CORE_PROFILE | 
      GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);

  glutInitWindowSize(WIN_X, WIN_Y);
  glutCreateWindow("Hello"); 

#ifdef WIN32
  glewInit();
#endif


  glutDisplayFunc(display);
  glutMouseFunc(mouse_button);
  glutMotionFunc(mouse_move);
  glutMainLoop();
  return 0;
} 
