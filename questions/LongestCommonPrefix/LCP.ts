function longestCommonPrefix(strs: string[]): string {
  strs.length == 0 ? "" : null;

  let ans = strs[0];
  strs.forEach((e, i) => {
    while (e.search(ans) != 0) {
      ans = ans.substring(0, ans.length - 1);
      ans == "" ? "" : null;
    }
  });

  return ans;
}

console.log(longestCommonPrefix(["flower", "flow", "flight"]));
