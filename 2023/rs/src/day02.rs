pub(crate) use rs::read;

fn main() {
    let data: Vec<String> = read("./data/day02-input.txt");

    let result: usize = data
        .iter()
        .map(|line| {
            let (_, second_part) = line.split_once(':').unwrap();
            let games: Vec<bool> = second_part
                .split(';')
                .map(|game| {
                    game.split(',')
                        .map(|v| v.trim())
                        .any(|iteration| {
                            let (count, color) = iteration.split_once(" ").unwrap();
                            let count: u32 = count.parse().unwrap();

                            match color {
                                "blue" => count > 14,
                                "red" => count > 12,
                                "green" => count > 13,
                                _ => false,
                            }
                        })
                })
                .collect();

            games.iter().any(|&value| value)
        })
        .enumerate()
        .fold(0, |acc, (index, value)| {
            let index = index + 1;
            acc + if value { index } else { 0 }
        });

    println!("{}", result+1);
}
