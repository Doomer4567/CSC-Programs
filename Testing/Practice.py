rooms = {
    'Entrance':
        {'west': 'Treasure Room'},
    'Treasure Room':
        {'south': 'Dining Hall', 'East': 'Entrance'},
    'Dining Hall': {
        'north': 'Treasure Room', 'West': 'Secret Treasure Room', 'East': 'Long Omious Corridor',
        'south': 'Witchs Bedroom'
    },
    'Secret Treasure Room':
        {'east': 'Dining Hall'},
    'Witchs Bedroom': {
        'north': 'Dining Hall', 'East': 'Witchs Bedroom Closet'
    },
    'Witchs Bedroom Closet': {
        'west': 'Witchs Bedroom'
    },
    'Long Omious Corridor': {
        'west': 'Dining Hall', 'North': 'Witchs Throne Room'
    }
}


def main():
    command = ''
    current_room = 'Entrance'
    print(rooms[current_room])
    while command != 'exit':
        command = input()
        command = command.lower()
        if command in ["north", "south", "east", "west"]:
            if command in rooms[current_room]:
                current_room = rooms[current_room][command]
            else:
                print("You can't go that way.")
        print(current_room)
        command = 'exit'


main()
