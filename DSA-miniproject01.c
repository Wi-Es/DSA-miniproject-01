#include <stdio.h>
#define N 5000
char a[N], b[N], c[N];
void add_strings()
{
  int carry = 0;
  for (int i = N - 1; i >= 0; i--)
  {
    int digit = (a[i] - '0') + (b[i] - '0') + carry;
    c[i] = (digit % 10) + '0';
    carry = digit / 10;
  }
}
void fib(int n)
{
  if (n == 0 || n == 1)
  {
    printf("%d", n);
    return;
  }
  for (int i = 2; i <= n; i++)
  {
    add_strings();
    for (int i = 0; i < N; i++)
    {
      a[i] = b[i];
      b[i] = c[i];
    }
  }
  int firstDigit = 0;
  for (int i = 0; i < N; i++)
  {
    if (firstDigit == 0 && c[i] == '0')
    {
      continue;
    }

    if (firstDigit == 0 && c[i] != '0')
    {
      firstDigit = 1;
    }
    printf("%c", c[i]);
  }
  printf("\n");
}

int main()
{
  int n;
  scanf("%d", &n);
  for (int i = 0; i < N; i++)
  {
    a[i] = '0';
    b[i] = '0';
    c[i] = '0';
  }
  b[N - 1] = '1';
  fib(n);
}