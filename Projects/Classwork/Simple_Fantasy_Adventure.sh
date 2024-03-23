#!/usr/bin/bash
Classes=(Mage Knight Peasant Crow)
Location=(Forest Mountain Village Dessert Jungle)

Class () {
    select choice in "${Classes[@]}"; do
    if [[ " ${Classes[*]} " == *" $choice "* ]]; then
        break;
    else
        echo "Invalid Choice: $REPLY"
    fi
done
}

Location () {
    select choice in "${Location[@]}"; do
    if [[ " ${Location[*]} " == *" $choice "* ]]; then
        break;
    else
        echo "Invalid Choice: $REPLY"
    fi
done
}



echo "Welcome to your SIMPLE FANTASY ADVENTURE!"
echo
echo "Before we begin, We need to setup your character and weapons"
read -rp "Whats your Name, Adventurer!?: " UsrName
echo "Choose a Class!"
    Class
    UsrClass=$choice

echo "Great, Now Choose where you call Home!"
    Location
    UsrHome=$choice


echo "So you have chosen to be a $UsrClass in the $UsrHome, Its time to wake up $UsrName! The World Needs you!"
echo "$UsrName! $UsrName! Wake up $UsrName, Your gonna miss the Class Selection Cermony!"
read -rp "Press Enter to Continue" 
echo "You wake up in your lovely $UsrHome Home, The Class selection is a very important cermony around thr world."
echo "It defines who you are and your future career, there are rarities in classes and some become royal attendents."
echo "As you step up, Ready to here your future. After the dream you had, You already know your gonna be a $UsrClass."
echo "The priest puts his hand on you, and as you wait for the right words he says, 'A HERO!, Our Savior is here to fight the Demon Lord'."
UsrClass="Hero $UsrClass"
echo "!Your class is now $UsrClass!"
echo "It's time $UsrName, Make your way to The Captial and meet with the king to fufill your Noble Duty"
read -rp "Press Enter to Continue"
echo "Entering the captial, Its a beautiful Luscious Kingdom. Citizens are happy, The Economy is great but war is on the way."
echo "Meeting the King, You are given 3 choices. 1. You can either Join the frontlines, 2. Take on duties for the king, or 3. Die"
choice=0
while [ "$choice" -lt 1 ] || [ "$choice" -gt 4 ]
do
    read -rp "Choose (1-4): " choice
    if [ "$choice" -gt 1 ] || [ "$choice" -lt 4 ]; then
        break;
    else 
        echo "Invalid Choice"
    fi
done
