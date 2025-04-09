a, b = {x for x in "awiguuuuuvnr"}, {x for x in "23986"}
# print(a, b)

names = ["boa", "asg", "awgrf", "RWG", "wagfre"]
names = [x.upper() for x in names]
# print(names)

it = iter(names)
print(type(it))
