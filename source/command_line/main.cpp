// -----------------------------------------------------------------------------
// Wordfangle
// J Colman 2017
// -----------------------------------------------------------------------------

// Command-line test

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
  b.init(6, 5);
  b.print();

  return 0;
}

