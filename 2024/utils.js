const fs = require("fs");

const getFileContent = (path) => {
  const data = fs.readFileSync(path, { encoding: "utf8", flag: "r" });
  return data;
};

const getFileContentLines = (path) => {
  return getFileContent(path).split(/\r?\n/);
};

module.exports = {
  getFileContent,
  getFileContentLines,
};
