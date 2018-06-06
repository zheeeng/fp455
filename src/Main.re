exception Argument_required(string);
exception Invalid_string_int(string);

let main = () => {
  let pass =
    try (Node.Process.argv[2]) {
    | Invalid_argument(_) =>
      raise(Argument_required("Need a password as the first argument!"))
    };

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

try (main()) {
| Argument_required(str) => Js.log(str)
| Invalid_string_int(str) => Js.log(str)
| _ => Js.log("unexpected error happens.")
};
