use rs::read;

fn main() {
    let data = read("./data/day04-input.txt");

    let result: Vec<_> = data.iter()
	.map(|card| {
	    let (wining_slots, player_slots) = card.split_once(" | ").unwrap();
	    let (_, second_part) = wining_slots.split_once(":").unwrap();

	    let wining_slots: Vec<_>= second_part
		.split(" ")
		.filter(|v| v != &"")
		.collect();
	    let player_slots: Vec<_> = player_slots
		.split(" ")
		.filter(|v| v != &"")
		.collect();

	    let mut points = 0;
	    for value in wining_slots {
		if player_slots.contains(&value) {
		    if let Some(_index) = player_slots.iter().position(|&value| value == value) {
			if points == 0 {
			    points += 1;
			} else {
			   points *= 2;
			}
		    }
		} 
	    }

	    points
	})
	.collect();

    let mut total_point: usize = 0;
    for value in result {
	total_point += value;
    }

    println!("Part1: {total_point}");
}
