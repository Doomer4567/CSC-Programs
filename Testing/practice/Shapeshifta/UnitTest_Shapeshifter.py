import unittest
from shapeshifter import Shapeshifter


class TestShapeshifter(unittest.TestCase):
    def setup(self):
        self.ssh = Shapeshifter('Human')
        self.ssw = Shapeshifter('Wolf')
        self.ssc = Shapeshifter('Crow')

    def test_form(self):
        self.assertEqual(self.ssh.form, 'Human')
        self.assertEqual(self.ssw.form, 'Wolf')
        self.assertEqual(self.ssc.form, 'Crow')

    def test_voice(self):
        self.assertEqual(self.ssh.voice, "Hmm")
        self.assertEqual(self.ssw.voice, "Awo")
        self.assertEqual(self.ssc.voice, "Caw")

    def test_wings(self):
        self.assertEqual(self.ssh.wings, 0)
        self.assertEqual(self.ssw.wings, 0)
        self.assertEqual(self.ssc.wings, 2)

    def test_arms(self):
        self.assertEqual(self.ssh.arms, 2)
        self.assertEqual(self.ssw.arms, 0)
        self.assertEqual(self.ssc.arms, 0)

    def test_legs(self):
        self.assertEqual(self.ssh.legs, 2)
        self.assertEqual(self.ssw.legs, 4)
        self.assertEqual(self.ssc.legs, 2)

    def test_tail(self):
        self.assertEqual(self.ssh.tail, False)
        self.assertEqual(self.ssw.tail, True)
        self.assertEqual(self.ssc.tail, False)

    def test_Human(self):
        self.assertEqual(self.ssh.form, 'Human')
        self.assertEqual(self.ssh.voice, "Hmm")
        self.assertEqual(self.ssh.wings, 0)
        self.assertEqual(self.ssh.arms, 2)
        self.assertEqual(self.ssh.legs, 2)
        self.assertEqual(self.ssh.tail, False)

    def test_Wolf(self):
        self.assertEqual(self.ssw.form, 'Wolf')
        self.assertEqual(self.ssw.voice, "Awo")
        self.assertEqual(self.ssw.wings, 0)
        self.assertEqual(self.ssw.arms, 0)
        self.assertEqual(self.ssw.legs, 4)
        self.assertEqual(self.ssw.tail, True)

    def test_Crow(self):
        self.assertEqual(self.ssc.form, 'Crow')
        self.assertEqual(self.ssc.voice, "Caw")
        self.assertEqual(self.ssc.wings, 2)
        self.assertEqual(self.ssc.arms, 0)
        self.assertEqual(self.ssc.legs, 2)
        self.assertEqual(self.ssc.tail, False)

    def test_created_invalid(self):
        invalid = ['Dragon' , 5 , 5.0, True, False, None, [0, 2, 'Bob'], 'Human']
        for x in invalid:
            with self.assertRaises(Exception):
                self.ssn = x

    def test_set_invalid(self):
        invalid = ['Dragon', 5, 5.0, True, False, None, [0, 2, 'Bob'],['Human', 'Wolf']]
        for x in invalid:
                with self.assertRaises(Exception):
                    self.ssh.form == x

    def test_manual_bypass_speech(self):
        invalid = ['Dragon', 5, 5.0, True, False, None, [0, 2, 'Bob'], ['Human', 'Wolf']]
        for x in invalid:
            with self.assertRaises(Exception):
                self.ssh._Shapeshifter__form = x
                result = self.ssh.voice
                result = self.ssh.arms
                result = self.ssh.legs
                result = self.ssh.wings
                result = self.ssh.tail

