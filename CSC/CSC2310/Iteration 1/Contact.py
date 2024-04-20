import json

class Contact:
    def __init__(self, contact_info: dict):
        self.__firstname = contact_info.get("FirstName", "")
        self.__lastname = contact_info.get("LastName", "")
        self.__title = contact_info.get("Title", "")
        self.__email = contact_info.get("Email", "")
        self.__department = contact_info.get("department", "")
        self.__phone = contact_info.get("PhoneNumber", "")
        self.__building = contact_info.get("Building", "")
        self.__last_contact = None

    def __str__(self) -> str:
        """
        Dunder method that defines what happens when you print a Contact object.
        :return: String defining the object
        """
        return f"{self.__firstname} {self.__lastname}\nTitle: {self.__title}\nEmail: {self.__email}\nDepartment: " \
               f"{self.__department}\nPhone: {self.__phone}\nBuilding: {self.__building}\nLDC: {self.__last_contact}"

    def __eq__(self, other: 'Contact') -> bool:  # Using quotes around the type allows for typing of this class here
        """
        Dunder method that defines whether two Contact objects are equal based on their attributes.
        :param other: Another contact object.
        :return: Equality evaluation.
        """
        return self.__uid == other.uid and \
            self.__firstname == other.firstname and \
            self.__lastname == other.lastname and \
            self.__email == other.email and \
            self.__department == other.department and \
            self.__title == other.title and \
            self.__phone == other.phone and \
            self.__building == other.building and \
            self.__mail_code == other.mail_code and \
            self.__last_contact == other.last_contact
