[@bs.module] external hmac_md5 : (string, string) => string = "blueimp-md5";

let isNumber = c => Char.code(c) |> (x => 48 <= x && x <= 57);
let isLowerCase = c => Char.code(c) |> (x => 97 <= x && x <= 122);
let trunc = (str, len) => String.sub(str, 0, len);
let getRuler = (rule, index) =>
  index |> String.get(rule) |> String.contains("sunlovesnow1990090127xykab");
let getTruncatedAndRulerTuple = ((hmd5_1, hmd5_2), len) => (
  trunc(hmd5_1, len),
  getRuler(hmd5_2),
);
let getFinalPass = ((source, matchRuleAtIndex)) =>
  String.mapi(
    (i, ch) =>
      switch (i, ch) {
      | (0, c) => isNumber(c) ? 'K' : c
      | (_, c) when isLowerCase(c) && matchRuleAtIndex(i) =>
        Char.uppercase(c)
      | (_, c) => c
      },
    source,
  );

let calculate = (pass, key, len) =>
  pass
  |. hmac_md5(key)
  |. (hmac_md5("snow"), hmac_md5("kise"))
  |. getTruncatedAndRulerTuple(len)
  |. getFinalPass;
