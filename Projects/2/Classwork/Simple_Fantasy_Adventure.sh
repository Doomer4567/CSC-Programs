#! /bin/bash
UsrInt=0
echo "Welcome to your SIMPLE FANTASY ADVENTURE!"
echo
echo "Before we begin, We need to setup your character and weapons"
while(UsrInt <= 0 || UsrInt >= 5)
do
   read -pr "Choose a Class (1.Mage,2.Knight,3.Peasant,4.Crow): " UsrInt 
done

UsrClass=UsrInt
UsrInt=0
while(UsrInt <= 0 || UsrInt >= 5)
do
    read -p "Great, Now Choose where you call Home!(1.Forest,2.Mountain,3.Village,4.Dessert,5.Jungle)" UsrInt
done

UsrHome=UsrInt

echo UsrClass
echo UsrHome