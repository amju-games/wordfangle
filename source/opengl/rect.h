// -----------------------------------------------------------------------------
// Wordfangle
// J Colman 2017
// -----------------------------------------------------------------------------

#pragma once

#include "colour.h"

struct rect
{ 
  float x, y, w, h;
  float u0 = 0, u1 = 1, v0 = 0, v1 = 1;

  colour col;
  
  rect(float x_ = 0, float y_ = 0, float w_ = 1, float h_ = 1) :
    x(x_), y(y_), w(w_), h(h_) {}
  
  void draw();
};

