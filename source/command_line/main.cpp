// -----------------------------------------------------------------------------
// Wordfangle
// J Colman 2017
// -----------------------------------------------------------------------------

// Command-line test

#include <iostream>
#include <set>
#include "board.h"
#include "word_list.h"

int main()
{
  word_list wlist;
  if (!wlist.load("../../assets/word_list.txt"))
  {
    return 1;
  }

  board b;
  int w = 3;
  int h = 3;
  b.init(w, h);

  while (true)
  {
    b.print();

    std::string middle_row_word = concat_letters(b.get_row(h / 2));
    std::cout << "Middle row: " << middle_row_word << "\n";
    if (wlist.is_a_word(middle_row_word))
    {
      std::cout << "WOW! You made a word! " << middle_row_word << "\n";
      b.clear_row(h / 2);
      b.print();
    }

    std::cout 
      << "Enter a move! u/d/l/r then row (1.." 
      << h 
      << ")/column (1.." 
      << w 
      << ").\n";

    std::string move;
    std::cin >> move;

    if (std::set<std::string>{"u", "d", "l", "r"}.count(move) == 0)
    {
      std::cout << "What is this move? " << move << "\n";   
      continue;
    }
    int rc = 0; // row or col
    std::cin >> rc;
    if (move == "u")
    {
      b.rotate_col_up(rc);
    }
    else if (move == "d")
    {
      b.rotate_col_down(rc);
    }
    else if (move == "l")
    {
      b.rotate_row_left(rc);
    }
    else
    {
      b.rotate_row_right(rc);
    }
  }

  return 0;
}

