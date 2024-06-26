class Contact:
    def __init__(self, contact: dict):
        self.__UID = contact.get('UID', "")
        self.__FirstName = contact.get('FirstName', "")
        self.__LastName = contact.get('LastName', "")
        self.__EmailAddress = contact.get('EmailAddress', "")
        self.__Dept = contact.get('Dept', "")
        self.__Title = contact.get('Title', "")
        self.__Phone = contact.get('Phone', "")
        self.__Building = contact.get('Building', "")
        self.__POBox = contact.get('POBox', "")
        self._lastContact = ""

    @property
    def UID(self):
        return self.__UID

    @property
    def FirstName(self):
        return self.__FirstName

    @property
    def LastName(self):
        return self.__LastName

    @property
    def EmailAddress(self):
        return self.__EmailAddress

    @property
    def Dept(self):
        return self.__Dept

    @property
    def Title(self):
        return self.__Title

    @property
    def Phone(self):
        return self.__Phone

    @property
    def Building(self):
        return self.__Building

    @property
    def POBox(self):
        return self.__POBox

    @property
    def lastContact(self):
        return self._lastContact

    @lastContact.setter
    def lastContact(self, value: str):
        self._lastContact = value

    def __str__(self) -> str:
        """
        Dunder method that defines what happens when you print a Contact object.
        :return: String defining the object
        """
        return f"{self.__FirstName} {self.__LastName}\nTitle: {self.__Title}\nEmail: {self.__EmailAddress}\nDepartment: " \
               f"{self.__Dept}\nPhone: {self.__Phone}\nBuilding: {self.__Building}\nLDC: {self._lastContact}"

    def __eq__(self, other: 'Contact') -> bool:  # Using quotes around the type allows for typing of this class here
        """
        Dunder method that defines whether two Contact objects are equal based on their attributes.
        :param other: Another contact object.
        :return: Equality evaluation.
        """
        return self.__UID == other.UID and \
            self.__FirstName == other.__FirstName and \
            self.__LastName == other.__LastName and \
            self.__EmailAddress == other.EmailAddress and \
            self.__Dept == other.Dept and \
            self.__Title == other.Title and \
            self.__Phone == other.Phone and \
            self.__Building == other.Building and \
            self.__POBox == other.POBox and \
            self._lastContact == other.lastContact
