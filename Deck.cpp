#include "Deck.h"
#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>

const std::map<Deck::Suite, std::string> Deck::mMapSuiteToString = {
    {Deck::clubs, "Clubs"},
    {Deck::diamonds, "Diamonds"},
    {Deck::hearts, "Hearts"},
    {Deck::spades, "Spades"}};

Deck::Deck() { mDeck.reserve(cMaxDeckSize); }
Deck::~Deck() {}

bool Deck::add(tCard card) {

  if (mDeck.size() < cMaxDeckSize && !isCardDuplicate(card)) {
    mDeck.push_back(card);
    return true;
  }
  return false;
}
void Deck::draw() {
  if (!mDeck.empty()) {
    mDeck.pop_back();
  }
}
void Deck::take(size_t n) {
  if (n >= mDeck.size()) {
    mDeck.clear();
    std::cout << mDeck.capacity() << std::endl;
  } else if (n > 0) {
    mDeck.erase(mDeck.begin() /* + mDeck.size() - n*/, mDeck.end() - n);
  }
}
void Deck::shuffle() {

  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  auto rng = std::default_random_engine(seed);
  std::shuffle(mDeck.begin(), mDeck.end(), rng);
}
size_t Deck::size() {

  // std::cout << "  Capacity: " << mDeck.capacity() << std::endl;
  return mDeck.size();
}
void Deck::reveal() {
  if (!mDeck.empty()) {
    std::cout << "  Cards in the deck are: " << std::endl;
    for (auto it = mDeck.rbegin(); it != mDeck.rend(); it++) {
      std::cout << "  " << it->first << " of "
                << mMapSuiteToString.at(it->second) << std::endl;
    }
  } else {
    std::cout << "  Deck is empty!" << std::endl;
  }
}
void Deck::revealTop() {
  if (!mDeck.empty()) {
    std::cout << "  The topmost card in the deck is ";
    auto last = mDeck.end() - 1;
    std::cout << last->first << " of " << mMapSuiteToString.at(last->second)
              << std::endl;
  } else {
    std::cout << "  Deck is empty!" << std::endl;
  }
}

bool Deck::isCardDuplicate(tCard card) {
  return std::find(mDeck.begin(), mDeck.end(), card) != mDeck.end() ? true
                                                                    : false;
}

bool Deck::isCardValid(tCard card) {
  return (card.first < 1 || card.first > 13 || card.second < 0 ||
          card.second > 3)
             ? false
             : true;
}
