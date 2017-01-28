// -----------------------------------------------------------------------------
// Wordfangle
// J Colman 2017
// -----------------------------------------------------------------------------

#include "board.h"
#include "log.h"
#include "wf_assert.h"

void board::init(int w, int h)
{
  m_tiles.reserve(h);
  for (int i = 0; i < h; i++)
  { 
    tile_row row;
    for (int j = 0; j < w; j++)
    {
      row.push_back(get_random_letter());
    }
    m_tiles.push_back(row);
  }
}

std::string board::get_random_letter()
{
  // TODO Create set of letters (once, up front) which allow you to make
  //  a bunch of words. 

  static int s_i = 0;
  int i = s_i % 26;
  s_i++;
  std::stringstream ss;
  ss << char(i + 'a');
  return ss.str();
}

int board::get_w() const
{
  wf_assert(!m_tiles.empty());
  return static_cast<int>(m_tiles[0].size());
}

int board::get_h() const
{
  return static_cast<int>(m_tiles.size());
}

const tile_row& board::get_row(int r) const
{
  wf_assert(r >= 0);
  wf_assert(r < m_tiles.size());
  wf_assert(!m_tiles.empty());
  return m_tiles[r];
}

tile_row board::get_column(int c) const
{
  wf_assert(!m_tiles.empty());
  wf_assert(c >= 0);
  wf_assert(c < m_tiles[0].size());

  tile_row col;
  for (const tile_row& r : m_tiles)
  {
    col.push_back(r[c]);
  }
  return col;
}

void board::rotate_row_right(int r)
{
  wf_assert(r >= 0);
  wf_assert(r < m_tiles.size());
  wf_assert(!m_tiles.empty());
  tile_row& row = m_tiles[r];
  row.push_front(row.back());
  row.pop_back();
}

void board::rotate_row_left(int r)
{
  wf_assert(r >= 0);
  wf_assert(r < m_tiles.size());
  wf_assert(!m_tiles.empty());
  tile_row& row = m_tiles[r];
  row.push_back(row.front());
  row.pop_front();
}

void board::rotate_col_up(int c)
{
  wf_assert(!m_tiles.empty());
  wf_assert(c >= 0);
  wf_assert(c < m_tiles[0].size());

  int h = get_h();
  tile t = m_tiles[0][c];
  for (int i = 0; i < h - 1; i++)
  {
    tile_row& row = m_tiles[i];
    tile_row& next_row = m_tiles[i + 1];
    row[c] = next_row[c];
  }
  m_tiles[h - 1][c] = t;
}

void board::rotate_col_down(int c)
{
  wf_assert(!m_tiles.empty());
  wf_assert(c >= 0);
  wf_assert(c < m_tiles[0].size());

  int h = get_h();
  tile t = m_tiles[h - 1][c];
  for (int i = h - 1; i > 0; i--)
  {
    tile_row& row = m_tiles[i];
    tile_row& prev_row = m_tiles[i - 1];
    row[c] = prev_row[c];
  }
  m_tiles[0][c] = t;
}

void board::print() const
{
  for (const tile_row& r : m_tiles)
  {
    msg m;
    for (const tile& t : r)
    {
      m << t.letter << " ";
    }
    log(m);
  }
}



