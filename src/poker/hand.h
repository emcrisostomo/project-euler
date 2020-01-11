//
// Created by enrico.m.crisostomo on 09/01/2020.
//

#ifndef PROJECT_EULER_HAND_H
#define PROJECT_EULER_HAND_H

#include <vector>
#include <set>
#include <map>
#include "card.h"

namespace emc
{
namespace poker
{

class hand
{
public:
  explicit hand(const std::vector<card>& cards);

  enum rank
  {
    HIGH_CARD,
    ONE_PAIR,
    TWO_PAIRS,
    THREE_OF_A_KIND,
    STRAIGHT,
    FLUSH,
    FULL_HOUSE,
    FOUR_OF_A_KIND,
    STRAIGHT_FLUSH,
    ROYAL_FLUSH
  };

  bool operator< (const hand& rhs) const;
  bool operator> (const hand& rhs) const;
  bool operator<=(const hand& rhs) const;
  bool operator>=(const hand& rhs) const;

  size_t get_ranks_with_frequency(size_t freq) const;
  rank get_rank() const;
  bool is_one_pair() const;
  bool is_two_pairs() const;
  bool is_three_of_a_kind() const;
  bool is_straight() const;
  bool is_flush() const;
  bool is_full_house() const;
  bool is_four_of_a_kind() const;
  bool is_straight_flush() const;
  bool is_royal_flush() const;

private:
  std::vector<card> cards;
  std::set<card::suit> suits;
  std::vector<unsigned short> delta;
  std::map<size_t, std::set<card::rank, std::greater<>>, std::greater<>> rank_by_freq;

  std::set<card::suit> get_suits() const;
  std::vector<unsigned short> get_rank_delta() const;
  std::map<size_t, std::set<card::rank, std::greater<>>, std::greater<>> get_rank_by_freq() const;
};

}
}

#endif //PROJECT_EULER_HAND_H
