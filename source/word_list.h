// -----------------------------------------------------------------------------
// Wordfangle
// J Colman 2017
// -----------------------------------------------------------------------------

#pragma once

#include <string>
#include <vector>

// * word_list class *
// Store of all valid words.
class word_list
{
public:
  // File format is one word per line.
  // First line should be an int, the number of words in the file. This is so
  //  we can reserve space up front.
  bool load(const std::string& filename);

  bool is_a_word(const std::string& word) const;

private:
  std::vector<std::string> m_words;
};

