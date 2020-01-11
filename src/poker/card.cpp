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
  //  9C 6D KD 3H 4C QS QC AC KH
  //JC 6S 5H 2H 2D KD 9D 7C AS JS
  //AD QH TH 9D 8H TS 6D 3S AS AC
  //2H 4S 5C 5S TC KC JD 6C TS 3C
  //QD AS 6H JS 2C 3D 9H KC 4H 8S
  //KD 8S 9S 7C 2S 3S 6D 6S 4H KC
  //3C 8C 2D 7D 4D 9S 4S QH 4H JD
  //8C KC 7S TC 2D TS 8H QD AC 5C
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
