use std::fs;

pub fn read(path: &str) -> Vec<String> {
    let data: Vec<String> = fs::read_to_string(path)
        .expect("Unable to read file")
        .lines()
        .map(String::from)
        .collect();

    data
}
