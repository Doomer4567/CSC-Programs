#!/bin/bash
#Description: This script is desgined to query the gutendex to return information about a set of given
#books. The information regarding download_count is stored to a file for each books. Books are chosen
#by passing a set of parameters as book_id to the script.
#
#Author: Ethan Byker
#
#Creation Date: 09 April 2024
strCurlUrl:"http://gutendex.com/books/?ids="
for strBookID in "#@"; do
strCurlURL+=${strBookID},00
done
