export function part2(data){
    let result = data.map((card, index) => {
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
		points += 1;
	    }
	}

	let cardsWon = [];
	let inc = 1;
	for(let i = 0; i <= points; i++){
	    cardsWon.push(index+inc);
	    inc++;
	}

	return cardsWon;
    });

    console.log(result);

    // let totalPoints = 0;
    // for (let value of result) totalPoints += value;

    // console.log(`Part1: ${totalPoints}`);
}
