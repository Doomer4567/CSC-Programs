import json


class Contact:
    def __init__(self, uid: int, firstname: str, lastname: str, email: str, department: str, title: str, phone: str,
                 building: str, mail_code: str):
        self.__uid = uid
        self.__firstname = firstname
        self.__lastname = lastname
        self.__title = title
        self.__email = email
        self.__department = department
        self.__phone = phone
        self.__building = building
        self.__mail_code = mail_code
        self.__last_contact = None

    @property
    def firstname(self):
        return self.__firstname

    @property
    def lastname(self):
        return self.__lastname

    @property
    def uid(self):
        return self.__uid

    @property
    def email(self):
        return self.__email

    @property
    def department(self):
        return self.__department

    @property
    def title(self):
        return self.__title

    @property
    def phone(self):
        return self.__phone

    @property
    def building(self):
        return self.__building

    @property
    def mail_code(self):
        return self.__mail_code

    def last_contact(self, date):
        self.__last_contact = date

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


def main():
    with open('contacts.json') as f:
        contact_data = json.load(f)

    contacts = {}
    for x in contact_data:
        new_contact = Contact(x["FirstName"], x["LastName"], x["UID"], x["EmailAddress"], x["Dept"], x["Title"],
                              x["Phone"], x["Building"], x["POBox"])
        contacts.update({x["EmailAddress"]: new_contact})

