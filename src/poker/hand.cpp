//
// Created by enrico.m.crisostomo on 09/01/2020.
//

#include <string>
#include "hand.h"

namespace emc
{
namespace poker
{

emc::poker::hand::hand(const std::vector<card>& cards)
{
  if (cards.size() != 5) throw std::runtime_error("Invalid hand size: " + std::to_string(cards.size()));

  this->cards = cards;
  std::sort(this->cards.begin(), this->cards.end());

  this->suits = get_suits();
  this->delta = get_rank_delta();
  this->rank_by_freq = get_rank_by_freq();
}

bool emc::poker::hand::operator<(const emc::poker::hand& rhs) const
{
  rank left_rank = this->get_rank();
  rank right_rank = rhs.get_rank();

  if (left_rank < right_rank) return true;
  if (left_rank > right_rank) return false;

  return this->rank_by_freq < rhs.rank_by_freq;
}

bool emc::poker::hand::operator>(const emc::poker::hand& rhs) const
{
  return (rhs < *this);
}

bool emc::poker::hand::operator<=(const emc::poker::hand& rhs) const
{
  return !(rhs > *this);
}

bool emc::poker::hand::operator>=(const emc::poker::hand& rhs) const
{
  return !(*this < rhs);
}

std::set<card::suit> emc::poker::hand::get_suits() const
{
  std::set<card::suit> suits;
  std::for_each(
    this->cards.begin(),
    this->cards.end(),
    [&](const card& c)
    {
      suits.insert(c.get_suit());
    });

  return suits;
}

hand::rank hand::get_rank() const
{
  if (is_royal_flush()) return ROYAL_FLUSH;
  else if (is_straight_flush()) return STRAIGHT_FLUSH;
  else if (is_four_of_a_kind()) return FOUR_OF_A_KIND;
  else if (is_full_house()) return FULL_HOUSE;
  else if (is_flush()) return FLUSH;
  else if (is_straight()) return STRAIGHT;
  else if (is_three_of_a_kind()) return THREE_OF_A_KIND;
  else if (is_two_pairs()) return TWO_PAIRS;
  else if (is_one_pair()) return ONE_PAIR;
  else return HIGH_CARD;
}

size_t hand::get_ranks_with_frequency(size_t freq) const
{
  if (this->rank_by_freq.find(freq) == this->rank_by_freq.end())
    return 0;

  return this->rank_by_freq.at(freq).size();
}

bool hand::is_one_pair() const
{
  return get_ranks_with_frequency(2) == 1;
}

bool hand::is_two_pairs() const
{
  return get_ranks_with_frequency(2) == 2;
}

bool hand::is_three_of_a_kind() const
{
  return get_ranks_with_frequency(3) == 1;
}

bool hand::is_straight() const
{
  return this->delta == std::vector<unsigned short>({0, 1, 1, 1, 1});
}

bool hand::is_flush() const
{
  return this->suits.size() == 1;
}

bool hand::is_full_house() const
{
  return get_ranks_with_frequency(3) == 1
         && get_ranks_with_frequency(2) == 1;
}

bool hand::is_four_of_a_kind() const
{
  return get_ranks_with_frequency(4) == 1;
}

bool emc::poker::hand::is_straight_flush() const
{
  return
    this->suits.size() == 1
    && is_straight();
}

bool emc::poker::hand::is_royal_flush() const
{
  return
    is_straight_flush() &&
    this->cards[0].get_rank() == card::rank::TEN;
}

std::vector<unsigned short> hand::get_rank_delta() const
{
  std::vector<unsigned short> rank_delta;
  rank_delta.reserve(this->cards.size());
  rank_delta.push_back(0);

  for (auto i = 1; i < this->cards.size(); ++i)
  {
    rank_delta.push_back(this->cards[i].get_rank() - this->cards[i - 1].get_rank());
  }

  return rank_delta;
}

std::map<size_t, std::set<card::rank, std::greater<>>, std::greater<>> hand::get_rank_by_freq() const
{
  std::map<card::rank, size_t> rank_count;

  std::for_each(
    this->cards.begin(),
    this->cards.end(),
    [&](const card& c)
    {
      const card::rank& rank = c.get_rank();

      if (rank_count.find(rank) == rank_count.end())
        rank_count[rank] = 0;

      ++rank_count[rank];
    });

  std::map<size_t, std::set<card::rank, std::greater<>>, std::greater<>> rank_by_freq;

  for (const auto& r : rank_count)
  {
    rank_by_freq[r.second].insert(r.first);
  }

  return rank_by_freq;
}

}
}