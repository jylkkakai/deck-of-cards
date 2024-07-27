#include "Deck.h"
#include <iostream>

int main(void) {

  Deck deck;
  deck.reveal();
  deck.revealTop();
  std::cout << std::endl;

  Deck::Card card = {1, Deck::hearts};
  deck.add(card);
  deck.reveal();
  deck.revealTop();
  std::cout << std::endl;

  card = {11, Deck::clubs};
  deck.add(card);
  deck.reveal();
  deck.revealTop();
  std::cout << std::endl;

  deck.draw();
  deck.reveal();
  deck.revealTop();
  std::cout << std::endl;

  for (size_t i = 0; i < 10; i++) {
    card = {i, Deck::spades};
    deck.add(card);
  }
  for (size_t i = 0; i < 15; i++) {
    card = {i, Deck::diamonds};
    deck.add(card);
  }
  deck.reveal();
  deck.revealTop();
  std::cout << std::endl;

  deck.shuffle();
  deck.reveal();
  deck.revealTop();
  std::cout << std::endl;

  deck.take(deck.size());
  deck.reveal();
  deck.revealTop();

  return 0;
}
