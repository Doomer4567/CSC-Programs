import unittest
from classes.Event import Event


class TestEvent(unittest.TestCase):
    def setUp(self) -> None:
        """
        Set up some commonly used object among test functions.
        :return: None
        """
        self.event_1: dict = {
            "Name": "Lecture on AI",
            "UID": 0,
            "Date": "2023-10-15",
            "StartTime": "14:00",
            "Location": "Bruner 228",
            "Duration": 2
        }
        self.event_2: dict = {
            "Name": "Music Concert",
            "UID": 2,
            "Date": "2023-12-08",
            "StartTime": "19:30",
            "Location": "University Auditorium",
            "Duration": 2
        }

    def test_creation(self):
        """
        Test the creation and proper assignment of attributes to the Event class
        :return: None
        """
        event_1 = Event(self.event_1)
        self.assertEqual(event_1.name, "Lecture on AI")
        self.assertEqual(event_1.uid, 0)
        self.assertEqual(event_1.date, "2023-10-15")
        self.assertEqual(event_1.start_time, "14:00")
        self.assertEqual(event_1.location, "Bruner 228")
        self.assertEqual(event_1.duration, 2)

        event_2 = Event(self.event_2)
        self.assertEqual(event_2.name, "Music Concert")
        self.assertEqual(event_2.uid, 2)
        self.assertEqual(event_2.date, "2023-12-08")
        self.assertEqual(event_2.start_time, "19:30")
        self.assertEqual(event_2.location, "University Auditorium")
        self.assertEqual(event_2.duration, 2)

    def test_str_method(self):
        """
        Test the string method of the Event class
        :return: None
        """
        event_1 = Event(self.event_1)
        expected_str_1 = "Event: Lecture on AI\nDate: 2023-10-15\nStart time: 14:00\nDuration: 2 hours\nLocation: " \
                         "Bruner 228"
        self.assertEqual(str(event_1), expected_str_1)

        event_2 = Event(self.event_2)
        expected_str_2 = "Event: Music Concert\nDate: 2023-12-08\nStart time: 19:30\nDuration: 2 hours\nLocation: " \
                         "University Auditorium"
        self.assertEqual(str(event_2), expected_str_2)

    def test_getters(self):
        event = Event(self.event_1)

        self.assertFalse(callable(getattr(event, "name")),
                         msg="name should only be a property using the property decorator")
        self.assertFalse(callable(getattr(event, "uid")),
                         msg="uid should only be a property using the property decorator")
        self.assertFalse(callable(getattr(event, "date")),
                         msg="date should only be a property using the property decorator")
        self.assertFalse(callable(getattr(event, "start_time")),
                         msg="start_time should only be a property using the property decorator")
        self.assertFalse(callable(getattr(event, "location")),
                         msg="location should only be a property using the property decorator")
        self.assertFalse(callable(getattr(event, "duration")),
                         msg="duration should only be a property using the property decorator")

    def test_not_setters(self):
        event = Event(self.event_1)

        # PyCharm should rightfully say something like, "Property '<property>' cannot be set"
        with self.assertRaises(AttributeError) as context:
            event.name = "New Event"
        self.assertEqual(
            f"property 'name' of 'Event' object has no setter",
            str(context.exception),
            msg="name should not allow direct assignment"
        )

        with self.assertRaises(AttributeError) as context:
            event.uid = "123456"
        self.assertEqual(
            f"property 'uid' of 'Event' object has no setter",
            str(context.exception),
            msg="uid should not allow direct assignment"
        )

        with self.assertRaises(AttributeError) as context:
            event.date = "2024-03-01"
        self.assertEqual(
            f"property 'date' of 'Event' object has no setter",
            str(context.exception),
            msg="date should not allow direct assignment"
        )

        with self.assertRaises(AttributeError) as context:
            event.start_time = "10:00"
        self.assertEqual(
            f"property 'start_time' of 'Event' object has no setter",
            str(context.exception),
            msg="start_time should not allow direct assignment"
        )

        with self.assertRaises(AttributeError) as context:
            event.location = "New York"
        self.assertEqual(
            f"property 'location' of 'Event' object has no setter",
            str(context.exception),
            msg="location should not allow direct assignment"
        )

        with self.assertRaises(AttributeError) as context:
            event.duration = 60
        self.assertEqual(
            f"property 'duration' of 'Event' object has no setter",
            str(context.exception),
            msg="duration should not allow direct assignment"
        )

    def test_input_checking(self):
        """
        Tests whether attribute types are checked at runtime. These should follow the format:
        `assert(isinstance(data[<attribute>], <type>))` for most cases.
        """
        # Test that keys are checked in the dictionary by passing an empty dictionary. This should not fail.
        Event({})

        with self.assertRaises(
                AssertionError,
                msg="The type of \"Name\" is not tested"):
            bad_event_name: dict = {
                "Name": 77_65_86_69_58,
                "UID": 0,
                "Date": "2023-10-15",
                "StartTime": "14:00",
                "Location": "Bruner 228",
                "Duration": 2
            }
            Event(bad_event_name)
        with self.assertRaises(
                AssertionError,
                msg="The type of \"Date\" is not tested"):
            bad_event_date: dict = {
                "Name": "Lecture on AI",
                "UID": 0,
                "Date": 2023_10_15,
                "StartTime": "14:00",
                "Location": "Bruner 228",
                "Duration": 2
            }
            Event(bad_event_date)
        with self.assertRaises(
                AssertionError,
                msg="The type of \"UID\" is not tested"):
            bad_event_uid: dict = {
                "Name": "Lecture on AI",
                "UID": "0",
                "Date": "2023-10-15",
                "StartTime": "14:00",
                "Location": "Bruner 228",
                "Duration": 2
            }
            Event(bad_event_uid)
        with self.assertRaises(
                AssertionError,
                msg="The type of \"StartTime\" is not tested"):
            bad_event_start_time: dict = {
                "Name": "Lecture on AI",
                "UID": 0,
                "Date": "2023-10-15",
                "StartTime": 1400,
                "Location": "Bruner 228",
                "Duration": 2
            }
            Event(bad_event_start_time)
        with self.assertRaises(
                AssertionError,
                msg="\"StartTime\" is not validated."):
            bad_event_start_time: dict = {
                "Name": "Lecture on AI",
                "UID": 0,
                "Date": "2023-10-15",
                "StartTime": "24:60",
                "Location": "Bruner 228",
                "Duration": 2
            }
            Event(bad_event_start_time)
        with self.assertRaises(
                AssertionError,
                msg="The type of \"Location\" is not tested"):
            bad_event_location: dict = {
                "Name": "Lecture on AI",
                "UID": 0,
                "Date": "2023-10-15",
                "StartTime": "14:00",
                "Location": 228,
                "Duration": 2
            }
            Event(bad_event_location)
        with self.assertRaises(
                AssertionError,
                msg="The type of \"Duration\" is not tested"):
            bad_event_duration: dict = {
                "Name": "Lecture on AI",
                "UID": 0,
                "Date": "2023-10-15",
                "StartTime": "14:00",
                "Location": "Bruner 228",
                "Duration": "2000"
            }
            Event(bad_event_duration)


if __name__ == '__main__':
    unittest.main()
