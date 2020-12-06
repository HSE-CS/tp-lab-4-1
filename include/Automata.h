// Copyright 2020 Team
#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_

enum STATES
{
  OFF,
  WAIT,
  ACCEPT,
  CHECK,
  COOK,
};

class Automata
{
private:
  double cash;
  int count;
  char **menu;
  double *prices;
  STATES state;
  int chos;
public:
    Automata ();
  int on ();
  int off ();
  int coin (double);
  int getMenu (char **) const;
  STATES getState () const;
  int choice (int);
  bool check () const;
  int cansel ();
  int cook ();
  int finish ();
};
#endif  // INCLUDE_AUTOMATA_H_

