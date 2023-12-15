export function part1(data){
    let result = data.map(card => {
	let [winingSlots, playerSlots] = card.split(" | ");

	winingSlots = winingSlots.
	    split(":")[1].
	    split(" ").
	    map(v => v.trim()).
	    filter(v => v != "").
	    map(v => parseInt(v));

	playerSlots = playerSlots.
	    split(" ").
	    map(v => v.trim()).
	    filter(v => v != "").
	    map(v => parseInt(v));

	let points = 0;
	for(let number of winingSlots) {
	    if(playerSlots.includes(number)) {
		if(points == 0){
		    points += 1;
		} else  {
		    points *= 2;
		}
	    }
	}

	return points;
    })

    let totalPoints = 0;
    for (let value of result) totalPoints += value;

    console.log(`Part1: ${totalPoints}`);
}
