#include <iostream>

class Anthill {
  Anthill();
  ~Anthill();
public:
  int room;
  int tunnels;
  int start;
  int end;
public:
  int add_room();
  int add_tunnel();
  int create_ants();
  
};
