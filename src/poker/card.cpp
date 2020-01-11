//
// Created by enrico.m.crisostomo on 09/01/2020.
//

#include "card.h"

emc::poker::card::rank::rank(const std::string& r)
{
  if (r == "2") value = TWO;
  else if (r == "3") value = THREE;
  else if (r == "4") value = FOUR;
  else if (r == "5") value = FIVE;
  else if (r == "6") value = SIX;
  else if (r == "7") value = SEVEN;
  else if (r == "8") value = EIGHT;
  else if (r == "9") value = NINE;
  else if (r == "T") value = TEN;
  else if (r == "J") value = JACK;
  else if (r == "Q") value = QUEEN;
  else if (r == "K") value = KING;
  else if (r == "A") value = ACE;
  else throw std::invalid_argument("Invalid rank code: " + r);
}

emc::poker::card::suit::suit(const std::string& s)
{
  if (s == "C") value = CLUBS;
  else if (s == "D") value = DIAMONDS;
  else if (s == "H") value = HEARTS;
  else if (s == "S") value = SPADES;
  else throw std::invalid_argument("Invalid suit code: " + s);
}

emc::poker::card::card(const std::string& r, const std::string& s) : r(r), s(s)
{
}

bool emc::poker::card::operator<(const emc::poker::card& rhs) const
{
  return this->r < rhs.r;
}

bool emc::poker::card::operator>(const emc::poker::card& rhs) const
{
  return (rhs < *this);
}

bool emc::poker::card::operator<=(const emc::poker::card& rhs) const
{
  return !(rhs > *this);
}

bool emc::poker::card::operator>=(const emc::poker::card& rhs) const
{
  return !(*this < rhs);
}

emc::poker::card::suit emc::poker::card::get_suit() const
{
  return this->s;
}

emc::poker::card::rank emc::poker::card::get_rank() const
{
  return this->r;
}
