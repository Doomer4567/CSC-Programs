from classes.Contact import Contact
from classes.Event import Event

"""
This class represents a tuple of 1 Event and 1 Contact object, meaning the Contact is attending the Event.
This is its own class because there will be attributes associated to a contact attending an event, e.g.
whether they need a parking pass, special accommodations, etc. 

For now, the "memo" attribute is a catch-all for these, but in the future, more attributes will be added.
"""


class EventAttendee:

    def __init__(self, contact: str, event: str):
        self.contact = contact
        self.event = event
        self.__memo = ""

    @property
    def contact(self) -> str:
        return self.contact
    @contact.setter
    def contact(self, ):
        self.contact = Contact

    @property
    def event(self) -> str:
        return self.event

    @event.setter
    def event(self):
        self.event = Event

    @property
    def memo(self):
        return self.__memo


    # This function defines what happens when you print the object as text, i.e. print(event_attendee)
    # PRINTS IN THE FORM "John Smith attending Data Science League Meeting"
    def __str__(self):
        """
        python has a few ways of streamlining concatenation of strings.
        each time there's a {} in the string that represents a variable.
        notice at the end of the string, ".format()"
        the variables passed into this function will replace each {} (in order)
        """
        return "{} {}\nattending\n{}".format(self.contact.firstname, self.contact.lastname, self.event.name)
