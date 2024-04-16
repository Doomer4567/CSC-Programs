# CSC 2310-103
# Ethan Byker
# Lab 5
# 4/16/2024
# A Sandwich class to hold the data for a user's choice of bread, meat, choice of topping, and their order number

class Sandwich:
    def __init__(self, ordernumber, breadtype, meattype):
        self._order_number = ordernumber
        self._bread_type = breadtype
        self._meat_type = meattype
        self._toppings = []

    @property
    # getters and setters for Order Num
    def order_number(self):
        return self._order_number

    @property
    # getter for bread type
    def bread_type(self):
        return self._bread_type

    @property
    # getter for meat type
    def meat_type(self):
        return self._meat_type

    # for the user to have a choice to add toppings to the sandwich
    def add_topping(self, topping):
        self._toppings.append(topping)

    # for the user to have a choice to remove toppings from the sandwich
    def remove_topping(self, topping):
        if topping in self._toppings:
            self._toppings.remove(topping)

    @property
    # The main price of the sandwich being 3.75 + 0.50 for each topping the user puts 
    def price(self):
        return 3.75 + 0.50 * len(self._toppings)

    def info(self):
        # Print info of sandwich and what is inside the () for sandwich plus toppings and price
        print(f"Order Number: {self._order_number}")
        print(f"Bread: {self._bread_type}")
        print(f"Meat: {self._meat_type}")
        print(f"Toppings: {self._toppings if self._toppings else 'None'}")
        print(f"Price: ${self.price:.2f}")


# A class of a whole meal which is with a drink and side
class Meal(Sandwich):
    def __init__(self, order_number, bread_type, meat_type, drink, side):
        super().__init__(order_number, bread_type, meat_type)
        # initializing the drink and side
        self._drink = drink
        self._side = side

    @property
    # Getter for drink
    def drink(self):
        return self._drink

    @drink.setter
    # setter of drink by putting in a value
    def drink(self, value):
        self._drink = value

    @property
    # Getter for side
    def side(self):
        return self._side

    @side.setter
    # Setter for side by putting in a value
    def side(self, value):
        self._side = value

    @property
    # setting base price of meal at 6.75 and adding 0.50 for each topping
    def price(self):
        return 6.75 + 0.50 * len(self._toppings)

    def info(self):
        # Printing out drink, Side, and Price 
        super().info()
        print(f"Drink: {self._drink}")
        print(f"Side: {self._side}")
        print(f"Price: ${self.price:.2f}")


# Making a class for kids meal and adding a toy
class KidsMeal(Meal):
    def __init__(self, order_number, bread_type, meat_type, drink, side, toy):
        super().__init__(order_number, bread_type, meat_type, drink, side)
        # Initializing toy
        self._toy = toy

    @property
    # getter for toy
    def toy(self):
        return self._toy

    @toy.setter
    # setter for toy by putting in the value
    def toy(self, value):
        self._toy = value

    @property
    # setting base price as 4.75 and adding 0.30 for each topping
    def price(self):
        return 4.75 + 0.30 * len(self._toppings)

    def info(self):
        # printing toy and price 
        super().info()
        print(f"Toy: {self._toy}")
        print(f"Price: ${self.price:.2f}")


# calling the object of sandwich meal and KidsMeal and there toppings
sandwich_object = Sandwich(315, "Wheat", "Ham")
meal_object = Meal(209, "Rye", "Turkey", "Dr. Pepper", "French Fries")
meal_object.add_topping("Lettuce")
meal_object.add_topping("Tomato")
KidsMeal_object = KidsMeal(228, "White Bread", "Bacon", "Potion of Regret", "Apple Slices", "Buzz Lightyear")
KidsMeal_object.add_topping("Pickles")
# finally printing the info of all the objects 
print("Sandwich:")
sandwich_object.info()

print("\nMeal:")
meal_object.info()

print("\nKidsMeal:")
KidsMeal_object.info()
