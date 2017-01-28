// -----------------------------------------------------------------------------
// Wordfangle
// J Colman 2017
// -----------------------------------------------------------------------------

#include <iostream>
#include <cmath>
#include "grid.h"
#include "rect.h"

  void grid::draw()
  { 
    rect ghost;
    for (int i = 0; i < h; i++)
    { 
      for (int j = 0; j < w; j++)
      { 
        rect r(x + j * (tile_size + gap), y + i * (tile_size + gap), tile_size, tile_size); 
        if (dragging)
        {
          if (i == select_row && dragging_row)
          { 
            r.x += drag_row;

            ghost = r;
            ghost.col = colour(0, 1, 1, 1);
            if (drag_row > 0) // dragging right
            {
              ghost.x = drag_row + x - tile_size - gap; 
            }
            else
            {
              ghost.x = drag_row + x + w * (tile_size + gap); 
            }
          }
          
          if (j == select_col && dragging_col)
          { 
            r.y += drag_col;

            ghost = r;
            ghost.col = colour(0, 1, 1, 1);
            if (drag_col > 0) // dragging down
            {
              ghost.y = drag_col + y - tile_size - gap;
            }
            else
            {
              ghost.y = drag_col + y + h * (tile_size + gap);
            }
          }

        }
        
        r.col = colour(1, 1, 0.2, 1);
/*      
        if (   r.x       < mouse_x 
            && r.x + r.w > mouse_x 
            && r.y       < mouse_y 
            && r.y + r.h > mouse_y)
*/      
        if (i == select_row && j == select_col)
        { 
          r.col = colour(1, 0, 0, 1);
        }
         
        r.draw();
      }
    }
    ghost.draw();
  }

  void grid::set_mouse(int x, int y)
  {
    mouse_x = x;
    mouse_y = y;

    int dx = x - mouse_anchor_x;
    int dy = y - mouse_anchor_y;

    if (!dragging_row && !dragging_col)
    {
      if (std::abs(dx) > std::abs(dy))
      {
        dragging_row = true;
        drag_row = dx;
        drag_col = 0;
      }
      else
      {
        dragging_col = true;
        drag_col = dy;
        drag_row = 0;
      }
    }
    else if (dragging_row)
    {
      drag_row = dx;
    }
    else
    {
      drag_col = dy;
    }

  }

  void grid::set_mouse_anchor(int x_, int y_)
  {
    dragging = false;
    drag_col = 0;
    drag_row = 0;
    dragging_row = false;
    dragging_col = false;
    select_row = -1;
    select_col = -1;

    // Outside of grid?
    if (   x_ < x
        || x_ > (x + w * tile_size + (w - 1) * gap)
        || y_ < y
        || y_ > (y + h * tile_size + (h - 1) * gap))
    {
      std::cout << "Out of grid!\n";
      return;
    }

    dragging = true;
    mouse_anchor_x = x_;
    mouse_anchor_y = y_;

    // work out column
    int c = (x_ - x) / (tile_size + gap);
    // row
    int r = (y_ - y) / (tile_size + gap);
    std::cout << "Tapped on row " << r << " col " << c << "\n";
    select_row = r;
    select_col = c;
  }

