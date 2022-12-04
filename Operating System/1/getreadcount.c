#include "types.h"
#include "stat.h"
#include "user.h"

int main() {
  int count = getreadcount();
  printf(1, "Readcount : %d\n", count);
  return 0;
}
