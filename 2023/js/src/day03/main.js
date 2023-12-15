import fs from "fs";
import path from "path";
import { part1 } from "./part1.js"
import { part2 } from "./part2.js"

function read(url) {
    const fullPath = path.resolve(url); 
    const data = fs.readFileSync(fullPath, "utf8")
	  .toString()
	  .trim()
	  .split('\n');

    return data
}

const data = read("./data/test.txt");
//part1(data);
part2(data);
