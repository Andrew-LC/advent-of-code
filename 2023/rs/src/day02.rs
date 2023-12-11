use rs::read;

#[allow(dead_code)]
#[derive(Debug)]
struct Dice {
    color: String,
    count: u32,
}

fn main() {
    let data: Vec<String> = read("./data/test.txt");

    let _result: Vec<_> = data
        .iter()
        .flat_map(|line| {
            let (_, second_part) = line.split_once(':').unwrap();
            let second_part = second_part.trim_start();
            second_part.split(';').flat_map(|game| {
                game.split(',').map(|v| v.trim()).map(|iteration| {
                    let (count, color) = iteration.split_once(" ").unwrap();
		    Dice {color.to_string(), count.parse().unwrap()}
                })
            })
        })
        .collect();
}
