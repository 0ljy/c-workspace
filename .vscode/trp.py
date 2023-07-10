a, x, mod = map(int, input().split())
if a == 1:
  print(x % mod)
else:
  print((pow(a, x, mod * (a - 1)) - 1) // (a - 1))
