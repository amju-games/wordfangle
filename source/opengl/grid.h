// -----------------------------------------------------------------------------
// Wordfangle
// J Colman 2017
// -----------------------------------------------------------------------------

#pragma once

struct grid
{
  int x = 50;
  int y = 70;
  int w, h;
  int tile_size = 30; 
  int gap = 10;
  int mouse_x = 0;
  int mouse_y = 0;
  int mouse_anchor_x = 0;
  int mouse_anchor_y = 0;
  int select_row = -1;
  int select_col = -1;
  bool dragging = false;
  int drag_col = 0;
  int drag_row = 0;
  bool dragging_row = false;
  bool dragging_col = false;

  grid(int w_, int h_) : w(w_), h(h_) {}

  int total_w() const { return w * (tile_size + gap) + gap; }
  int total_h() const { return h * (tile_size + gap) + gap; }

  void draw();

  void set_mouse(int x, int y);

  void set_mouse_anchor(int x_, int y_);
};



