export function part1(data){
    const Count = {
	"red": 12,
	"blue": 14,
	"green": 13,
    }

    const result = data.map((line, index) => {
	const secondPart = line.split(':')[1].trim();
	const games = secondPart
	      .split(';')
	      .map(game => {
		  const gamesIteration = game
			.split(',')
			.map(v => v.trim());

		  return gamesIteration.map(v => {
		      let [count, color] = v.split(' ');

		      if(count > Count[color]){
			  return false;
		      }
		      return true;
		  }).every(value => value == true)
	      }).every(value => value == true);

	return games
    }).reduce((acc, curr, index) => {
	if(curr == true){
	    return acc + (index+1);
	} else {
	    return acc
	}
    }, 0);

    console.log(`Part1: ${result}`);
}
