const { getFileContent } = require("../utils");
const data = getFileContent("./rules.txt").split("\n\n");
const rules = data[0].split("\n").reduce((acc, curr) => {
  const nums = curr.split("|");
  acc[nums[0]] = [...(acc[nums[0]] ?? []), nums[1]];
  return acc;
}, {});
const updates = data[1].split("\n").map((line) => line.split(","));
const isCorrect = (nums) =>
  JSON.stringify(nums) ==
  JSON.stringify(nums.sort((a, b) => (rules[a]?.includes(b) ? -1 : rules[b]?.includes(a) ? 1 : 0)));
console.log(
  updates.reduce(
    (acc, curr) => {
      const res = isCorrect(curr) ? 0 : 1;
      acc[res] = acc[res] += parseInt(curr[Math.floor(curr.length / 2)]);
      return acc;
    },
    [0, 0]
  )
);
