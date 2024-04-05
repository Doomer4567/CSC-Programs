#Author: Ethan Byker
#Date: 4/5/2024

import random


class Potion:
    def __init__(self, ingredient1, ingredient2):
        self.ingredient1 = ingredient1
        self.ingredient2 = ingredient2

    def get_name(self):
        #Elixir of Halitosis
        if self.ingredient1 == "Vampire's Breath" and self.ingredient2 == "Witch's Tongue":
            return "Elixir of Halitosis"
        elif self.ingredient1 == "Witch's Tongue" and self.ingredient2 == "Vampire's Breath":
            return "Elixir of Halitosis"
        #if "Vampire's Breath" in self.ingredients and "Witch's Tongue" in self.ingredients:
        #    return "Elixir of Halitosis"
        #Philter of Amphibiosity
        elif self.ingredient1 == "Toe of Frog" and self.ingredient2 == "Eye of Newt":
            return "Philter of Amphibiosity"
        elif self.ingredient1 == "Eye of Newt" and self.ingredient2 == "Toe of Frog":
            return "Philter of Amphibiosity"
        #Draught of Eavesdropping
        elif self.ingredient1 == "Adder's Fork" and self.ingredient2 == "Elephant's Proboscis":
            return "Draught of Eavesdropping"
        elif self.ingredient1 == "Elephant's Proboscis" and self.ingredient2 == "Adder's Fork":
            return "Draught of Eavesdropping"
        #Potion of Regret
        elif self.ingredient1 == "Milk" and self.ingredient2 == "Marinara Sauce":
            return "Potion of Regret"
        elif self.ingredient1 == "Marinara Sauce" and self.ingredient2 == "Milk":
            return "Potion of Regret"
        else:
            return "Failed Decoction"

    def get_value(self):
        if self.get_name() == "Elixir of Halitosis":
            potionValue = random.randint(10,50)
        elif self.get_name() == "Philter of Amphibiosity":
            potionValue = random.randint(750,1000)
        elif self.get_name() == "Draught of Eavesdropping":
            potionValue = random.randint(500,750)
        elif self.get_name() == "Potion of Regret":
            potionValue = random.randint(2,40)
        else:
            potionValue = 1

        return potionValue

