exception Exit_process(string);

let helpInfo = {|Welcome to fp455-cli

fp455-cli is a command line for generate flower password. fp455 means flower pa(4)s(5)s(5)word.

Usage:

    fp455 password key [length] -- generate the password
    fp455 -h, fp455 --help  -- get the help infomation

Suggestion:
alias fp455 as ` fp`, note the leading space, for not saving sensitive infomation to shell history.

    alias fp455=' fp'
|};

let main = () =>
  switch (Array.to_list(Node.Process.argv)) {
  | [_, _, "-h" | "--help", ..._] => Js.log(helpInfo)
  | [_, _, pass, key, ...rest] =>
    (
      switch (int_of_string(List.hd(rest))) {
      | len when len > 0 && len <= 32 => len
      | _ => raise(Exit_process("The length must be in range(0, 32]!"))
      | exception (Failure("hd")) => 16
      | exception (Failure("int_of_string")) =>
        raise(
          Exit_process(
            "Invalid length argument, try \"fp455 -h\" get the help information",
          ),
        )
      }
    )
    |> (len => Fp455.calculate(pass, key, len) |> Js.log)
  | _ =>
    Js.log("Not engough arguments, try \"fp455 -h\" get the help information")
  };

try (main()) {
| Exit_process(str) =>
  Js.log(str);
  Node.Process.exit(1);
| _ => Js.log("unexpected error happens.")
};
