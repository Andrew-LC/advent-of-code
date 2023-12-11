export function part2(data) {
  const result = data.map(line => {
    const secondPart = line.split(':')[1].trim();
    let games = secondPart
      .split(";")
      .map(v => {
        return v.trim()
          .split(",")
          .map(v => v.split(" ").filter(v => v !== ''))
          .map(v => {
            let [count, color] = v;
            return { color, count: parseInt(count) };
          })
      })
      .flatMap(value => value)
      .reduce((acc, obj) => {
        const existingObj = acc.find(item => item.color === obj.color);

        if (!existingObj || obj.count > existingObj.count) {
          if (existingObj) {
            acc.splice(acc.indexOf(existingObj), 1, obj);
          } else {
            acc.push(obj);
          }
        }

        return acc;
      }, [])
      .reduce((acc, obj) => {
	  return acc * obj.count  
      }, 1);

    return games;
  })
  .reduce((acc, value) => {
      return acc + value
  }, 0);

    console.log(`Part2: ${result}`);
}
