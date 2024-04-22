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
        self.Events = []
        self.Contacts = []
        self.EventAttendees = []
        self.EventUID = 0
        self.ContactUID = 0
    # getters (5 methods)
        @property
        def Events(self):
            self.Events
        
        @property
        def Contacts(self):
            self.Contacts
        
        @property
        def EventAttendees(self):
            self.EventAttendees
        
        @property
        def EventUID(self):
            self.EventUID
        
        @property
        def ContactUID(self):
            self.ContactUID
    # setters (5 methods)

    # other methods (6 methods)

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
