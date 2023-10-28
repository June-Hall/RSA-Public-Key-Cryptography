static int primesList[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

int isPrimeFast(const int prime) {
  int i;
  for (i = 0; i < 10; i++) {
    if (prime % primesList[i] == 0) {
      return 0;
    }
  }
  return 1;
}