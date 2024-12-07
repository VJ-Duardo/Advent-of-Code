const { getFileContentLines } = require("../utils");
const data = getFileContentLines("./equations.txt").map((line) =>
  line.split(": ").map((part, i) => (i == 1 ? part.split(" ").map((n) => parseInt(n)) : parseInt(part)))
);

console.log(
  data.reduce((acc, curr) => {
    const tryEq = (val = 0, op = "+", i = 0) => {
      val = op == "||" ? parseInt("" + val + curr[1][i]) : eval(`${val}${op}${[curr[1][i]]}`);
      if (i == curr[1].length - 1) return val == curr[0];
      return !["+", "*", "||"].every((nOp) => !tryEq(val, nOp, i + 1));
    };
    return acc + (tryEq() ? curr[0] : 0);
  }, 0)
);
