#include <iostream>

class Anthill {
  Anthill();
  ~Anthill();
public:
  short room;
  short tunnels;
  int start;
  int end;
  unsigned short ants;
public:
  void add_room();
  void add_tunnel();
  void create_ants();
  
};
