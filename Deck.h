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
  typedef std::pair<int, Suite> tCard;
  static const size_t cMaxDeckSize = 52;

  bool add(tCard card);
  void draw();
  void take(size_t n);
  void shuffle();
  size_t size();
  void reveal();
  void revealTop();

private:
  std::vector<tCard> mDeck;
  static const std::map<Suite, std::string> mMapSuiteToString;

  bool isCardDuplicate(tCard card);
  bool isCardValid(tCard card);
};
#endif // !DECK_H
#define DECK_H
