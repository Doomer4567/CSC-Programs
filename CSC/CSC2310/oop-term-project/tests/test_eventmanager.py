import unittest
from classes.EventManager import EventManager
from classes.Event import Event
from classes.Contact import Contact


class TestEventManager(unittest.TestCase):
    def setUp(self) -> None:
        self.manager = EventManager()

        self.contact_dict_1 = {
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
        self.contact_dict_2 = {
            "FirstName": "John",
            "LastName": "Doe",
            "UID": 1,
            "EmailAddress": "jdoe@example.com",
            "Dept": "Engineering",
            "Title": "Engineer",
            "Phone": "123-456-7890",
            "Building": "Smith Hall (SMTH) 101",
            "POBox": "1234"
        }

        self.event_dict_1 = {
            "Name": "Lecture on AI",
            "UID": 0,
            "Date": "2023-10-15",
            "StartTime": "14:00",
            "Location": "Bruner 228",
            "Duration": 2
        }
        self.event_dict_2 = {
            "Name": "Music Concert",
            "UID": 2,
            "Date": "2023-12-08",
            "StartTime": "19:30",
            "Location": "University Auditorium",
            "Duration": 2
        }

        self.contact_1 = Contact(self.contact_dict_1)
        self.contact_2 = Contact(self.contact_dict_2)
        self.event_1 = Event(self.event_dict_1)
        self.event_2 = Event(self.event_dict_2)

    def test_add_event(self):
        self.manager.add_event(self.event_dict_1)
        self.assertEqual(len(self.manager.events), 1)
        self.assertEqual(self.manager.events[0].name, "Lecture on AI")

        self.manager.add_event(self.event_dict_2)
        self.assertEqual(len(self.manager.events), 2)
        self.assertEqual(self.manager.events[1].name, "Music Concert")

    def test_add_contact(self):
        self.manager.add_contact(self.contact_dict_1)
        self.assertEqual(len(self.manager.contacts), 1)
        self.assertEqual(self.manager.contacts[0].firstname, "Amani")

        self.manager.add_contact(self.contact_dict_2)
        self.assertEqual(len(self.manager.contacts), 2)
        self.assertEqual(self.manager.contacts[1].firstname, "John")

    def test_add_event_attendee(self):
        self.manager.add_contact(self.contact_dict_1)
        self.manager.add_contact(self.contact_dict_2)
        self.manager.add_event(self.event_dict_1)

        self.manager.add_event_attendee(self.event_1, self.contact_1)
        self.assertTrue(self.manager.is_attending(self.contact_1, self.event_1))

        # Ensure attendee is not added twice
        self.manager.add_event_attendee(self.event_1, self.contact_1)
        self.assertEqual(len(self.manager.event_attendees), 1)

    def test_uid_to_contact(self):
        self.manager.add_contact(self.contact_dict_1)
        self.manager.add_contact(self.contact_dict_2)

        self.assertEqual(self.manager.uid_to_contact(0), self.contact_1)
        self.assertEqual(self.manager.uid_to_contact(1), self.contact_2)
        self.assertIsNone(self.manager.uid_to_contact(100))

    def test_uid_to_event(self):
        self.manager.add_event(self.event_dict_1)
        self.manager.add_event(self.event_dict_2)

        self.assertEqual(self.manager.uid_to_event(0), self.event_1)
        self.assertEqual(self.manager.uid_to_event(2), self.event_2)
        self.assertIsNone(self.manager.uid_to_event(100))

    def test_is_attending(self):
        self.manager.add_contact(self.contact_dict_1)
        self.manager.add_event(self.event_dict_1)

        self.assertFalse(self.manager.is_attending(self.contact_1, self.event_1))
        self.manager.add_event_attendee(self.event_1, self.contact_1)
        self.assertTrue(self.manager.is_attending(self.contact_1, self.event_1))


if __name__ == '__main__':
    unittest.main()
