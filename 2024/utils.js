const fs = require("fs");

const getFileContent = (path) => {
  const data = fs.readFileSync(path, { encoding: "utf8", flag: "r" });
  return data.replaceAll("\r\n", "\n");
};

const getFileContentLines = (path) => {
  return getFileContent(path).split(/\n/);
};

module.exports = {
  getFileContent,
  getFileContentLines,
};
