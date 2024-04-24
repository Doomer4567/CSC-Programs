from EventAttendee import EventAttendee
from Event import Event
from Contact import Contact

'''
This file is where the bulk of your work will be done. 
I have listed each category of method you will need to create in the comments.
I have also listed how many methods will appear in each category.
'''


class EventManager:
    """
    This class is meant to manage the Events, Contacts, and Event_Attendees.
    This class also directly communicates with the GUI as the GUI "has" an EventManager object (aggregation).
    This class has a list of Event objects, a list of Contact objects, and a list of EventAttendee objects.
    """

    # constructor (1 method)

    def __init__(self):
        self.events = []
        self.contacts = []
        self.eventattendees = []
        self.eventuid = 0
        self.contactuid = 0

    # getters (5 methods)
    @property
    def events(self):
        return self.events

    @property
    def contacts(self):
        return self.contacts

    @property
    def eventattendees(self):
        return self.eventattendees

    @property
    def eventuid(self):
        return self.eventuid

    @property
    def contactuid(self):
        return self.contactuid

    # setters (5 methods)
    @events.setter
    def events(self, events):
        self.events = events

    @contacts.setter
    def contacts(self, contacts):
        self.contacts = contacts

    @eventattendees.setter
    def eventattendees(self, eventattendees):
        self.eventattendees = eventattendees

    @eventuid.setter
    def eventuid(self, eventuid):
        self.eventuid = eventuid

    @contactuid.setter
    def contactuid(self, contactuid):
        self.contactuid = contactuid

    # other methods (6 methods)

    def add_event(self, x):
        self.events = x
        self.eventuid += 1
        self._sort_events()

    def add_contact(self, x):
        self.contacts = x
        self.contactuid += 1
        self._sort_contacts()

    def is_attending(self, contact=EventAttendee.contact):
        for x in self.eventattendees():
            for y in self.contacts(contact):
                if x == y:
                    return True
                else:
                    return False

    def add_event_attendee(self, contact=EventAttendee.contact):
        if self.is_attending(contact):
            return self.events
        else:
            return None

    def uid_to_event(self):
        for x in self.events:
            if Event.uid == self.eventuid:
                return self.events
            else:
                return None

    def uid_to_contact(self):
        for x in self.contacts:
            if Contact.uid == self.contactuid:
                return self.contacts
            else:
                return None

    # pre-existing methods (2 methods; they are already here; no need to touch them)

    def _sort_contacts(self) -> None:
        """
        Sort contacts by their last name
        :returns: None
        """
        # sort the list by lastname (alphabetically)
        self.contacts.sort(key=lambda x: x.lastname)

    def _sort_events(self) -> None:
        """
        Sort the stored events by date
        :returns: None
        """
        self.events.sort(key=lambda x: x.date, reverse=False)
