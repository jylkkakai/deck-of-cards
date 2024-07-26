#include "Deck.h"
#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>

const std::map<Deck::Suite, std::string> Deck::m_mapSuiteToString = {
    {Deck::clubs, "Clubs"},
    {Deck::diamonds, "Diamonds"},
    {Deck::hearts, "Hearts"},
    {Deck::spades, "Spades"}};

Deck::Deck() { m_deck.reserve(maxDeckSize); }
Deck::~Deck() {}

bool Deck::add(Card card) {
  if (m_deck.size() < maxDeckSize && !isCardDuplicate(card) &&
      isCardValid(card)) {
    m_deck.push_back(card);
    return true;
  }
  return false;
}

Deck::Card Deck::draw() {
  Card c;
  if (!m_deck.empty()) {
    c = m_deck.back();
    m_deck.pop_back();
  }
  return c;
}

std::vector<Deck::Card> Deck::take(size_t n) {
  int minN = std::min(n, m_deck.size());
  std::vector<Card> cards(minN);
  if (minN > 0) {
    std::copy_backward(m_deck.end() - minN, m_deck.end(), cards.end());
    m_deck.erase(m_deck.end() - minN, m_deck.end());
  }
  return cards;
}

void Deck::shuffle() {
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  auto rng = std::default_random_engine(seed);
  std::shuffle(m_deck.begin(), m_deck.end(), rng);
}

size_t Deck::size() { return m_deck.size(); }

void Deck::reveal() {
  if (!m_deck.empty()) {
    std::cout << "  Cards in the deck are: " << std::endl;
    for (auto it = m_deck.rbegin(); it != m_deck.rend(); it++) {
      std::cout << "  " << it->first << " of "
                << m_mapSuiteToString.at(it->second) << std::endl;
    }
  } else {
    std::cout << "  Deck is empty!" << std::endl;
  }
}

void Deck::revealTop() {
  if (!m_deck.empty()) {
    std::cout << "  The topmost card in the deck is ";
    auto last = m_deck.back();
    // auto last = m_deck.end() - 1;
    std::cout << last.first << " of " << m_mapSuiteToString.at(last.second)
              << std::endl;
  } else {
    std::cout << "  Deck is empty!" << std::endl;
  }
}

bool Deck::isCardDuplicate(Card card) {
  return std::find(m_deck.begin(), m_deck.end(), card) != m_deck.end() ? true
                                                                       : false;
}

bool Deck::isCardValid(Card card) {
  return (card.first < 1 || card.first > 13 || card.second < 0 ||
          card.second > 3)
             ? false
             : true;
}
