from Levenshtein import distance
from typing import List
from classes.Contact import Contact

'''
This class is used to perform the search function on the Contact List and Event List in the GUI.
You (the student) do not need to do any work here.
'''


class SearchContacts(object):
    """
    Uses Levenshtein distance, a fuzzy string matching algorithm, to search a list of contacts.
    """

    @staticmethod
    def search(query: str, contact_list: List[Contact]) -> List[Contact]:
        """
        Search a given list of contacts.
        :param query: Query to search the list of contacts for.
        :param contact_list: List of contacts to search.
        :return: List of contacts sorted by relevancy.
        """
        # Short circuit on an empty query
        if len(query) == 0:
            return contact_list
        contact_scores: List[tuple] = []

        # Iterate through the list of contacts, finding the edit distance of each attribute
        for contact in contact_list:
            # Build a list of the scores for each attribute
            scores: List[int] = [distance(str(contact.UID), query), distance(contact.FirstName, query),
                                 distance(contact.LastName, query), distance(contact.EmailAddress, query),
                                 distance(contact.Dept, query), distance(contact.Title, query),
                                 distance(contact.Phone, query), distance(contact.Building, query),
                                 distance(contact.POBox, query), distance(contact.lastContact, query)]
            # Append to our list of contacts, taking the minimum edit distance score.
            contact_scores.append((min(scores), contact))

        # Sort by that edit distance, rendering the lowest edit distance first and the highest edit distance last as
        # a measure of the relevance to the query of each Contact.
        contact_scores.sort(key=lambda x: x[0])

        # Remove the scores from the list, leaving us with only a list of Contacts.
        return [contact[1] for contact in contact_scores]
