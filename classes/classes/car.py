class Car:
    def __init__(self, make, model, year):
        self.make = make
        self.model = model
        self.year = year
        self.is_running = False

    def start(self):
        self.is_running = True
        print(f"The {self.make} {self.model} has started.")

    def stop(self):
        self.is_running = False
        print(f"The {self.make} {self.model} has stopped.")

    def honk(self):
        if self.is_running:
            print("Honk! Honk!")
        else:
            print("The car is not running.")

my_car = Car("Toyota", "Camry", 2020)

print(f"Make: {my_car.make}")
print(f"Model: {my_car.model}")
print(f"Year: {my_car.year}")

my_car.start()
my_car.honk()
my_car.stop()
