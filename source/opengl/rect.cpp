// -----------------------------------------------------------------------------
// Wordfangle
// J Colman 2017
// -----------------------------------------------------------------------------

#include "gl_includes.h"
#include "rect.h"

  void rect::draw()
  { 
    glColor3f(col.r, col.g, col.b);
    glBegin(GL_QUADS);
    float x1 = x;
    float x2 = x + w;
    float y1 = y;
    float y2 = y + h;
    glTexCoord2d(0,0);glVertex2f(x1, y1);
    glTexCoord2d(1,0);glVertex2f(x2, y1);
    glTexCoord2d(1,1);glVertex2f(x2, y2);
    glTexCoord2d(0,1);glVertex2f(x1, y2);
    glEnd();
  }

