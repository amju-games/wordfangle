// -----------------------------------------------------------------------------
// Wordfangle
// J Colman 2017
// -----------------------------------------------------------------------------

#include <sstream>
#include <gtest/gtest.h>
#include "board.h"

class mock_board : public board
{
public:
  virtual std::string get_random_letter() override
  {
    int i = m_i % 26;
    m_i++;
    std::stringstream ss;
    ss << char(i + 'a');
    return ss.str();
  }

private:
  int m_i = 0;
};

TEST(board, create)
{
  int BOARD_W = 9;
  int BOARD_H = 6;
  mock_board b;
  b.init(BOARD_W, BOARD_H);
  ASSERT_EQ(b.get_w(), BOARD_W);
  ASSERT_EQ(b.get_h(), BOARD_H);

  b.print();
}

TEST(board, get_row)
{
  int BOARD_W = 9;
  int BOARD_H = 6;
  board b;
  b.init(BOARD_W, BOARD_H);
  ASSERT_EQ(b.get_row(0).size(), BOARD_W); 
}

TEST(board, get_column)
{
  int BOARD_W = 9;
  int BOARD_H = 6;
  board b;
  b.init(BOARD_W, BOARD_H);
  ASSERT_EQ(b.get_column(0).size(), BOARD_H); 
}

TEST(board, rotate_row_right)
{
  int BOARD_W = 9;
  int BOARD_H = 6;
  mock_board b;
  b.init(BOARD_W, BOARD_H);
  tile_row r = b.get_row(0);
  b.rotate_row_right(0);
  tile_row r_rotated = b.get_row(0);
  ASSERT_EQ(r.size(), r_rotated.size());
  for (int i = 0; i < BOARD_W; i++)
  {
    ASSERT_EQ(r[i], r_rotated[(i + 1) % BOARD_W]);
  } 
}

TEST(board, rotate_row_left)
{
  int BOARD_W = 4;
  int BOARD_H = 3;
  mock_board b;
  b.init(BOARD_W, BOARD_H);
  tile_row r = b.get_row(0);
  b.rotate_row_left(0);
  tile_row r_rotated = b.get_row(0);
  ASSERT_EQ(r.size(), r_rotated.size());
  for (int i = 0; i < BOARD_W; i++)
  {
    ASSERT_EQ(r[(i + 1) % BOARD_W], r_rotated[i]);
  } 
}

TEST(board, rotate_col_up)
{
  int BOARD_W = 3;
  int BOARD_H = 3;
  mock_board b;
  b.init(BOARD_W, BOARD_H);
  std::cout << "\nBefore:\n";
  b.print();

  tile_row r = b.get_column(0);
  b.rotate_col_up(0);
  std::cout << "\nAfter:\n";
  b.print();

  tile_row r_rotated = b.get_column(0);
  for (int i = 0; i < BOARD_H; i++)
  {
    ASSERT_EQ(r[(i + 1) % BOARD_H], r_rotated[i]);
  } 
}

TEST(board, rotate_col_down)
{
  int BOARD_W = 3;
  int BOARD_H = 3;
  mock_board b;
  b.init(BOARD_W, BOARD_H);
  std::cout << "\nBefore:\n";
  b.print();

  tile_row r = b.get_column(0);
  b.rotate_col_down(0);
  std::cout << "\nAfter:\n";
  b.print();

  tile_row r_rotated = b.get_column(0);
  for (int i = 0; i < BOARD_H; i++)
  {
    ASSERT_EQ(r[i], r_rotated[(i + 1) % BOARD_H]);
  } 
}

TEST(board, clear_row)
{
  int BOARD_W = 3;
  int BOARD_H = 3;
  mock_board b;
  b.init(BOARD_W, BOARD_H);
  std::cout << "\nBefore:\n";
  b.print();

  tile_row r_before = b.get_row(0);
  b.clear_row(0);
  tile_row r_after = b.get_row(0);
  for (const auto& t : r_after)
  {
    ASSERT_EQ(t.letter, WF_BLANK_LETTER);
  }
}



