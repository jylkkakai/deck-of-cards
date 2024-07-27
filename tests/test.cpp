#include "../Deck.h"
#include <gtest/gtest.h>

void addNToDeck(Deck *deck, int n) {
  size_t i = 0;
  size_t j = 1;
  while (i + j <= n) {
    Deck::Card card = {j, static_cast<Deck::Suite>(i)};
    deck->add(card);

    if (j == 13) {
      i++;
      j = 0;
    } else {
      j++;
    }
  }
}

TEST(testAdd, addValid1) {
  Deck d;
  int size = d.size();
  Deck::Card card = {1, Deck::clubs};
  bool valid = d.add(card);
  EXPECT_EQ(true, valid);
  EXPECT_EQ(size + 1, d.size());
}

TEST(testAdd, addValid2) {
  Deck d;
  int size = d.size();
  Deck::Card card = {13, Deck::diamonds};
  bool valid = d.add(card);
  EXPECT_EQ(true, valid);
  EXPECT_EQ(size + 1, d.size());
}

TEST(testAdd, addValid3) {
  Deck d;
  int size = d.size();
  Deck::Card card = {1, Deck::hearts};
  bool valid = d.add(card);
  EXPECT_EQ(true, valid);
  EXPECT_EQ(size + 1, d.size());
}

TEST(testAdd, addValid4) {
  Deck d;
  int size = d.size();
  Deck::Card card = {13, Deck::spades};
  bool valid = d.add(card);
  EXPECT_EQ(true, valid);
  EXPECT_EQ(size + 1, d.size());
}

TEST(testAdd, addValidToFullDeck) {
  Deck d;
  addNToDeck(&d, 52);
  int size = d.size();
  Deck::Card card = {13, Deck::spades};
  bool valid = d.add(card);
  EXPECT_EQ(false, valid);
  EXPECT_EQ(size, d.size());
}

TEST(testAdd, addDuplicate) {

  Deck d;
  Deck::Card card = {1, Deck::clubs};
  bool valid = d.add(card);
  int size = d.size();
  valid = d.add(card);
  EXPECT_EQ(false, valid);
  EXPECT_EQ(size, d.size());
}

TEST(testAdd, addInvalidSuite1) {

  Deck d;
  int size = d.size();
  Deck::Card card = {1, static_cast<Deck::Suite>(4)};
  bool valid = d.add(card);
  EXPECT_EQ(false, valid);
  EXPECT_EQ(size, d.size());
}

TEST(testAdd, addInvalidSuite2) {

  Deck d;
  int size = d.size();
  Deck::Card card = {1, static_cast<Deck::Suite>(-1)};
  bool valid = d.add(card);
  EXPECT_EQ(false, valid);
  EXPECT_EQ(size, d.size());
}

TEST(testAdd, addInvalidNumber1) {
  Deck d;
  int size = d.size();
  Deck::Card card = {0, Deck::clubs};
  bool valid = d.add(card);
  EXPECT_EQ(false, valid);
  EXPECT_EQ(size, d.size());
}

TEST(testAdd, addInvalidNumber2) {

  Deck d;
  int size = d.size();
  Deck::Card card = {14, Deck::clubs};
  bool valid = d.add(card);
  EXPECT_EQ(false, valid);
  EXPECT_EQ(size, d.size());
}

TEST(testDraw, validDraw1) {
  Deck d;
  int size = d.size();
  Deck::Card card = {1, Deck::clubs};
  bool valid = d.add(card);
  Deck::Card drawCard = d.draw();

  EXPECT_EQ(card, drawCard);
  EXPECT_EQ(size, d.size());
}

TEST(testDraw, validDraw2) {
  Deck d;
  addNToDeck(&d, 52);
  int size = d.size();
  Deck::Card card = {13, Deck::spades};
  Deck::Card drawCard = d.draw();

  EXPECT_EQ(card, drawCard);
  EXPECT_EQ(size - 1, d.size());
}

TEST(testDraw, drawFromEmpty) {
  Deck d;
  int size = d.size();
  Deck::Card drawCard = d.draw();

  EXPECT_EQ(0, drawCard.first);
  EXPECT_EQ(size, d.size());
}

