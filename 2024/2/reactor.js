const { getFileContentLines } = require("../utils");
const data = getFileContentLines("./reports.txt");
const safeCount = data.reduce((acc, curr) => {
  const digits = curr.split(" ").map((n) => parseInt(n));
  for (let i = 0; i < digits.length; i++) {
    const nums = [...digits.slice(0, i), ...digits.slice(i + 1)];
    const rising = nums[1] - nums[0] > 0;
    if (
      nums.every((num, i, arr) => {
        const diff = arr[i + 1] - num;
        return (
          i === arr.length - 1 || (rising == diff > 0 && Math.abs(diff) <= 3 && Math.abs(diff) > 0)
        );
      })
    ) {
      return acc + 1;
    }
  }
  return acc;
}, 0);
console.log(safeCount);
