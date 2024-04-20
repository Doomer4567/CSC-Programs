
class Shapeshifter:
    def __init__(self, form:str):
        if form in ['Human', 'Wolf', 'Crow']:
            self.__form = form
        else:
                raise Exception("Invalid input. Form must be 'Human', 'Wolf', or 'Crow'")

    @property
    def form(self):
        if self.__form == 'Human':
            return 'Human'
        elif self.__form == 'Wolf':
            return 'Wolf'
        elif self.__form == 'Crow':
            return 'Crow'
        else:
            raise Exception('Error. Invalid form detected.')
    def voice(self):
        if self.__form == 'Human':
            return 'Hello'
        elif self.__form == 'Wolf':
            return 'Awo'
        elif self.__form == 'Crow':
            return 'Caw'
        else:
            raise Exception('Error. Invalid form detected.')

    def legs(self):
        if self.__form == 'Human':
            return 2
        elif self.__form == 'Wolf':
            return 4
        elif self.__form == 'Crow':
            return 0
        else:
            raise Exception('Error. Invalid form detected.')

    def wings(self):
        if self.__form == 'Human':
            return 0
        elif self.__form == 'Wolf':
            return 0
        elif self.__form == 'Crow':
            return 2
        else:
            raise Exception('Error. Invalid form detected.')
    def arms(self):
        if self.__form == 'Human':
            return 2
        elif self.__form == 'Wolf':
            return 0
        elif self.__form == 'Crow':
            return 0
        else:
            raise Exception('Error. Invalid form detected.')
    def tail(self):
        if self.__form == 'Human':
            return 0
        elif self.__form == 'Wolf':
            return 1
        elif self.__form == 'Crow':
            return 0
        else:
            raise Exception('Error. Invalid form detected.')
