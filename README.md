# fp455
Flower Password based on ReasonML

[![Known Vulnerabilities](https://snyk.io/test/github/zheeeng/fp455/badge.svg)](https://snyk.io/test/github/zheeeng/fp455)
[![language](https://img.shields.io/badge/%3C/%3E-ReasonML-blue.svg)](https://reasonml.github.io//)
[![license](https://img.shields.io/github/license/mashape/apistatus.svg)]()
[![Build Status](https://travis-ci.org/zheeeng/fp455.svg?branch=master)](https://travis-ci.org/zheeeng/fp455)
[![npm version](https://img.shields.io/npm/v/fp455.svg)](https://www.npmjs.com/package/fp455)
[![npm bundle size (minified + gzip)](https://img.shields.io/bundlephobia/minzip/fp455.svg)](https://unpkg.com/fp455/dist/fp455.min.js)

[More about this tool on official website](http://flowerpassword.com/)

---

## The Command Line

<details>
fp455-cli is a command line for generate flower password. fp455 means flower pa(4)s(5)s(5)word.
</details>

### Installation

```sh
yarn global add fp455
npm install -g fp455
```

**suggestion**:
alias fp455 for not saving encrypt commands

```
# preserve the leading space
alias fp=' fp455'
```

### Usage

```sh
fp455 password key [length] -- generate the password
fp455 -h, fp455 --help  -- get the help infomation
```

**note**: length is in range [1, 32]

### Example

```sh
$ fp455 abc123456 fp455
> e2fbb727dA3638b6

$ fp455 abc123456 fp455 32
> e2fbb727dA3638b638C4b9f9Bee181ad

$ fp no-history-pass fp455
> Kc8E6a281F02Cd28
```

---

## As Dependency

### Installation

```sh
yarn add fp455
npm install -s fp455
```

## Usage

In Module system:


```javascript
import fp455 from 'fp455'

// (string, string, int) -> string
fp455.calculate('abc123456 ', 'fp455', 16)
```

In browser:

```javascript
<script src="path/to/yourCopyOf/fp455.min.js"></script>
<script>
    const pass = fp455.calculate('abc123456 ', 'fp455', 16)
</script>
```

**CDN**: `
https://unpkg.com/fp455/dist/fp455.min.js
`

## License
MIT
