import json
class Event:

    def __init__(self, uid: int, name: str, date: str, start_time: str, location: str, duration: int ):
        self.__uid = uid
        self.__name = name
        self.__date = date
        self.__start_time = start_time
        self.__location = location
        self.__duration = duration

    @property
    def uid(self):
        return self.__uid

    @property
    def name(self):
        return self.__name

    @property
    def date(self):
        return self.__date

    @property
    def start_time(self):
        return self.__start_time

    @property
    def location(self):
        return self.__location

    @property
    def duration(self):
        return self.__duration

    # This function defines what happens when you print the object as text i.e., print(Event)
    def __str__(self) -> str:
        """
        python has a few ways of streamlining concatenation of strings.
        each time there's a {} in the string that represents a variable.
        notice at the end of the string, ".format()"
        the variables passed into this function will replace each {} (in order)
        """
        return "Event: {}\nDate: {}\nStart time: {}\nDuration: {} hours\nLocation: {}" \
            .format(self.name, self.date, self.start_time, self.duration, self.location)

    def __eq__(self, other: 'Event') -> bool:
        return self.__name == other.name and \
            self.__uid == other.uid and \
            self.__date == other.date and \
            self.__start_time == other.start_time and \
            self.__location == other.location and \
            self.__duration == other.duration

def main():
    with open('events.json') as f:
        event_data = json.load(f)

    events = {}
    for x in event_data:
        new_event = Event(x["Name"], x["UID"], x["Date"], x["StartTime"], x["Location"], x["Duration"])
        events.update({x["Name"]: new_event})
