
class Event:

    def __init__(self, event_dict):
        self.__UID = event_dict.get('UID', "")
        self.__Name = event_dict.get('Name', "")
        self.__Date = event_dict.get('Date', "")
        self.__StartTime = event_dict.get('StartTime', "")
        self.__Location = event_dict.get('Location', "")
        self.__Duration = event_dict.get('Duration', "")

    @property
    def UID(self):
        return self.__UID

    @property
    def Name(self):
        return self.__Name

    @property
    def Date(self):
        return self.__Date

    @property
    def StartTime(self):
        return self.__StartTime

    @property
    def Location(self):
        return self.__Location

    @property
    def Duration(self):
        return self.__Duration

    # This function defines what happens when you print the object as text i.e., print(Event)
    def __str__(self) -> str:
        """
        python has a few ways of streamlining concatenation of strings.
        each time there's a {} in the string that represents a variable.
        notice at the end of the string, ".format()"
        the variables passed into this function will replace each {} (in order)
        """
        return "Event: {}\nDate: {}\nStart time: {}\nDuration: {} hours\nLocation: {}" \
            .format(self.Name, self.Date, self.StartTime, self.Duration, self.Location)

    def __eq__(self, other: 'Event') -> bool:
        return self.Name == other.Name and \
            self.UID == other.UID and \
            self.Date == other.Date and \
            self.StartTime == other.StartTime and \
            self.Location == other.Location and \
            self.Duration == other.Duration
