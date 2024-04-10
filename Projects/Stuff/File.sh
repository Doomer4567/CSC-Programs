#! /bin/bash
#Makes Directory
mkdir Peppers
cd Peppers || exit
URL="https://swollenhippo.com/crockett.php/peppers?APIKey=0BE51E93-631C-4D26-A81E-BF0F7A9E2D1B"
#Sets up jq with the url
Array=$(curl "$URL")
length=$(echo "$Array" | jq  'length')
counter=0
#Only finished after reaching the last peppa
while [ "$counter" -lt "$length" ];
do
#find pepper title
Title=$(echo "$Array" | jq -r .[$counter].PepperName)
touch "$Title"
#Grabs the color size and heat unit of pepper
Color=$(echo "$Array" | jq -r .[$counter].PepperColor)
Size=$(echo "$Array" | jq -r .[$counter].PepperSize)
SHU=$(echo "$Array" | jq  -r .[$counter].ScovilleHeatUnitsSHU)
#Prints it into a file
echo "Color:$Color | Size:$Size | Scoville Heat Unit:$SHU" >> "$Title"
((counter++))
done
#cd out to avoid bugs
cd ..
