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

using tile_row = std::deque<tile>;


