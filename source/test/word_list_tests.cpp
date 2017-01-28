// -----------------------------------------------------------------------------
// Wordfangle
// J Colman 2017
// -----------------------------------------------------------------------------

#include <gtest/gtest.h>
#include "word_list.h"

TEST(word_list, load_and_check_words)
{
  word_list wlist;

  // Contains "apple", "banana"
  bool ok = wlist.load("test_list.txt");
  ASSERT_TRUE(ok);

  ok = wlist.is_a_word("apple");
  ASSERT_TRUE(ok);

  ok = wlist.is_a_word("zebra");
  ASSERT_FALSE(ok);
}

TEST(word_list, find_all_words)
{
  word_list wlist;
  bool ok = wlist.load("word_list.txt");
  ASSERT_TRUE(ok);

  auto words = wlist.find_all_words_in("abcde");
  for (auto& w : words)
  {
    std::cout << w << " ";
  }
  std::cout << std::endl;
//  ASSERT_EQ(words.size(), 2); 
}


