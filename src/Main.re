exception Argument_required(string);
exception Invalid_string_int(string);
exception CLI_HELP;

let main = () => {
  let pass =
    (
      try (Node.Process.argv[2]) {
      | Invalid_argument(_) =>
        raise(Argument_required("Need a password as the first argument!"))
      }
    )
    |> (
      fun
      | "-h"
      | "--help" => raise(CLI_HELP)
      | pass => pass
    );

  let key =
    try (Node.Process.argv[3]) {
    | Invalid_argument(_) =>
      raise(Argument_required("Need a secret key as the seconed argument!"))
    };

  let len =
    try (int_of_string(Node.Process.argv[4])) {
    | Invalid_argument(_) => 16
    | _ => raise(Invalid_string_int("The length must be an integer!"))
    };

  if (len <= 0 || len > 32) {
    raise(Invalid_string_int("The length must be in range(1, 32)!"));
  };

  let finallyPass = Fp455.calculate(pass, key, len);
  Js.log(finallyPass);
};

let helpInfo = {|Welcome to fp455-cli

fp455-cli is a command line for generate flower password. fp455 means flower pa(4)s(5)s(5)word.

Usage:

    fp455 password key [length] -- generate the password
    fp455 -h, fp455 --help  -- get the help infomation

Suggestion:
alias fp455 as ` fp`, note the leading space, for not saving sensitive infomation to shell history.

    alias fp455=' fp'
|};

try (main()) {
| Argument_required(str) => Js.log(str)
| Invalid_string_int(str) => Js.log(str)
| CLI_HELP => Js.log(helpInfo)
| _ => Js.log("unexpected error happens.")
};
