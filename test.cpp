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

  deck.add(std::make_pair(11, Deck::spades));
  std::cout << "  " << deck.size() << std::endl;
  deck.reveal();
  deck.revealTop();

  return 0;
}
