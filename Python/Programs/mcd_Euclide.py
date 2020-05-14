x = input("Insert x: ")
y = input("\nInsert y: ")

while (y > 0):
    r = x % y
    x = y
    y = r

print '\n', x
