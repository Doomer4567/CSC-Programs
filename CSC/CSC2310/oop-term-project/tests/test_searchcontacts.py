import json
import unittest
from classes.SearchContacts import SearchContacts
from classes.Contact import Contact


class TestSearchContacts(unittest.TestCase):
    def setUp(self):
        with open("../contacts.json", "r") as json_file:
            contact_dict = json.load(json_file)
        self.contact_list = [Contact(contact) for contact in contact_dict]
        self.contact_search = SearchContacts()

    def test_search(self):
        query1 = self.contact_search.search("Gupta", self.contact_list)
        self.assertEqual(len(query1), 27,
                         msg="A list of all contacts has not been returned. This test is here as a sanity check, "
                             "so I recommend making sure that you are not throwing away data somewhere in your code.")
        self.assertEqual(query1[0].lastname, "Gupta",
                         msg="The first result is the one with the lowest edit distance of all attributes. In this "
                             "case, it should be Gupta with an edit distance of 0 as it is an exact match. It is "
                             "possible that you have ordered the list in reverse and simply need to reverse the list.")

        query2 = self.contact_search.search("Ganood", self.contact_list)
        self.assertEqual(query2[0].lastname, "Gannod",
                         msg="This is a test of the fuzzy string matching, so make sure that you are using that and "
                             "not Python's built-ins.")

        query3 = self.contact_search.search("bburchfield@tntech.edu", self.contact_list)
        self.assertEqual(query3[0].lastname, "Burchfield",
                         msg="This is a test of the email field. Make sure that you are checking the edit distance on "
                             "that.")
        query4 = self.contact_search.search("Computer Science", self.contact_list)
        self.assertEqual(query4, self.contact_list,
                         msg="The result of this query should be the same as the original Contact list as all entries "
                             "have the same department (\"Dept\") field.")

        query5 = self.contact_search.search("", self.contact_list)
        self.assertEqual(query5, self.contact_list, msg="A zero length query should return the original list.")

        query6 = self.contact_search.search("Coordinator", self.contact_list)
        self.assertEqual(query6[0].lastname, "Davis",
                         msg="Not sure how you got here. Perhaps you have modified your JSON file?")

        query7 = self.contact_search.search("931-372-3691", self.contact_list)
        self.assertEqual(query7[0].lastname, "Disbrow",
                         msg="This should be an exact match. Try using PyCharm's debugger to find out what is "
                             "happening.")

        query7 = self.contact_search.search("Bruner 329", self.contact_list)
        self.assertEqual(query7[0].lastname, "Brummett",
                         msg="This one is a bit tricky. Bruner is in a lot of strings, but only one contains 329. "
                             "Also, there are similar phone numbers. Try opening the \"contacts.json\" file to search "
                             "for what might be causing your issue. My guess would be that you are passing "
                             "parameters to `distance()` either that you should not or in a way that you should not.")


if __name__ == '__main__':
    unittest.main()
