// ----------------------------------------------------------------------------
// Wordfangle
// J Colman 2017
// ----------------------------------------------------------------------------

#include <numeric>
#include "tile.h"

std::string concat_letters(const tile_row& row)
{
  std::string res = std::accumulate(
    row.begin(), 
    row.end(), 
    std::string(),
    [](const std::string& s, const tile& t) { return s + t.letter; }
  );
  return res;
}


