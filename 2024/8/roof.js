const { getFileContentLines } = require("../utils");
const data = getFileContentLines("./antennas.txt").map((line) => line.split(""));
const antennas = data.reduce((acc, curr, i) =>curr.reduce((_acc, _curr, j) => {
      if (_curr != ".") acc[_curr] = [...(acc[_curr] ?? []), [i, j]];
      return acc;}, acc),{});

const antinodes = [];
const checkBounds = (x, y) =>
  x >= 0 && x < data.length && y >= 0 && y < data[0].length && antinodes.push([x, y]);
Object.values(antennas).forEach((type) =>
  type.forEach((pos) => type.forEach((_pos) => {
    if (pos.toString() != _pos.toString()) {
      let c = 0;
      while (checkBounds(...[0, 1].map((k) => pos[k] + (pos[k] - _pos[k]) * c))) { c++;}
    }})));
console.log(new Set(antinodes.map((a) => a.toString())).size);
