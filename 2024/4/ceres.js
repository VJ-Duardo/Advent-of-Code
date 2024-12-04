const { getFileContentLines } = require("../utils");
let data = getFileContentLines("./words.txt").map((line) => line.split(""));

console.log(
  data.reduce(
    (acc, curr, i) =>
      acc +
      curr.reduce((_acc, _curr, j) => {
        let count = 0;
        for (let k = -1; k <= 1; k++) {
          for (let l = -1; l <= 1; l++) {
            let word = "";
            for (let m = 0; m < 4; m++) {
              word += data[i + m * k]?.[j + m * l];
            }
            if (word == "XMAS") count++;
          }
        }
        return _acc + count;
      }, 0),
    0
  )
);

console.log(
  data.reduce(
    (acc, curr, i) =>
      acc +
      curr.reduce(
        (_acc, _curr, j) =>
          _curr == "A" &&
          [1, -1]
            .map((k) => data[i - 1]?.[j + k] + data[i + 1]?.[j - k])
            .every((sub) => /MS|SM/.test(sub))
            ? _acc + 1
            : _acc,
        0
      ),
    0
  )
);
