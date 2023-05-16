typedef struct Coins
{
  int quarter;
  int dime;
  int nickel;
  int penny;
} Coins_t;

Coins_t make_change(float amount);