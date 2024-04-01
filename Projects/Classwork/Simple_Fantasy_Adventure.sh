#! /bin/bash

echo " ! Welcome $1, to !"
echo " ! THE SIMPLE FANTASY ADVENTURE ! "

echo "Please answer the following questions :)"
echo
#Class Choice
read -rp "What is Your Class? (Mage, Knight, Peasant, Hippo): " UsrClass
echo
if [ "$UsrClass" = "Mage" ]; then
    echo "The Wise and mystical Mage, Will you Outsmart the evil in the kingdom?"

elif [ "$UsrClass" = "Knight" ]; then
    echo "The Honarable and Bave Knight, Will you Lead the charge against the injustice in this kindom?"

elif [ "$UsrClass" = "Peasant" ]; then
    echo "The Peasant? Uh This may be bugged"

elif [ "$UsrClass" = "Hippo" ]; then
    echo "!SECURITY BREACH! !SECURITY BREACH! !THE HIPPO HAS BREACHED CONTAINMENT!"
else
    echo "Invalid choice: Please Restart"
    exit
fi

read -rp "Press Enter to Continue"
#Home Choice
read -rp "Where were you born? (Forest, Mountains, Village, Dessert, Jungle): " UsrHome
echo
if [ "$UsrHome" = "Forest" ]; then
    echo  "The Beautiful Forest, Home to many mystical beasts and Home to many mystical adventures."


elif [ "$UsrHome" = "Mountains" ]; then
    echo  "The Tall Mountains, Home to the hidden and rewarding to those who dare."


elif [ "$UsrHome" = "Village" ]; then
    echo  "The Welcoming Village, Home to many Courageous Knights and warriors."


elif [ "$UsrHome" = "Dessert" ]; then
    echo  "D-Dessert? Who Made this Uh Home to the Sweet and Kind."


elif [ "$UsrHome" = "Jungle" ]; then
    echo  "You know where you are? You're in the jungle, baby! You're gonna die!"


else
    echo "Invalid choice: Please Restart"
    exit
fi

read -rp "Press Enter to Continue"
#Weapon Choice
read -rp "What is your Weapon? (Mace, Sword, Bow, Spell Book, Cantaloupe): " UsrWeapon
echo

if [ "$UsrWeapon" = "Mace" ]; then
    echo "The Mace, A strong Weapon for a strong Body."


elif [ "$UsrWeapon" = "Sword" ]; then
    echo "The Sword, Weaker then the pen? I don't know about that."


elif [ "$UsrWeapon" = "Bow" ]; then
    echo "The Bow, in my opinion, I find bow users annoying."


elif [ "$UsrWeapon" = "Spell Book" ]; then
    echo "The Spell Book, Supposedly if you can't read it, You'll be cursed."


elif [ "$UsrWeapon" = "Cantaloupe" ]; then
    echo "The HUH? Im sorry I Don't know whats wrong with this game"


else
    echo "Invalid choice: Please Restart"
    exit
fi

read -rp "Press Enter to Continue"
#Motive Choice
read -rp "What would be the first thing you do, if you were a $UsrClass? (Campaign, Explore, Sleep, Eat): " UsrMotive

if [ "$UsrMotive" = "Campaign" ]; then
    echo "Onward to Adventure Hero, The weight of the world is on your shoulder!"

elif [ "$UsrMotive" = "Explore" ]; then
    echo "You began by exploring, You may be able to expose a great weakness to fight against the evil!"


elif [ "$UsrMotive" = "Sleep" ]; then
    echo "SLEEP!, You are given such a important responsibility and you sleep!?. Why is it even an option!"


elif [ "$UsrMotive" = "Eat" ]; then
    echo "E-E-Eat! *Cough* You Eat graciously and prepare your stomach for the great evil in the kitchen!"


else
    echo "Invalid choice: Please Restart"
    exit
fi
read -rp "Press Enter to Continue"

echo "Wake up in the mornin' feelin' like $1 (hey, what up girl?) Grab my glasses, I'm out the door, I'm gonna hit this $UsrHome.
Before I leave, brush my teeth with a $UsrWeapon 'Cause when I leave for the night. I ain't comin' back I'm talkin' pedicure on our toes, toes
Tryin' on all our clothes, clothes. Boys blowin' up our phones, phones. Drop-toppin', playin' our favorite CDs
Pullin' up to $UsrMotive Tryna get a little bit tipsy. Don't stop, make it pop DJ, blow my speakers up
Tonight, I'ma fight 'Til we see the sunlight. Tick-tock on the clock But the party don't stop, no
Oh, whoa, whoa-oh Oh, whoa, whoa-oh"



