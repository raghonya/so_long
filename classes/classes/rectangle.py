class Rectangle:
    def __init__(self, length, width):
        self.length = length
        self.width = width

    def area(self):
        return self.length * self.width

    def perimeter(self):
        return 2 * (self.length + self.width)

rectangle1 = Rectangle(5, 3)
rectangle2 = Rectangle(7, 4)

area1 = rectangle1.area()
perimeter1 = rectangle1.perimeter()
area2 = rectangle2.area()
perimeter2 = rectangle2.perimeter()

print(f"Rectangle 1: Area = {area1}, Perimeter = {perimeter1}")
print(f"Rectangle 2: Area = {area2}, Perimeter = {perimeter2}")
