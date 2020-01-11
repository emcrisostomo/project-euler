#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cassert>
#include "poker/card.h"
#include "poker/hand.h"

using namespace emc::poker;

// In the card game poker, a hand consists of five cards and are ranked, from
// lowest to highest, in the following way:
//
//   High Card: Highest value card.
//   One Pair: Two cards of the same value.
//   Two Pairs: Two different pairs.
//   Three of a Kind: Three cards of the same value.
//   Straight: All cards are consecutive values.
//   Flush: All cards of the same suit.
//   Full House: Three of a kind and a pair.
//   Four of a Kind: Four cards of the same value.
//   Straight Flush: All cards are consecutive values of same suit.
//   Royal Flush: Ten, Jack, Queen, King, Ace, in same suit.
//
// The cards are valued in the order:
//
//   2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King, Ace.
//
// If two players have the same ranked hands then the rank made up of the
// highest value wins; for example, a pair of eights beats a pair of fives
// (see example 1 below).  But if two ranks tie, for example, both players have
// a pair of queens, then highest cards in each hand are compared (see example
// 4 below); if the highest cards tie then the next highest cards are compared,
// and so on.
//
// The file, poker.txt, contains one-thousand random hands dealt to two players.
// Each line of the file contains ten cards (separated by a single space): the
// first five are Player 1's cards and the last five are Player 2's cards.  You
// can assume that all hands are valid (no invalid characters or repeated
// cards), each player's hand is in no specific order, and in each hand there is
// a clear winner.
//
// How many hands does Player 1 win?
//
int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    std::cerr << "Invalid number of arguments: " << argc << "\n";
    return 1;
  }

  std::fstream infile(argv[1]);
  std::string line;
  size_t first_player_wins{0};

  while (std::getline(infile, line))
  {
    std::istringstream iss(line);
    std::vector<std::string> results(std::istream_iterator<std::string>{iss},
                                     std::istream_iterator<std::string>());

    assert(results.size() == 10);

    std::vector<card> cards;
    cards.reserve(results.size());

    for (const auto& r : results)
    {
      cards.emplace_back(emc::poker::card(r.substr(0, 1), r.substr(1, 1)));
    }

    hand first_player_hand(std::vector<card>(cards.begin(), cards.begin() + 5));
    hand second_player_hand(std::vector<card>(cards.begin() + 5, cards.begin() + 10));

    if (first_player_hand > second_player_hand)
      ++first_player_wins;
  }

  std::cout << first_player_wins << '\n';
  return 0;
}
