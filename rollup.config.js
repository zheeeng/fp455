import bucklescript from 'rollup-plugin-bucklescript'

const buildBin = process.env.NODE_ENV === 'bin'

const coreBuildConfig = {
  input: 'src/Fp455.re',
  output: {
    file: 'dist/core.js',
    format: 'cjs',
  },
  plugins: [bucklescript({
  })],
}

const binBuildConfig = {
  input: 'src/Main.re',
  output: {
    file: 'dist/bin.js',
    format: 'cjs',
  },
  external: ['process'],
  plugins: [bucklescript({
    'package-specs': 'commonjs',
  })],
  banner: '#!/usr/bin/env node',
}

export default buildBin ? binBuildConfig : coreBuildConfig
