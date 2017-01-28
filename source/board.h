// ----------------------------------------------------------------------------
// Wordfangle
// J Colman 2017
// ----------------------------------------------------------------------------

#pragma once

#include <vector>
#include "tile.h"

// * board class *
// Represents playing area.
class board
{
public:
  void init(int w, int h);
  virtual ~board() {}

  int get_w() const;
  int get_h() const;

  // Return random letter of alphabet, weighted by frequency?
  // Or not random at all, picked from level data.
  virtual std::string get_random_letter();

  const tile_row& get_row(int r) const;
  tile_row get_column(int c) const; // made on fly, so not a reference

  void rotate_row_right(int r);
  void rotate_row_left(int r);
  void rotate_col_up(int r);
  void rotate_col_down(int r);

  // Creates blanks in all tiles in row r.
  void clear_row(int r);

  // Concat all letters on board, excluding blanks (created by clear_row()).
  std::string collect_all_letters() const;

  void print() const;
 
private:
  std::vector<tile_row> m_tiles;
};

