
class Sandwich:
    def __init__(self, OrderNumber: int, BreadType: str, MeatType: str):
        self.OrderNumber = OrderNumber
        self.BreadType = BreadType
        self.MeatType = MeatType
        
    @property 
    def Topping(self) -> str:
        return self.Topping
    
    @Topping.setter
    def Topping(self, Toppings):
        global numToppings
        self.Toppings = Toppings
        numToppings+=1
    
    @property
    def Price(self) -> float:
        return self.Price
    
    @Price.setter
    def Price(self, Price):
        Price = 3.75 + (0.50 * numToppings)

    def get_OrderNumber(self):
        return OrderNumber

    def get_BreadType(self):
        return BreadType

    def get_MeatType(self):
        return MeatType

    def info(self):
        print(OrderNumber)
        print(BreadType)
        print(MeatType)
        print(Price)

class Meal:
    def __init__(self, Drink, Side):
        self.Drink = Drink
        self.Side = Side
    
    def get_Drink(self):
        return Drink
 
    def get_Side(self):
        return Side

    def get_Price(self):
        Price = 6.75 + (0.50 * Toppings)
        return Price

    def info(self):
        print(Drink)
        print(Side)


class KidsMeal:
    def __init__(self, toy):
        self.toy = toy

    def get_toy(self):
        return toy

    def get_Price(self):
        Price = 4.75 + (0.50 * x)
        return Price

    def info(self):
        Sandwich.info()
        print(toy)

    