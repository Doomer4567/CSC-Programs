import unittest
from shapeshifter import Shapeshifter

class TestShapeshifter(unittest.TestCase):
    def setup(self):
        self.ssh = shapeshifter('Human')
        self.ssh = shapeshifter('Wolf')
        self.ssh = shapeshifter('Crow')
    
    def test_form(self):
        self.assertEqual(self.ssh.form, 'Human')
        self.assertEqual(self.ssh.form, 'Wolf')
        self.assertEqual(self.ssh.form, 'Crow')


    def test_wings(self):
        self.assertEqual(self.ssh.wings, 0)
        self.assertEqual(self.ssh.wings, 0)
        self.assertEqual(self.ssh.wings, 2)
    
    def test_legs(self):
        self.assertEqual(self.ssh.legs, 2)
        self.assertEqual(self.ssh.legs, 4)
        self.assertEqual(self.ssh.legs, 4)