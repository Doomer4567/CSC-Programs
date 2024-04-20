import unittest
from potion import Potion


class TestPotion(unittest.TestCase):

    def test_potion_elixir(self):
        self.potion_elixir_1 = Potion("Vampire's Breath", "Witch's Tongue")
        self.potion_elixir_2 = Potion("Witch's Tongue", "Vampire's Breath")
        self.potion_elixir_3 = Potion("Witch's Tongue", "Witch's Tongue")
        self.potion_elixir_4 = Potion("Vampire's Breath", "Vampire's Breath")
        self.assertEqual(self.potion_elixir_1.get_name(), "Elixir of Halitosis")
        self.assertEqual(self.potion_elixir_2.get_name(), "Elixir of Halitosis")
        self.assertEqual(self.potion_elixir_3.get_name(), "Failed Decoction")
        self.assertEqual(self.potion_elixir_4.get_name(), "Failed Decoction")

    def test_potion_philter(self):
        self.potion_philter_1 = Potion("Toe of Frog", "Eye of Newt")
        self.potion_philter_2 = Potion("Eye of Newt", "Toe of Frog")
        self.potion_philter_3 = Potion("Eye of Newt", "Eye of Newt")
        self.potion_philter_4 = Potion("Toe of Frog", "Toe of Frog")
        self.assertEqual(self.potion_philter_1.get_name(), "Philter of Amphibiosity")
        self.assertEqual(self.potion_philter_2.get_name(), "Philter of Amphibiosity")
        self.assertEqual(self.potion_philter_3.get_name(), "Failed Decoction")
        self.assertEqual(self.potion_philter_4.get_name(), "Failed Decoction")

    def test_potion_draught(self):
        self.potion_draught_1 = Potion("Adder's Fork", "Elephant's Proboscis")
        self.potion_draught_2 = Potion("Elephant's Proboscis", "Adder's Fork")
        self.potion_draught_3 = Potion("Elephant's Proboscis", "Elephant's Proboscis")
        self.potion_draught_4 = Potion("Adder's Fork", "Adder's Fork")
        self.assertEqual(self.potion_draught_1.get_name(), "Draught of Eavesdropping")
        self.assertEqual(self.potion_draught_2.get_name(), "Draught of Eavesdropping")
        self.assertEqual(self.potion_draught_3.get_name(), "Failed Decoction")
        self.assertEqual(self.potion_draught_4.get_name(), "Failed Decoction")

    def test_potion_potion(self):
        self.potion_potion_1 = Potion("Milk", "Marinara Sauce")
        self.potion_potion_2 = Potion("Marinara Sauce", "Milk")
        self.potion_potion_3 = Potion("Marinara Sauce", "Marinara Sauce")
        self.potion_potion_4 = Potion("Milk", "Milk")
        self.assertEqual(self.potion_potion_1.get_name(), "Potion of Regret")
        self.assertEqual(self.potion_potion_2.get_name(), "Potion of Regret")
        self.assertEqual(self.potion_potion_3.get_name(), "Failed Decoction")
        self.assertEqual(self.potion_potion_4.get_name(), "Failed Decoction")

    def test_elixir_value(self):
        self.potion_elixir = Potion("Vampire's Breath", "Witch's Tongue")
        self.assertTrue(10 <= self.potion_elixir.get_value() <= 50)

    def test_philter_value(self):
        self.potion_philter = Potion("Toe of Frog", "Eye of Newt")
        self.assertTrue(750 <= self.potion_philter.get_value() <= 1000)

    def test_draught_value(self):
        self.potion_draught = Potion("Adder's Fork", "Elephant's Proboscis")
        self.assertTrue(500 <= self.potion_draught.get_value() <= 750)

    def test_potion_value(self):
        self.potion_potion = Potion("Milk", "Marinara Sauce")
        self.assertTrue(2 <= self.potion_potion.get_value() <= 40)

    def test_failure_value(self):
        self.potion_failure = Potion("Hope", "Fear")
        self.assertEqual(self.potion_failure.get_value(), 1)


if __name__ == '__main__':
    unittest.main()
