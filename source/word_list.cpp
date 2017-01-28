// -----------------------------------------------------------------------------
// Wordfangle
// J Colman 2017
// -----------------------------------------------------------------------------

#include <algorithm>
#include <fstream>
#include "log.h"
#include "word_list.h"

bool word_list::load(const std::string& filename)
{
  std::ifstream f;
  f.open(filename);
  if (!f.is_open())
  {
    log(msg() << "Failed to open file " << filename);
    return false;
  }
  int num_words = 0;
  f >> num_words;
  if (num_words < 1 || num_words > 1000000)
  {
    log(msg() << "Bad number of words " << num_words << " in file " << filename);
    return false;
  }
  m_words.reserve(num_words * 1.1);
  while (!f.eof())
  {
    std::string s;
    f >> s;
    if (!s.empty())
    {
      m_words.push_back(s);
    }
  }
  log(msg() << "Loaded " << m_words.size() << " words from file " << filename);
  return true;
}

bool word_list::is_a_word(const std::string& word) const
{
  bool b = std::binary_search(m_words.begin(), m_words.end(), word);
#ifdef WORD_LIST_LOG
  log(msg() << "Word '" << word << "' " << (b ? "" : "NOT") << " found");
#endif
  return b;
}

std::vector<std::string> word_list::find_all_words_in(const std::string& cs) const
{
  std::vector<std::string> res;
  for (int i = 2; i < cs.size(); i++)
  {
    std::string s(cs.substr(0, i + 1));
    std::sort(s.begin(), s.end());
    do
    {
      bool b = is_a_word(s);
      log(msg() << "Word '" << s << "' " << (b ? "" : "NOT") << " found");
      if (b)
      {
        res.push_back(s);
      }
    }
    while (std::next_permutation(s.begin(), s.end()));
  }
  return res;
}

