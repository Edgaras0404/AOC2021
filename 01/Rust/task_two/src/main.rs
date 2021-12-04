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

    let mut temp: i64;
    let mut sum: i64;
    let mut result: u32 = 0;

    let mut i = 0;
    while i < (numbers.len() - 3) {
        temp = 0;
        sum = 0;

        let mut j = 0;
        while j < 3 {
            temp += i64::from(numbers[i+j]);
            j += 1;
        }

        j = 1;
        while j < 4 {
            sum += i64::from(numbers[i+j]);
            j += 1;
        }

        if sum > temp {
            result += 1;
        }

        i += 1;
    }


    println!("The result is {}", result);
}
