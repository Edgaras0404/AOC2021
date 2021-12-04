use std::fs::File;
use std::io::prelude::*;
use std::path::Path;


fn main() {
    let path = Path::new("input.txt");
    let display = path.display();

    let mut file = match File::open(&path) {
        Err(why) => panic!("Failed to open {}: {}", display, why),
        Ok(file) => file,
    };

    let mut numbers = String::new();
    match file.read_to_string(&mut numbers) {
        Err(why) => panic!("Failed to read {}: {}", display, why),
        Ok(_) => (),
    }

    let numbers: Vec<i32> = numbers
        .split_whitespace()
        .map(|s| s.parse().expect("Failed to parse data"))
        .collect();
    let mut temp: i32 = numbers[0];
    let mut result: u32 = 0;
    for num in numbers {
        if num > temp {
            result += 1;
        }
        temp = num;
    }

    println!("The result is {}", result);
}
