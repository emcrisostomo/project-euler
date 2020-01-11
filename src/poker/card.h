//
// Created by enrico.m.crisostomo on 09/01/2020.
//

#ifndef PROJECT_EULER_CARD_H
#define PROJECT_EULER_CARD_H

#include <string>

namespace emc
{
namespace poker
{

class card
{
public:
  class rank
  {
  public:
    enum rank_value
    {
      TWO,
      THREE,
      FOUR,
      FIVE,
      SIX,
      SEVEN,
      EIGHT,
      NINE,
      TEN,
      JACK,
      QUEEN,
      KING,
      ACE
    };

    explicit rank(rank_value r);
    explicit rank(const std::string& r);

    operator rank_value() const { return value; }

  private:
    rank_value value;
  };

  class suit
  {
  public:
    enum suit_value
    {
      CLUBS,
      DIAMONDS,
      HEARTS,
      SPADES
    };

    explicit suit(suit_value s);
    explicit suit(const std::string& s);

    operator suit_value() const { return value; }

  private:
    suit_value value;
  };

  card(rank r, suit s);
  card(const std::string& r, const std::string& s);

  rank get_rank() const;
  suit get_suit() const;

  bool operator< (const card& rhs) const;
  bool operator> (const card& rhs) const;
  bool operator<=(const card& rhs) const;
  bool operator>=(const card& rhs) const;

private:
  rank r;
  suit s;
};

}
}

#endif //PROJECT_EULER_CARD_H
