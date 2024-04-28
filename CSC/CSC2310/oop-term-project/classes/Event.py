
class Event:

    def __init__(self, event_dict):
        self.UID = event_dict.get('UID', "")
        self.Name = event_dict.get('Name', "")
        self.Date = event_dict.get('Date', "")
        self.StartTime = event_dict.get('StartTime', "")
        self.Location = event_dict.get('Location', "")
        self.Duration = event_dict.get('Duration', "")

        @property
        def UID(self):
            return self.UID
        
        @property
        def Name(self):
            return self.Name

        @property
        def Date(self):
            return self.Date

        @property
        def StartTime(self):
            return self.StartTime
        
        @property
        def Location(self):
            return self.Location
        
        @property
        def Duration(self):
            return self.Duration

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