TEST(testTake, take10FromEmpty) {
  Deck d;
  std::vector<Deck::Card> c;
  int size = d.size();
  c = d.take(10);

  EXPECT_EQ(0, c.size());
  EXPECT_EQ(size, d.size());
}

TEST(testTake, take10FromOne) {
  Deck d;
  std::vector<Deck::Card> c;
  Deck::Card card = {13, Deck::spades};
  bool valid = d.add(card);
  int size = d.size();
  c = d.take(10);

  EXPECT_EQ(1, c.size());
  EXPECT_EQ(size - 1, d.size());
}

TEST(testTake, take0FromOne) {
  Deck d;
  std::vector<Deck::Card> c;
  Deck::Card card = {13, Deck::spades};
  bool valid = d.add(card);
  int size = d.size();
  c = d.take(0);

  EXPECT_EQ(0, c.size());
  EXPECT_EQ(size, d.size());
}

TEST(testTake, take52From10) {
  Deck d;
  std::vector<Deck::Card> c;
  addNToDeck(&d, 10);
  int size = d.size();
  c = d.take(52);

  EXPECT_EQ(10, c.size());
  EXPECT_EQ(size - 10, d.size());
}

TEST(testTake, take10From10) {
  Deck d;
  std::vector<Deck::Card> c;
  addNToDeck(&d, 10);
  int size = d.size();
  c = d.take(10);

  EXPECT_EQ(10, c.size());
  EXPECT_EQ(size - 10, d.size());
}

TEST(testTake, take1From10) {
  Deck d;
  std::vector<Deck::Card> c;
  addNToDeck(&d, 10);
  int size = d.size();
  c = d.take(1);

  EXPECT_EQ(1, c.size());
  EXPECT_EQ(size - 1, d.size());
}

TEST(testTake, take1FromFull) {
  Deck d;
  std::vector<Deck::Card> c;
  addNToDeck(&d, 52);
  int size = d.size();
  c = d.take(1);

  EXPECT_EQ(1, c.size());
  EXPECT_EQ(size - 1, d.size());
}

TEST(testTake, take23FromFull) {
  Deck d;
  std::vector<Deck::Card> c;
  addNToDeck(&d, 52);
  int size = d.size();
  c = d.take(23);

  EXPECT_EQ(23, c.size());
  EXPECT_EQ(size - 23, d.size());
}

TEST(testTake, take52FromFull) {
  Deck d;
  std::vector<Deck::Card> c;
  addNToDeck(&d, 52);
  int size = d.size();
  c = d.take(52);

  EXPECT_EQ(52, c.size());
  EXPECT_EQ(size - 52, d.size());
}

TEST(testTake, take1000FromFull) {
  Deck d;
  std::vector<Deck::Card> c;
  addNToDeck(&d, 52);
  int size = d.size();
  c = d.take(1000);

  EXPECT_EQ(52, c.size());
  EXPECT_EQ(0, d.size());
}

TEST(testShuffle, shuffleEmpty) {
  Deck d;
  int size = d.size();
  d.shuffle();
  EXPECT_EQ(size, d.size());
}
//
TEST(testShuffle, shuffleOne) {
  Deck d;
  Deck::Card card = {13, Deck::spades};
  int size = d.size();
  d.shuffle();
  EXPECT_EQ(size, d.size());
}

TEST(testShuffle, shuffleFullDeck) {
  Deck d;
  addNToDeck(&d, 52);
  int size = d.size();
  d.shuffle();
  EXPECT_EQ(size, d.size());
}

TEST(testShuffle, shuffleResultNotEqual) {
  Deck d;
  addNToDeck(&d, 52);
  std::vector<Deck::Card> d1(52);
  d.shuffle();
  d1 = d.take(52);
  addNToDeck(&d, 52);
  std::vector<Deck::Card> d2(52);
  d.shuffle();
  d2 = d.take(52);

  EXPECT_NE(d1, d2);
}

TEST(testShuffle, shuffleResultNotEqualForSeparateDecks) {
  Deck d1;
  Deck d2;
  addNToDeck(&d1, 52);
  std::vector<Deck::Card> sd1(52);
  d1.shuffle();
  sd1 = d1.take(52);
  addNToDeck(&d2, 52);
  std::vector<Deck::Card> sd2(52);
  d2.shuffle();
  sd2 = d2.take(52);

  EXPECT_NE(sd1, sd2);
}
int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
