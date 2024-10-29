use std::fs::File;
use std::io::{self, BufRead};
use std::path::Path;
use County.rs

fn main() {
    
    let mut List = vec![County];
    let County= &mut newCounty;

    if let Ok(lines) = read_lines("counties_list.sv") {
        // Consumes the iterator, returns an (Optional) String
        for line in lines.flatten() {
            lf let mut Some((index,county,state,pop)) = text.split_once(',') {
                *newCounty = new County(index,county,state,pop);
                List.append(*newCounty);
            }
        }
    }

    while(input > 2 || input < 0){
        println!("Choose a Sorting Algorithm (1. MergeSort, 2. SelectionSort): ")
        let mut input

        match input {
            1 => 
                List.println();
                List.MergeSort();
                List.println();
                break;

            2 => 
                List.SelectionSort;
                List.println();
                break;

            _ => println!("Invalid Choice, Try Again!")
        }
    }
}


fn read_lines<P>(filename: P) -> io::Result<io::Lines<io::BufReader<File>>>
where P: AsRef<Path>, {
    let file = File::open(filename)?;
    Ok(io::BufReader::new(file).lines())
}