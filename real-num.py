import decimal

lamb = decimal.Decimal("3.7")
x = decimal.Decimal("0.25")

for i in range(10):
    x = lamb * x * (1 - x)
    print(x)