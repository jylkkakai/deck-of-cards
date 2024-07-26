#include "Deck.h"
#include <iostream>

int main(void) {

  Deck deck;
  std::cout << "  " << deck.size() << std::endl;
  deck.reveal();
  deck.revealTop();

  deck.add(std::make_pair(1, Deck::hearts));
  std::cout << "  " << deck.size() << std::endl;
  deck.reveal();
  deck.revealTop();

  deck.add(std::make_pair(11, Deck::clubs));
  std::cout << "  " << deck.size() << std::endl;
  deck.reveal();
  deck.revealTop();

  deck.draw();
  std::cout << "  " << deck.size() << std::endl;
  deck.reveal();
  deck.revealTop();

  for (size_t i = 0; i < 10; i++) {
    deck.add(std::make_pair(i, Deck::spades));
  }
  for (size_t i = 0; i < 15; i++) {
    deck.add(std::make_pair(i, Deck::diamonds));
  }
  deck.reveal();
  deck.revealTop();
  deck.shuffle();
  deck.reveal();
  deck.revealTop();

  deck.take(deck.size());
  deck.reveal();
  deck.revealTop();

  return 0;
}
