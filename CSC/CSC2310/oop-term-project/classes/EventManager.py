from classes.EventAttendee import EventAttendee
from classes.Event import Event
from classes.Contact import Contact

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
        self.__events = []
        self.__contacts = []
        self.__event_attendees = []
        self.__event_uid = 0
        self.__contact_uid = 0

    # getters (5 methods)
    @property
    def events(self) -> list[Event]:
        return self.__events

    @property
    def contacts(self) -> list[Contact]:
        return self.__contacts

    @property
    def event_attendees(self) -> list[EventAttendee]:
        return self.__event_attendees

    @property
    def event_uid(self) -> int:
        return self.__event_uid

    @property
    def contact_uid(self) -> int:
        return self.__contact_uid

    # setters (5 methods)
    @events.setter
    def events(self, events: list[Event]):
        self.__events = events

    @contacts.setter
    def contacts(self, contacts: list[Contact]):
        self.__contacts = contacts

    @event_attendees.setter
    def event_attendees(self, event_attendees: list[EventAttendee]):
        self.__event_attendees = event_attendees

    @event_uid.setter
    def event_uid(self, event_uid: int):
        self.__event_uid = event_uid

    @contact_uid.setter
    def contact_uid(self, contact_uid: int):
        self.__contact_uid = contact_uid

    # other methods (6 methods)

    #After an Event gets made this function appends it to the EventManager's
    #events list and gives it a uid then increasing the uid and sort it into the events list
    def add_event(self, event: dict):
        new_event = Event(event)
        self.events.append(new_event)
        self.event_uid += 1
        self._sort_events()

    #similar to the add_event method
    def add_contact(self, contact: dict):
        new_contact = Contact(contact)
        self.contacts.append(new_contact)
        self.contact_uid += 1
        self._sort_contacts()

    #checks to see if the contact is already attending 
    def is_attending(self, contact: Contact, event: Event):
        for attendee in self.event_attendees:
            if attendee.contact == contact and attendee.event == event:
                return True
        return False
    #uses the is_attending method to check if a contact is attending and if returned false then adds the contact to the list
    def add_event_attendee(self, event: Event, contact: Contact):
        if not self.is_attending(contact, event):
            attendee = EventAttendee(contact, event)
            self.event_attendees.append(attendee)

    #gives the event a uid
    def uid_to_event(self, uid: int):
        for event in self.events:
            if uid == event.uid:
                return event
        return None
    #give the contact a uid
    def uid_to_contact(self, uid: int):
        for contact in self.contacts:
            if uid == contact.UID:
                return contact
        return None

    # pre-existing methods (2 methods; they are already here; no need to touch them)

    def _sort_contacts(self) -> None:
        """
        Sort contacts by their last name
        :returns: None
        """
        # sort the list by lastname (alphabetically)
        self.contacts.sort(key=lambda x: x.LastName)

    def _sort_events(self) -> None:
        """
        Sort the stored events by date
        :returns: None
        """
        self.events.sort(key=lambda x: x.Date, reverse=False)
