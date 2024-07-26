#ifndef DECK_H
#define DECK_H
#include <cstddef>
#include <map>
#include <string>
#include <utility>
#include <vector>

class Deck {
public:
  Deck();
  Deck(Deck &&) = default;
  Deck(const Deck &) = default;
  Deck &operator=(Deck &&) = default;
  Deck &operator=(const Deck &) = default;
  ~Deck();

  enum Suite {

    clubs = 0,
    diamonds = 1,
    hearts = 2,
    spades = 3

  };
  typedef std::pair<int, Suite> Card;
  static const size_t maxDeckSize = 52;

  bool add(Card card);
  Card draw();
  std::vector<Card> take(size_t n);
  void shuffle();
  size_t size();
  void reveal();
  void revealTop();

private:
  std::vector<Card> m_deck;
  static const std::map<Suite, std::string> m_mapSuiteToString;

  bool isCardDuplicate(Card card);
  bool isCardValid(Card card);
};
#endif // !DECK_H
#define DECK_H
