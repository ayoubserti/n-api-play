# About

set of example using `node_api` API.

# Try it

```
$ git clone https://github.com/ayoubserti/n-api-play.git .
$ npm install
$ node --napi-modules tests/test1.js

```

# Understand NAPI module

nodejs v8.x comes with a new power feature. The `node_api` way allows native developer to create NodeJS addon and distribute the same binary for any nodejs version beginning from `v8.0.0` or at least when the feature become stable and LTS.

As the moment of writing this document, `napi` feature still  experimental and the API may change in the way. But, I found it's a promoting technique to write up node add-on  because it save you from distributing pre-built package for every new NodeJS version.

The benefit I found in `napi` that's wrap V8 datatypes and API and keep you away from V8 changes and API deprecation. Therefore, your code keep compiling forward.
