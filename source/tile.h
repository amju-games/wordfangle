// ----------------------------------------------------------------------------
// Wordfangle
// J Colman 2017
// ----------------------------------------------------------------------------

#pragma once

#include <deque>
#include <string>
#include <vector>

// * tile class *
// Represents one letter tile.
struct tile
{
  tile() {}
  tile(const std::string& letter_) { letter = letter_; }

  std::string letter;
  int score = 1;

  bool operator==(const tile& other) const { return letter == other.letter; }
};

#define WF_BLANK_LETTER "."

using tile_row = std::deque<tile>;

// Get the word formed by a tile_row
std::string concat_letters(const tile_row&);

