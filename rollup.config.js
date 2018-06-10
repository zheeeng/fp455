import bucklescript from 'rollup-plugin-bucklescript'
import uglifyPlugin from 'rollup-plugin-uglify'
import resolve from 'rollup-plugin-node-resolve'
import commonjs from 'rollup-plugin-commonjs'

const uglify = uglifyPlugin.uglify

const buildBin = process.env.NODE_ENV === 'bin'

const coreBuildConfig = {
  input: 'src/Fp455.re',
  output: {
    file: 'dist/core.js',
    format: 'umd',
    name: 'fp455',
    globals: {
      fp455: 'fp455',
    },
  },
  external: ['blueimp-md5'],
  plugins: [
    bucklescript(),
  ],
}

const miniCoreBuildConfig = {
  input: 'src/Fp455.re',
  output: {
    file: 'dist/fp455.min.js',
    format: 'umd',
    name: 'fp455',
    globals: {
      fp455: 'fp455',
    },
  },
  plugins: [
    bucklescript(),
    resolve(),
    commonjs(),
    uglify(),
  ],
}

const binBuildConfig = {
  input: 'src/Main.re',
  output: {
    file: 'dist/bin.js',
    format: 'cjs',
    banner: '#!/usr/bin/env node',
  },
  external: ['process', 'blueimp-md5'],
  plugins: [
    bucklescript({
      'package-specs': 'commonjs',
    })
  ],
}

export default buildBin
  ? binBuildConfig
  : [ coreBuildConfig, miniCoreBuildConfig ]
