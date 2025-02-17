// Finish the solution so that it returns the sum of all the multiples of 3 or 5 below the number passed in.
// Additionally, if the number is negative, return 0.
// Note: If the number is a multiple of both 3 and 5, only count it once.

int solution(int number) {
  int sum = 0;
  for(int i = 3; i < number; i++) if(i % 3 == 0 || i % 5 == 0) sum+=i;
  return sum;
}
