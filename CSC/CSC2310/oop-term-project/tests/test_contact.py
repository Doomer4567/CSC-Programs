import unittest
from classes.Contact import Contact


class TestContact(unittest.TestCase):
    def setUp(self) -> None:
        """
        Set up some commonly used object among test functions.
        :return: None
        """
        self.contact_dict_1: dict = {
            "FirstName": "Amani",
            "LastName": "Altarawneh",
            "UID": 0,
            "EmailAddress": "aaltarawneh@tntech.edu",
            "Dept": "Computer Science",
            "Title": "Assistant Professor",
            "Phone": "--",
            "Building": "Bruner Hall (BRUN) 232",
            "POBox": "5101"
        }
        self.contact_dict_2: dict = {
            "FirstName": "John",
            "LastName": "Doe",
            "UID": 1,
            "EmailAddress": "jdoe@example.com",
            "Dept": "Engineering",
            "Title": "Engineer",
            "Phone": "123-456-7890",
            "Building": "Smith Hall (SMTH) 101",
            "POBox": "12345"
        }
        self.contact_dict_3: dict = {
            "FirstName": "Emily",
            "LastName": "Smith",
            "UID": 2,
            "EmailAddress": "emilysmith@example.com",
            "Dept": "Computer Science",
            "Title": "Associate Professor",
            "Phone": "555-555-5555",
            "Building": "Bruner Hall",
            "POBox": "6789"
        }

    def test_creation(self):
        """
        Test the creation and proper attribute assignment of the Contact class
        :return:
        """
        # From contacts.json
        self.contact_1 = Contact(self.contact_dict_1)
        self.assertEqual(self.contact_1.firstname, "Amani")
        self.assertEqual(self.contact_1.lastname, "Altarawneh")
        self.assertEqual(self.contact_1.uid, 0)
        self.assertEqual(self.contact_1.email, "aaltarawneh@tntech.edu")
        self.assertEqual(self.contact_1.department, "Computer Science")
        self.assertEqual(self.contact_1.title, "Assistant Professor")
        self.assertEqual(self.contact_1.phone, "--")
        self.assertEqual(self.contact_1.building, "Bruner Hall (BRUN) 232")
        self.assertEqual(self.contact_1.mail_code, "5101")
        self.assertEqual(self.contact_1.last_contact, "")

        # Just some random data to test with
        self.contact_2 = Contact(self.contact_dict_2)
        self.assertEqual(self.contact_2.firstname, "John")
        self.assertEqual(self.contact_2.lastname, "Doe")
        self.assertEqual(self.contact_2.uid, 1)
        self.assertEqual(self.contact_2.email, "jdoe@example.com")
        self.assertEqual(self.contact_2.department, "Engineering")
        self.assertEqual(self.contact_2.title, "Engineer")
        self.assertEqual(self.contact_2.phone, "123-456-7890")
        self.assertEqual(self.contact_2.building, "Smith Hall (SMTH) 101")
        self.assertEqual(self.contact_2.mail_code, "12345")
        self.assertEqual(self.contact_2.last_contact, "")

        # More random data
        self.contact_3 = Contact(self.contact_dict_3)
        self.assertEqual(self.contact_3.firstname, "Emily")
        self.assertEqual(self.contact_3.lastname, "Smith")
        self.assertEqual(self.contact_3.uid, 2)
        self.assertEqual(self.contact_3.email, "emilysmith@example.com")
        self.assertEqual(self.contact_3.department, "Computer Science")
        self.assertEqual(self.contact_3.title, "Associate Professor")
        self.assertEqual(self.contact_3.phone, "555-555-5555")
        self.assertEqual(self.contact_3.building, "Bruner Hall")
        self.assertEqual(self.contact_3.mail_code, "6789")
        self.assertEqual(self.contact_3.last_contact, "")

    def test_last_contact(self):
        """
        Test the last contact attribute of the Contact class
        :return: None
        """
        self.contact_1 = Contact(self.contact_dict_1)
        self.assertEqual(self.contact_1.last_contact, "")
        self.contact_1.last_contact = "1970-1-1"  # the Unix epoch 😎
        self.assertEqual(self.contact_1.last_contact, "1970-1-1")

    def test_str(self):
        """
        Test the string method of the Contact class
        :return: None
        """
        self.contact_1 = Contact(self.contact_dict_1)
        self.contact_2 = Contact(self.contact_dict_2)
        self.contact_3 = Contact(self.contact_dict_3)

        self.assertEqual(self.contact_1.__str__(),
                         "Amani Altarawneh\n"
                         "Title: Assistant Professor\n"
                         "Email: aaltarawneh@tntech.edu\n"
                         "Department: Computer Science\n"
                         "Phone: --\n"
                         "Building: Bruner Hall (BRUN) 232")

        self.assertEqual(self.contact_2.__str__(),
                         "John Doe\n"
                         "Title: Engineer\n"
                         "Email: jdoe@example.com\n"
                         "Department: Engineering\n"
                         "Phone: 123-456-7890\n"
                         "Building: Smith Hall (SMTH) 101")

        self.assertEqual(self.contact_3.__str__(),
                         "Emily Smith\n"
                         "Title: Associate Professor\n"
                         "Email: emilysmith@example.com\n"
                         "Department: Computer Science\n"
                         "Phone: 555-555-5555\n"
                         "Building: Bruner Hall")

    def test_getters(self):
        """
        Test that attributes of the contact class are not implemented in a more C++ style of OOP
        :return: None
        """
        self.contact = Contact(self.contact_dict_1)

        self.assertFalse(callable(getattr(self.contact, "lastname")),
                         msg="lastname should only be a property using the property decorator")
        self.assertFalse(callable(getattr(self.contact, "firstname")),
                         msg="firstname should only be a property using the property decorator")
        self.assertFalse(callable(getattr(self.contact, "uid")),
                         msg="uid should only be a property using the property decorator")
        self.assertFalse(callable(getattr(self.contact, "email")),
                         msg="email should only be a property using the property decorator")
        self.assertFalse(callable(getattr(self.contact, "department")),
                         msg="department should only be a property using the property decorator")
        self.assertFalse(callable(getattr(self.contact, "title")),
                         msg="title should only be a property using the property decorator")
        self.assertFalse(callable(getattr(self.contact, "phone")),
                         msg="phone should only be a property using the property decorator")
        self.assertFalse(callable(getattr(self.contact, "building")),
                         msg="building should only be a property using the property decorator")
        self.assertFalse(callable(getattr(self.contact, "mail_code")),
                         msg="mail_code should only be a property using the property decorator")
        # last_contact is covered in test_last_contact()

    def test_not_setters(self):
        """
        Tests that attributes of the Contact class are not setters, an indicator of not using the property decorator
        :return: None
        """
        self.contact = Contact(self.contact_dict_1)

        # PyCharm should rightfully say something like, "Property '<property>' cannot be set"
        with self.assertRaises(AttributeError) as context:
            self.contact.lastname = "Doe"
        self.assertEqual(
            "property 'lastname' of 'Contact' object has no setter", str(context.exception),
            msg="lastname should not allow direct assignment"
        )

        with self.assertRaises(AttributeError) as context:
            self.contact.firstname = "John"
        self.assertEqual(
            "property 'firstname' of 'Contact' object has no setter", str(context.exception),
            msg="firstname should not allow direct assignment"
        )

        with self.assertRaises(AttributeError) as context:
            self.contact.uid = "123"
        self.assertEqual(
            "property 'uid' of 'Contact' object has no setter", str(context.exception),
            msg="uid should not allow direct assignment"
        )

        with self.assertRaises(AttributeError) as context:
            self.contact.email = "john.doe@example.com"
        self.assertEqual(
            "property 'email' of 'Contact' object has no setter", str(context.exception),
            msg="email should not allow direct assignment"
        )

        with self.assertRaises(AttributeError) as context:
            self.contact.department = "Engineering"
        self.assertEqual(
            "property 'department' of 'Contact' object has no setter", str(context.exception),
            msg="department should not allow direct assignment"
        )

        with self.assertRaises(AttributeError) as context:
            self.contact.title = "Software Engineer"
        self.assertEqual(
            "property 'title' of 'Contact' object has no setter", str(context.exception),
            msg="title should not allow direct assignment"
        )

        with self.assertRaises(AttributeError) as context:
            self.contact.phone = "123-456-7890"
        self.assertEqual(
            "property 'phone' of 'Contact' object has no setter", str(context.exception),
            msg="phone should not allow direct assignment"
        )

        with self.assertRaises(AttributeError) as context:
            self.contact.building = "A"
        self.assertEqual(
            "property 'building' of 'Contact' object has no setter", str(context.exception),
            msg="building should not allow direct assignment"
        )

        with self.assertRaises(AttributeError) as context:
            self.contact.mail_code = "12345"
        self.assertEqual(
            "property 'mail_code' of 'Contact' object has no setter", str(context.exception),
            msg="mail_code should not allow direct assignment"
        )
        # last_contact is covered in test_last_contact()

    def test_input_checking(self):
        """
        Tests whether attribute types are checked at runtime. These should follow the format:
        `assert(isinstance(data[<attribute>], <type>))` for most cases.
        """
        # Test that keys are checked in the dictionary by passing an empty dictionary. This should not fail.
        Contact({})

        with self.assertRaises(
                AssertionError,
                msg="The type of \"LastName\" is not tested"):
            bad_contact_last_name: dict = {
                "FirstName": "Amani",
                "LastName": 555,
                "UID": 0,
                "EmailAddress": "aaltarawneh@tntech.edu",
                "Dept": "Computer Science",
                "Title": "Assistant Professor",
                "Phone": "--",
                "Building": "Bruner Hall (BRUN) 232",
                "POBox": "5101"
            }
            Contact(bad_contact_last_name)
        with self.assertRaises(
                AssertionError,
                msg="The type of \"FirstName\" is not tested"):
            bad_contact_first_name: dict = {
                "FirstName": 541,
                "LastName": "Altarawneh",
                "UID": 0,
                "EmailAddress": "aaltarawneh@tntech.edu",
                "Dept": "Computer Science",
                "Title": "Assistant Professor",
                "Phone": "--",
                "Building": "Bruner Hall (BRUN) 232",
                "POBox": "5101"
            }
            Contact(bad_contact_first_name)
        with self.assertRaises(
                AssertionError,
                msg="The type of \"MiddleName\" is not tested"):
            bad_contact_middle_name: dict = {
                "FirstName": "Amani",
                "MiddleName": 3.7,
                "LastName": "Altarawneh",
                "UID": 0,
                "EmailAddress": "aaltarawneh@tntech.edu",
                "Dept": "Computer Science",
                "Title": "Assistant Professor",
                "Phone": "--",
                "Building": "Bruner Hall (BRUN) 232",
                "POBox": "5101"
            }
            Contact(bad_contact_middle_name)
        with self.assertRaises(
                AssertionError,
                msg="The type of \"UID\" is not tested or is converted. If the JSON is correct, this should be parsed "
                    "as an integer"):
            bad_contact_uid: dict = {
                "FirstName": "Amani",
                "LastName": "Altarawneh",
                "UID": "0",
                "EmailAddress": "aaltarawneh@tntech.edu",
                "Dept": "Computer Science",
                "Title": "Assistant Professor",
                "Phone": "--",
                "Building": "Bruner Hall (BRUN) 232",
                "POBox": "5101"
            }
            Contact(bad_contact_uid)
        with self.assertRaises(
                AssertionError,
                msg="The type of \"EmailAddress\" is not tested"):
            bad_contact_email: dict = {
                "FirstName": "Amani",
                "LastName": "Altarawneh",
                "UID": 0,
                "EmailAddress": 1,
                "Dept": "Computer Science",
                "Title": "Assistant Professor",
                "Phone": "--",
                "Building": "Bruner Hall (BRUN) 232",
                "POBox": "5101"
            }
            Contact(bad_contact_email)
        with self.assertRaises(
                AssertionError,
                msg="\"EmailAddress\" is not RFC 5322 validated. You should use the RegEx `r\"(^[a-zA-Z0-9_.+-]+@["
                    "a-zA-Z0-9-]+\\.[a-zA-Z0-9-.]+$)\"`"):
            bad_contact_email2: dict = {
                "FirstName": "Amani",
                "LastName": "Altarawneh",
                "UID": 0,
                "EmailAddress": "invalid_email",
                "Dept": "Computer Science",
                "Title": "Assistant Professor",
                "Phone": "--",
                "Building": "Bruner Hall (BRUN) 232",
                "POBox": "5101"
            }
            Contact(bad_contact_email2)
        with self.assertRaises(
                AssertionError,
                msg="The type of \"Dept\" is not tested"):
            bad_contact_dept: dict = {
                "FirstName": "Amani",
                "LastName": "Altarawneh",
                "UID": 0,
                "EmailAddress": "aaltarawneh@tntech.edu",
                "Dept": 42,
                "Title": "Assistant Professor",
                "Phone": "--",
                "Building": "Bruner Hall (BRUN) 232",
                "POBox": "5101"
            }
            Contact(bad_contact_dept)
        with self.assertRaises(
                AssertionError,
                msg="The type of \"Title\" is not tested"):
            bad_contact_title: dict = {
                "FirstName": "Amani",
                "LastName": "Altarawneh",
                "UID": 0,
                "EmailAddress": "aaltarawneh@tntech.edu",
                "Dept": "Computer Science",
                "Title": 818,
                "Phone": "--",
                "Building": "Bruner Hall (BRUN) 232",
                "POBox": "5101"
            }
            Contact(bad_contact_title)
        with self.assertRaises(
                AssertionError,
                msg="The type of \"Phone\" is not tested"):
            bad_contact_phone: dict = {
                "FirstName": "Amani",
                "LastName": "Altarawneh",
                "UID": 0,
                "EmailAddress": "aaltarawneh@tntech.edu",
                "Dept": "Computer Science",
                "Title": "Assistant Professor",
                "Phone": 123_456_7890,  # Yes, you can write numbers like this
                "Building": "Bruner Hall (BRUN) 232",
                "POBox": "5101"
            }
            Contact(bad_contact_phone)
        with self.assertRaises(
                AssertionError,
                msg="\"Phone\" is not validated. You should use a regular expression with the assumption that the "
                    "phone number is 10 digits long (so not international)."):
            bad_contact_phone_letters: dict = {
                "FirstName": "Amani",
                "LastName": "Altarawneh",
                "UID": 0,
                "EmailAddress": "aaltarawneh@tntech.edu",
                "Dept": "Computer Science",
                "Title": "Assistant Professor",
                "Phone": "abc-def-ghij",
                "Building": "Bruner Hall (BRUN) 232",
                "POBox": "5101"
            }
            Contact(bad_contact_phone_letters)
        with self.assertRaises(
                AssertionError,
                msg="\"Phone\" is not validated correctly. It should always include 2 hyphens and may include "
                    "parenthesis"):
            bad_contact_phone_format: dict = {
                "FirstName": "Amani",
                "LastName": "Altarawneh",
                "UID": 0,
                "EmailAddress": "aaltarawneh@tntech.edu",
                "Dept": "Computer Science",
                "Title": "Assistant Professor",
                "Phone": "1234567890",
                "Building": "Bruner Hall (BRUN) 232",
                "POBox": "5101"
            }
            Contact(bad_contact_phone_format)
        with self.assertRaises(
                AssertionError,
                msg="The type of \"Building\" is not tested"):
            bad_contact_building: dict = {
                "FirstName": "Amani",
                "LastName": "Altarawneh",
                "UID": 0,
                "EmailAddress": "aaltarawneh@tntech.edu",
                "Dept": "Computer Science",
                "Title": "Assistant Professor",
                "Phone": "--",
                "Building": 232,
                "POBox": "5101"
            }
            Contact(bad_contact_building)
        with self.assertRaises(
                AssertionError,
                msg="The type of \"POBox\" is not tested"):
            bad_contact_po_box: dict = {
                "FirstName": "Amani",
                "LastName": "Altarawneh",
                "UID": 0,
                "EmailAddress": "aaltarawneh@tntech.edu",
                "Dept": "Computer Science",
                "Title": "Assistant Professor",
                "Phone": "--",
                "Building": "Bruner Hall (BRUN) 232",
                "POBox": 5101
            }
            Contact(bad_contact_po_box)
        with self.assertRaises(
                AssertionError,
                msg="\"POBox\" is not validated. It should be a string of 4 or 5 digits. The most straight forward "
                    "way to implement this would be RegEx for that specification."):
            bad_contact_po_box_content: dict = {
                "FirstName": "Amani",
                "LastName": "Altarawneh",
                "UID": 0,
                "EmailAddress": "aaltarawneh@tntech.edu",
                "Dept": "Computer Science",
                "Title": "Assistant Professor",
                "Phone": "--",
                "Building": "Bruner Hall (BRUN) 232",
                "POBox": "five one zero one"
            }
            Contact(bad_contact_po_box_content)
        with self.assertRaises(
                AssertionError,
                msg="\"POBox\" length is not validated or is not validated correctly. If you are using RegEx, "
                    "the quantifier \"{<number>,<number>}\" is greedy, and will give back as needed if that gives a "
                    "match. You need to match the entire string and will therefore need to use \"^\" to match the "
                    "start of the line and \"$\" to match the end of the line."):
            bad_contact_po_box_length: dict = {
                "FirstName": "Amani",
                "LastName": "Altarawneh",
                "UID": 0,
                "EmailAddress": "aaltarawneh@tntech.edu",
                "Dept": "Computer Science",
                "Title": "Assistant Professor",
                "Phone": "--",
                "Building": "Bruner Hall (BRUN) 232",
                "POBox": "123456"
            }
            Contact(bad_contact_po_box_length)


if __name__ == '__main__':
    unittest.main()
