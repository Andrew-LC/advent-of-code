use rs::read;

fn part1(data: Vec<String>) -> u32 {
    let result: u32 = data
	.iter()
	.map(|s| s.chars().filter(|c| c.is_digit(10)).collect::<String>())
	.filter(|s| !s.is_empty()) // Filter out empty strings
	.map(|s| {
	    let first_digit = s.chars().next().unwrap();
	    let last_digit = s.chars().last().unwrap_or(first_digit);
	    format!("{}{}", first_digit, last_digit).parse::<u32>().unwrap()
	})
	.sum();

    result
}


fn main() {
    let data: Vec<String> = read("./data/day01-input.txt");
    println!("Part 1: {:?}", part1(data));
}
