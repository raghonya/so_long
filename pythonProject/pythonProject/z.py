# Create a program that accepts two parameters. The first should be the full price of an item as an integer.
#The second should be the discount percentage as an integer.
#The program should count the price of the item after the discount has been applied. For example, if the price is 100 and the discount is 20, the program should return 80.

a=int(input("Enter the price: "))
b=int(input("Sale (%): "))
c= a-(a*b/100)
print(c)
