const { getFileContentLines } = require("../utils");
const dataLines = getFileContentLines("./map.txt");
let pos = (() => {
  const a = dataLines.join("").indexOf("^") / dataLines[0].length;
  return [Math.floor(a), Math.round((a % 1) * dataLines[0].length)];
})();
const startPos = pos.slice();
const data = dataLines.map((line) => line.split(""));

const dirs = [
  [-1, 0],
  [0, 1],
  [1, 0],
  [0, -1],
];
let beenThere = {};
let xPosi = [[...startPos, 0]];
const runPath = (pos, currDir) => {
  const dir = dirs[currDir % 4];
  while (data[pos[0] + dir[0]]?.[pos[1] + dir[1]] != "#") {
    pos = [0, 1].map((i) => pos[i] + dir[i]);
    if (!(pos.every((p) => p >= 0) && pos[0] < data[0].length && pos[1] < data.length)) {
      return true;
    }
    xPosi.push([...pos, currDir]);
  }
  if (beenThere[[...pos, currDir % 4].toString()]) {
    return false;
  }
  beenThere[[...pos, currDir % 4].toString()] = true;
  return runPath(pos, currDir + 1);
};

runPath(pos, 0);
console.log(new Set(xPosi.map((x) => [x[0], x[1]].toString())).size);

const posis = new Set();
console.log(
  xPosi
    .map((posi) => posi.slice())
    .reduce((acc, curr) => {
      if (
        !(startPos[0] == curr[0] && startPos[1] == curr[1] && curr[2] == 0) &&
        !posis.has([curr[0], curr[1]].toString())
      ) {
        posis.add([curr[0], curr[1]].toString());
        data[curr[0]][curr[1]] = "#";

        beenThere = {};
        if (
          !runPath(
            [curr[0], curr[1]].map((val, k) => val - dirs[curr[2] % 4][k]),
            curr[2]
          )
        )
          acc.add([curr[0], curr[1]].toString());
      }
      data[curr[0]][curr[1]] = ".";
      return acc;
    }, new Set()).size
);
