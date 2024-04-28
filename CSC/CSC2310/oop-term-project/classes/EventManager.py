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
        self.__eventAttendees = []
        self.__eventUID = 0
        self.__contactUID = 0

    # getters (5 methods)
    # setters (5 methods)
    @property
    def events(self):
        return self.__events

    @events.setter
    def events(self, newevents):
        self.__events = newevents

    @property
    def contacts(self):
        return self.__contacts

    @contacts.setter
    def contacts(self, newcontacts):
        self.__contacts = newcontacts

    @property
    def eventAttendees(self):
        return self.__eventAttendees

    @eventAttendees.setter
    def eventAttendees(self, newEventAttendees):
        self.__eventAttendees = newEventAttendees

    @property
    def eventUID(self):
        return self.__eventUID

    @eventUID.setter
    def eventUID(self, newEventUID):
        self.__eventUID = newEventUID

    @property
    def contactUID(self):
        return self.__contactUID

    @contactUID.setter
    def contactUID(self, newContactUID):
        self.__contactUID = newContactUID

    # other methods (6 methods)

    def add_event(self, eventDict):
        newEventID = Event(eventDict)

        # newEvent = Event(newEventID, eventDict['name'], eventDict['date'], eventDict['start_time'], eventDict[
        # 'location'], eventDict['duration'])

        self.__events.append(newEventID)
        self.__eventUID += 1
        self._sort_events()

    def add_contact(self, contactDict):
        newContact = Contact(contactDict)

        # newContact = Contact(newContactID)  contactDict['lastname'], contactDict['emailaddress'], contactDict[
        # 'dept'], contactDict['title'], contactDict['phone'], contactDict['building'], contactDict['mailcode'],
        # contactDict['lastContact'])

        self.__contacts.append(newContact)
        self.__contactUID += 1
        self._sort_contacts()

    # finish this shit
    def is_attending(self, contact, event):
        for i in self.__eventAttendees:
            for j in self.contacts:
                if i == j:
                    return True
                else:
                    return False

    def add_event_attendee(self, contact, event):
        if self.is_attending(self, contact):
            return self.events
        else:
            EventAttendee(contact, event)
            self.__eventAttendees.append(contact)
            return None

        # newAttendee = EventAttendee(contact, event)
        # self.__eventAttendees.append(newAttendee)

    def uid_to_event(self, UID):
        for i in self.events:
            if UID == self.eventUID:
                return self.events
            else:
                return None

    def uid_to_contact(self, UID):
        for i in self.contacts:
            if Contact.UID == self.contactUID:
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
        self.contacts.sort(key=lambda x: x.LastName)

    def _sort_events(self) -> None:
        """
        Sort the stored events by date
        :returns: None
        """
        self.events.sort(key=lambda x: x.Date, reverse=False)
