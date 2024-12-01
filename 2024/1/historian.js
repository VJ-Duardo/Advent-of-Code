const { getFileContentLines } = require("../utils");
const data = getFileContentLines("./locations.txt").map((line) => line.split(/\s+/));
const columns = [0, 1].map((i) =>
  data
    .map((lineArr) => lineArr[i])
    .map((num) => parseInt(num))
    .sort()
);
const result = columns[0].reduce((acc, curr, i) => acc + Math.abs(curr - columns[1][i]), 0);
console.log(result);
const occurrences = columns[1].reduce((acc, curr) => {
  acc[curr] = (acc[curr] ?? 0) + 1;
  return acc;
}, {});
const similarity = [...new Set(columns[0])].reduce(
  (acc, curr) => acc + curr * (occurrences[curr] ?? 0),
  0
);
console.log(similarity);
