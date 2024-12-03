const { getFileContent } = require("../utils");
const data = getFileContent("./memory.txt");
console.log(
  [...data.matchAll(/mul\((\d+),(\d+)\)/g)].reduce(
    (acc, curr) => acc + parseInt(curr[1]) * parseInt(curr[2]),
    0
  )
);
console.log(
  [...data.matchAll(/(mul)\((\d+),(\d+)\)|do\(\)|don't\(\)/g)].reduce(
    (acc, curr) => ({
      count:
        acc.count + (curr[1] == "mul" && acc.canDo ? parseInt(curr[2]) * parseInt(curr[3]) : 0),
      canDo: curr[0] == "do()" ? true : curr[0] == "don't()" ? false : acc.canDo,
    }),
    { count: 0, canDo: true }
  ).count
);
